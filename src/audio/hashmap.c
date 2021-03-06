// Hash table based on the implementation in "Crafting Interpreters"
// as well as the Wren VM.

#define TABLE_MAX_LOAD 0.75
#define NIL_KEY 0

#define IS_TOMBSTONE(entry) ((entry)->value.state == CHANNEL_LAST)
#define IS_EMPTY(entry) ((entry)->value.state == CHANNEL_INVALID)

// Thomas Wang, Integer Hash Functions.
// http://www.concentric.net/~Ttwang/tech/inthash.htm
internal inline  uint32_t
hashBits(uint64_t hash)
{
  // Wren VM cites v8's computeLongHash() function which in turn cites:
  // Thomas Wang, Integer Hash Functions.
  // http://www.concentric.net/~Ttwang/tech/inthash.htm
  hash = ~hash + (hash << 18);  // hash = (hash << 18) - hash - 1;
  hash = hash ^ (hash >> 31);
  hash = hash * 21;  // hash = (hash + (hash << 2)) + (hash << 4);
  hash = hash ^ (hash >> 11);
  hash = hash + (hash << 6);
  hash = hash ^ (hash >> 22);
  return (uint32_t)(hash & 0x3fffffff);
}

global_variable const CHANNEL TOMBSTONE  = {
  .state = CHANNEL_LAST,
  .ref = {
    .id = NIL_KEY
  }
};
global_variable const CHANNEL EMPTY_CHANNEL  = {
  .state = CHANNEL_INVALID,
  .ref = {
    .id = NIL_KEY
  }
};

typedef struct {
  uint32_t next;
  uint32_t found;
  bool done;
  CHANNEL* value;
} TABLE_ITERATOR;

void TABLE_iterInit(TABLE_ITERATOR* iter) {
  iter->next = 0;
  iter->found = 0;
  iter->done = false;
  iter->value = NULL;
}

typedef struct {
  CHANNEL_ID key;
  CHANNEL value;
} ENTRY;

typedef struct {
  uint32_t items;
  uint32_t count;
  uint32_t capacity;
  ENTRY* entries;
} TABLE;

void TABLE_init(TABLE* table) {
  table->count = 0;
  table->items = 0;
  table->capacity = 0;
  table->entries = NULL;
}

void TABLE_free(TABLE* table) {
  if (table->entries != NULL) {
    free(table->entries);
  }
  TABLE_init(table);
}

internal bool
TABLE_iterate(TABLE* table, TABLE_ITERATOR* iter) {
  CHANNEL* value = NULL;
  if (iter->found >= table->items) {
    iter->done = true;
  }
  if (!iter->done) {
    for (uint32_t i = iter->next; i < table->capacity; i++) {
      ENTRY* entry = &table->entries[i];
      if (entry->key == NIL_KEY) {
        continue;
      }
      iter->next = i + 1;
      iter->found++;
      value = &entry->value;
      break;
    }
    iter->value = value;
  }
  return !iter->done;
}

internal bool
TABLE_findEntry(ENTRY* entries, uint32_t capacity, CHANNEL_ID key, ENTRY** result) {
  if (capacity == 0) {
    return false;
  }

  uint32_t startIndex = hashBits(key) % capacity;
  uint32_t index = startIndex;
  ENTRY* tombstone = NULL;
  do {
    ENTRY* entry = &(entries[index]);
    if (entry->key == NIL_KEY) {
      if (IS_EMPTY(entry)) {
        *result = tombstone != NULL ? tombstone : entry;
        return false;
      } else {
        if (tombstone == NULL) {
          tombstone = entry;
        }
      }
    } else if (entry->key == key) {
      *result = entry;
      return true;
    }

    index = (index + 1) % capacity;
  } while (index != startIndex);
  *result = tombstone;
  return false;
}

internal void
TABLE_resize(TABLE* table, uint32_t capacity) {
  ENTRY* entries = malloc(sizeof(ENTRY) * capacity);
  for (uint32_t i = 0; i < capacity; i++) {
    entries[i].key = NIL_KEY;
    entries[i].value = EMPTY_CHANNEL;
  }
  table->count = 0;
  for (uint32_t i = 0; i < table->capacity; i++) {
    ENTRY* entry = &table->entries[i];
    if (entry->key == NIL_KEY) {
      continue;
    }
    ENTRY* dest = NULL;
    bool found = TABLE_findEntry(entries, capacity, entry->key, &dest);
    if (!found) {
      assert(dest != NULL);
      dest->key = entry->key;
      dest->value = entry->value;
      table->count++;
    }
  }
  free(table->entries);

  table->capacity = capacity;
  table->entries = entries;
}

internal CHANNEL*
TABLE_set(TABLE* table, CHANNEL_ID key, CHANNEL channel) {
  if ((table->items + 1) > table->capacity * TABLE_MAX_LOAD) {
    uint32_t capacity = table->capacity < 4 ? 4 : table->capacity * 2;
    TABLE_resize(table, capacity);
  }
  ENTRY* entry = NULL;
  bool found = TABLE_findEntry(table->entries, table->capacity, key, &entry);
  if (found) {
    entry->value = channel;
  } else {
    if (!IS_TOMBSTONE(entry)) {
      table->count++;
    }
    table->items++;
    entry->key = key;
    entry->value = channel;
  }

  return &(entry->value);
}

internal bool
TABLE_get(TABLE* table, CHANNEL_ID key, CHANNEL** channel) {
  if (table->count == 0) {
    *channel = NULL;
    return false;
  }
  ENTRY* entry;
  bool found = TABLE_findEntry(table->entries, table->capacity, key, &entry);
  if (found) {
    *channel = &entry->value;
    return true;
  }
  return false;
}

internal bool
TABLE_delete(TABLE* table, CHANNEL_ID key) {
  if (table->count == 0) {
    return false;
  }
  ENTRY* entry;
  bool found = TABLE_findEntry(table->entries, table->capacity, key, &entry);
  if (found) {
    table->items--;
    entry->key = NIL_KEY;
    entry->value = TOMBSTONE;
    return true;
  }
  return false;
}

internal void
TABLE_addAll(TABLE* dest, TABLE* src) {
  for (uint32_t i = 0; i < src->capacity; i++) {
    ENTRY* entry = &src->entries[i];
    if (entry->key != NIL_KEY) {
      TABLE_set(dest, entry->key, entry->value);
    }
  }
}
