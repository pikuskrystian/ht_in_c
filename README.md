# Hash Table Implementation in C

A simple and efficient hash table implementation in C, featuring dynamic resizing and collision handling.

## Features

- Dynamic hash table with automatic resizing
- Double hashing for collision resolution
- Memory efficient implementation
- Thread-safe operations
- Simple and clean API

## Building the Project

### Prerequisites

- C compiler (GCC, Clang, or MSVC)
- CMake (version 3.5 or higher)

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

## Usage

Here's a simple example of how to use the hash table:

```c
#include "hash_table.h"

int main() {
    // Create a new hash table
    ht_hash_table* ht = ht_new();
    
    // Insert some key-value pairs
    ht_insert(ht, "key1", "value1");
    ht_insert(ht, "key2", "value2");
    
    // Retrieve values
    char* value = ht_search(ht, "key1");
    printf("Value for key1: %s\n", value);
    
    // Delete items
    ht_delete(ht, "key1");
    
    // Free the hash table
    ht_del_hash_table(ht);
    
    return 0;
}
```

## API Reference

### Functions

- `ht_hash_table* ht_new()`: Creates a new hash table
- `void ht_del_hash_table(ht_hash_table* ht)`: Deletes a hash table and frees all memory
- `void ht_insert(ht_hash_table* ht, const char* key, const char* value)`: Inserts a key-value pair
- `char* ht_search(ht_hash_table* ht, const char* key)`: Searches for a value by key
- `void ht_delete(ht_hash_table* ht, const char* key)`: Deletes a key-value pair

## Implementation Details

The hash table implementation uses:
- Double hashing for collision resolution
- Dynamic resizing based on load factor
- Prime number sizing for better distribution
- Memory-efficient storage

## License

This project is open source and available under the MIT License.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request. 