internal void FILESYSTEM_loadEventHandler(void* task);

global_variable char* basePath = NULL;

internal void
BASEPATH_set(char* path) {
  size_t len = strlen(path) + 1;
  bool slash = path[len - 1] == '/';
  if (!slash) {
    len++;
  }
  basePath = realloc(basePath, len * sizeof(char));
  strcpy(basePath, path);
  if (!slash) {
    basePath[len - 2] = '/';
  }
  basePath[len - 1] = '\0';
}

internal char*
BASEPATH_get(void) {
  if (basePath == NULL) {
    if (STRINGS_EQUAL(SDL_GetPlatform(), "Mac OS X")) {
      basePath = SDL_GetBasePath();
      if (strstr(basePath, ".app/") != NULL) {
        // If this is a MAC bundle, we need to use the exe location
        return basePath;
      } else {
        // Free the SDL path and fall back
        free(basePath);
      }
    }
    long path_max;
    size_t size;
    char *buf = NULL;
    char *ptr = NULL;
#ifdef __MINGW32__
    path_max = PATH_MAX;
#else
    path_max = pathconf(".", _PC_PATH_MAX);
#endif
    if (path_max == -1) {
      size = 1024;
    } else if (path_max > 10240) {
      size = 10240;
    } else {
      size = path_max;
    }

    for (buf = ptr = NULL; ptr == NULL; size *= 2) {
      if ((buf = realloc(buf, size + sizeof(char) * 2)) == NULL) {
        abort();
      }

      ptr = getcwd(buf, size);
      if (ptr == NULL && errno != ERANGE) {
        abort();
      }
    }
    basePath = ptr;
    size_t len = strlen(basePath);
    *(basePath + len) = '/';
    *(basePath + len + 1) = '\0';
    for (size_t i = 0; i < len + 2; i++) {
      if (basePath[i] == '\\') {
        basePath[i] = '/';
      }
    }
  }
  return basePath;
}

internal void
BASEPATH_free(void) {
  if (basePath != NULL) {
    free(basePath);
  }
}

internal inline bool
isDirectory(const char *path) {
   struct stat statbuf;
   if (stat(path, &statbuf) != 0) {
       return false;
   }
   return S_ISDIR(statbuf.st_mode) == 1;
}

internal inline bool
doesFileExist(char* path) {
  return access(path, F_OK) != -1;
}

internal int
readFileFromTar(mtar_t* tar, char* path, size_t* lengthPtr, char** data) {
  // We assume the tar open has been done already
  int err;
  mtar_header_t h;

  char compatiblePath[PATH_MAX];

  strcpy(compatiblePath, "./");
  strcat(compatiblePath, path);

  err = mtar_rewind(tar);
  if (err != MTAR_ESUCCESS) {
    return err;
  }

  while ((err = mtar_read_header(tar, &h)) == MTAR_ESUCCESS) {
    // search for "<path>", "./<path>" and "/<path>"
    // see https://github.com/avivbeeri/nest/pull/2
    if (!strcmp(h.name, path) ||
        !strcmp(h.name, compatiblePath) ||
        !strcmp(h.name, compatiblePath + 1)) {
      break;
    }
    err = mtar_next(tar);

    if (err != MTAR_ESUCCESS) {
      return err;
    }
  }

  if (err != MTAR_ESUCCESS) {
    return err;
  }

  size_t length = h.size;
  *data = calloc(1, length + 1);
  if ((err = mtar_read_data(tar, *data, length)) != MTAR_ESUCCESS) {
    // Some kind of problem reading the file
    free(*data);
    return err;
  }

  if (lengthPtr != NULL) {
    *lengthPtr = length;
  }

  return err;
}

internal int
writeEntireFile(const char* path, const char* data, size_t length) {
  FILE* file = fopen(path, "wb+");
  if (file == NULL) {
    return errno;
  }
  fwrite(data, sizeof(char), length, file);
  fclose(file);
  return 0;
}

internal char*
readEntireFile(char* path, size_t* lengthPtr) {
  FILE* file = fopen(path, "rb");
  if (file == NULL) {
    return NULL;
  }
  char* source = NULL;
  if (fseek(file, 0L, SEEK_END) == 0) {
    /* Get the size of the file. */
    long bufsize = ftell(file);
    /* Allocate our buffer to that size. */
    source = malloc(sizeof(char) * (bufsize + 1));

    /* Go back to the start of the file. */
    if (fseek(file, 0L, SEEK_SET) != 0) { /* Error */ }

    /* Read the entire file into memory. */
    size_t newLen = fread(source, sizeof(char), bufsize, file);
    if (ferror(file) != 0) {
      perror("Error reading file");
    } else {
      if (lengthPtr != NULL) {
        *lengthPtr = newLen;
      }
      source[newLen++] = '\0'; /* Just to be safe. */
    }
  }
  fclose(file);
  return source;
}


