// This informs the engine we want to stop running, and jumps to the end of the game loop if we have no errors to report.
internal void
PROCESS_exit(WrenVM* vm) {
  ENGINE* engine = (ENGINE*)wrenGetUserData(vm);
  ASSERT_SLOT_TYPE(vm, 1, NUM, "code");
  engine->running = false;
  engine->exit_status = floor(wrenGetSlotDouble(vm, 1));
  wrenSetSlotNull(vm, 0);
}

internal void
PROCESS_args(WrenVM* vm) {
  ENGINE* engine = (ENGINE*)wrenGetUserData(vm);
  
  // Code extracted from wren-cli project
  // https://github.com/wren-lang/wren-cli/blob/main/src/module/os.c#L62
  wrenEnsureSlots(vm, 2);
  wrenSetSlotNewList(vm, 0);

  for (int i = 0; i < engine->argc; i++)
  {
    wrenSetSlotString(vm, 1, engine->argv[i]);
    wrenInsertInList(vm, 0, -1, 1);
  }
}


internal void
WINDOW_resize(WrenVM* vm) {
  ENGINE* engine = (ENGINE*)wrenGetUserData(vm);
  ASSERT_SLOT_TYPE(vm, 1, NUM, "width");
  ASSERT_SLOT_TYPE(vm, 2, NUM, "height");
  uint32_t width = wrenGetSlotDouble(vm, 1);
  uint32_t height = wrenGetSlotDouble(vm, 2);
  SDL_SetWindowSize(engine->window, width, height);
}

internal void
WINDOW_getWidth(WrenVM* vm) {
  ENGINE* engine = (ENGINE*)wrenGetUserData(vm);
  int width = 0;
  SDL_GetWindowSize(engine->window, &width, NULL);
  wrenSetSlotDouble(vm, 0, width);
}

internal void
WINDOW_getHeight(WrenVM* vm) {
  ENGINE* engine = (ENGINE*)wrenGetUserData(vm);
  int height = 0;
  SDL_GetWindowSize(engine->window, NULL, &height);
  wrenSetSlotDouble(vm, 0, height);
}

internal void
WINDOW_setTitle(WrenVM* vm) {
  ENGINE* engine = (ENGINE*)wrenGetUserData(vm);
  ASSERT_SLOT_TYPE(vm, 1, STRING, "title");
  char* title = wrenGetSlotString(vm, 1);
  SDL_SetWindowTitle(engine->window, title);
}

internal void
WINDOW_getTitle(WrenVM* vm) {
  ENGINE* engine = (ENGINE*)wrenGetUserData(vm);
  wrenSetSlotString(vm, 0, SDL_GetWindowTitle(engine->window));
}

internal void
WINDOW_setVsync(WrenVM* vm) {
  ENGINE* engine = (ENGINE*)wrenGetUserData(vm);
  ASSERT_SLOT_TYPE(vm, 1, BOOL, "vsync");
  bool value = wrenGetSlotBool(vm, 1);
  ENGINE_setupRenderer(engine, value);
}

internal void
WINDOW_setLockStep(WrenVM* vm) {
  ENGINE* engine = (ENGINE*)wrenGetUserData(vm);
  engine->lockstep = wrenGetSlotBool(vm, 1);
}

internal void
WINDOW_setFullscreen(WrenVM* vm) {
  ENGINE* engine = (ENGINE*)wrenGetUserData(vm);
  ASSERT_SLOT_TYPE(vm, 1, BOOL, "fullscreen");
  bool value = wrenGetSlotBool(vm, 1);
  SDL_SetWindowFullscreen(engine->window, value ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
}

internal void
WINDOW_getFullscreen(WrenVM* vm) {
  ENGINE* engine = (ENGINE*)wrenGetUserData(vm);
  uint32_t flags = SDL_GetWindowFlags(engine->window);
  wrenSetSlotBool(vm, 0, (flags & SDL_WINDOW_FULLSCREEN_DESKTOP) != 0);
}


internal void
VERSION_getString(WrenVM* vm) {
  size_t len = 0;
  char* version = DOME_VERSION;
  if (version[len] == 'v') {
    version++;
  }
  for (len = 0; len < strlen(version); len++) {
    if (version[len] != '.' && !isdigit(version[len])) {
      break;
    }
  }
  printf("len: %i \n", len);
  wrenSetSlotBytes(vm, 0, version, len);
}
