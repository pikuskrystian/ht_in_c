#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#endif // HASH_TABLE_H

typedef struct {
    char* key;
    char* value;
} ht_item;

typedef struct {
    int size;
    int count;
    ht_item** items;
} ht_hash_table;

// Function declarations
ht_hash_table* ht_new();
void ht_del_hash_table(ht_hash_table* ht);
void ht_del_item(ht_item* item); // Ensure this is declared somewhere
