#include <stdio.h>
#include "hash_table.h"

void print_table_status(ht_hash_table* ht) {
    printf("\nHash Table Status:\n");
    printf("Current size: %d\n", ht->size);
    printf("Items count: %d\n", ht->count);
    printf("Load factor: %.2f%%\n", (float)ht->count * 100 / ht->size);
}

int main() {
    // Create a new hash table
    printf("Creating a new hash table...\n");
    ht_hash_table* ht = ht_new();
    print_table_status(ht);

    // Insert some key-value pairs
    printf("\nInserting key-value pairs...\n");
    ht_insert(ht, "name", "John Doe");
    ht_insert(ht, "age", "30");
    ht_insert(ht, "city", "New York");
    ht_insert(ht, "job", "Developer");
    print_table_status(ht);

    // Search for values
    printf("\nSearching for values:\n");
    char* name = ht_search(ht, "name");
    char* age = ht_search(ht, "age");
    char* city = ht_search(ht, "city");
    printf("Found: name=%s, age=%s, city=%s\n", 
           name ? name : "not found",
           age ? age : "not found",
           city ? city : "not found");

    // Delete an item
    printf("\nDeleting 'age' from the hash table...\n");
    ht_delete(ht, "age");
    print_table_status(ht);

    // Try to search for deleted item
    age = ht_search(ht, "age");
    printf("Searching for 'age' after deletion: %s\n", 
           age ? age : "not found");

    // Demonstrate dynamic resizing by inserting many items
    printf("\nDemonstrating dynamic resizing by inserting more items...\n");
    char key[10];
    char value[10];
    for(int i = 0; i < 40; i++) {
        sprintf(key, "key%d", i);
        sprintf(value, "val%d", i);
        ht_insert(ht, key, value);
    }
    print_table_status(ht);

    // Clean up
    printf("\nCleaning up...\n");
    ht_del_hash_table(ht);
    printf("Hash table deleted successfully!\n");

    return 0;
}
