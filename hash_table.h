#ifndef HASH_TABLE_H
#define HASH_TABLE_H

// Constants
#define HT_INITIAL_BASE_SIZE 50

typedef struct {
    char* key;
    char* value;
} ht_item;

typedef struct {
    int base_size;  // Added base_size field
    int size;
    int count;
    ht_item** items;
} ht_hash_table;

// Deleted item marker
static ht_item HT_DELETED_ITEM = {NULL, NULL};

// Function declarations
ht_hash_table* ht_new();
void ht_del_hash_table(ht_hash_table* ht);
void ht_del_item(ht_item* item);
void ht_insert(ht_hash_table* ht, const char* key, const char* value);
char* ht_search(ht_hash_table* ht, const char* key);
void ht_delete(ht_hash_table* ht, const char* key);

#endif // HASH_TABLE_H 