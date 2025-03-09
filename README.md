# Hash Table Implementation in C

A robust and efficient hash table implementation in C, featuring dynamic resizing, collision handling using double hashing, and memory-efficient storage.

## Features

- Dynamic hash table with automatic resizing
  - Grows when load factor exceeds 70%
  - Shrinks when load factor falls below 10%
  - Uses prime number sizing for better distribution
- Double hashing for collision resolution
  - Minimizes clustering
  - Efficient probing sequence
- Memory efficient implementation
  - Optimized memory usage
  - Proper cleanup of deleted items
- Complete API for hash table operations
  - Insert/Update
  - Search
  - Delete
  - Automatic memory management

## Building the Project

### Prerequisites

- C compiler (GCC, Clang, or MSVC)
- CMake (version 3.5 or higher)
- Math library (usually included with C standard library)

### Build Instructions

1. Clone the repository:
```bash
git clone git@github.com:pikuskrystian/ht_in_c.git
cd ht_in_c
```

2. Create a build directory and build the project:
```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

The executable will be created in the `build/Release` directory.

## Usage Example

```c
#include "hash_table.h"
#include <stdio.h>

int main() {
    // Create a new hash table
    ht_hash_table* ht = ht_new();
    
    // Insert key-value pairs
    ht_insert(ht, "name", "John Doe");
    ht_insert(ht, "age", "30");
    ht_insert(ht, "city", "New York");
    
    // Search for values
    char* name = ht_search(ht, "name");
    if (name) {
        printf("Name: %s\n", name);
    }
    
    // Delete items
    ht_delete(ht, "age");
    
    // Clean up
    ht_del_hash_table(ht);
    
    return 0;
}
```

## API Reference

### Data Structures

```c
typedef struct {
    char* key;
    char* value;
} ht_item;

typedef struct {
    int base_size;    // Initial size before finding next prime
    int size;         // Actual size (prime number)
    int count;        // Number of items
    ht_item** items;  // Array of pointers to items
} ht_hash_table;
```

### Functions

#### Creation and Deletion
- `ht_hash_table* ht_new()`: Creates a new hash table with default initial size
- `void ht_del_hash_table(ht_hash_table* ht)`: Deletes hash table and frees all memory

#### Operations
- `void ht_insert(ht_hash_table* ht, const char* key, const char* value)`: 
  - Inserts or updates a key-value pair
  - Triggers resize if load factor > 70%
- `char* ht_search(ht_hash_table* ht, const char* key)`: 
  - Searches for a value by key
  - Returns NULL if key not found
- `void ht_delete(ht_hash_table* ht, const char* key)`:
  - Deletes a key-value pair
  - Triggers resize if load factor < 10%

## Implementation Details

### Hash Function
- Uses double hashing for collision resolution
- Primary hash: \( hash_a = hash(key, 151, size) \)
- Secondary hash: \( hash_b = hash(key, 163, size) \)
- Probe sequence: \( index = (hash_a + i * (hash_b + 1)) \bmod size \)

### Dynamic Resizing
- Initial size: 50 (adjusted to next prime)
- Growth factor: 2x when load factor > 70%
- Shrink factor: 0.5x when load factor < 10%
- All sizes are adjusted to the next prime number

### Memory Management
- Automatic cleanup of deleted items
- Proper handling of string duplicates
- No memory leaks in resize operations
- Special marker for deleted items to maintain chain integrity

## Contributing

Contributions are welcome! Here are some ways you can contribute:
- Report bugs
- Suggest enhancements
- Submit pull requests
- Improve documentation

## License

This project is open source and available under the MIT License.

## Author

Krystian Pikus 