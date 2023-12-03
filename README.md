
# Trie Project

## Description

This project implements a Trie (prefix tree) data structure in C++. It offers efficient insertion, search, and delete operations for string keys. The Trie is particularly useful for tasks such as autocomplete, spell checking, and prefix-based search.

## Features

- Insert words into the Trie.
- Search for words in the Trie.
- Delete words from the Trie.
- Perform prefix searches to support features like autocomplete.

## Getting Started

### Dependencies

- C++ compiler (C++17 or later recommended)
- [Google Test](https://github.com/google/googletest) for running unit tests (optional)

### Installing

- Clone the repository: 
  ```
  git clone https://github.com/yourusername/trie-project.git
  ```
- Navigate to the project directory:
  ```
  cd trie-project
  ```

### Building the Project

- Create a build directory and navigate to it:
  ```
  mkdir build && cd build
  ```
- Run CMake and build the project:
  ```
  cmake .. && make
  ```

## Running the Tests

To run the automated tests for this system:

- Navigate to the build directory:
  ```
  cd path/to/build
  ```
- Run the tests:
  ```
  ./runUnitTests
  ```

## Usage

The Trie can be used as follows:

```cpp
#include "Trie.h"

int main() {
    Trie trie;
    trie.insert("example");
    bool found = trie.search("example");
    trie.remove("example");
    return 0;
}
```

## Contributing

Contributions to this project are welcome. Please follow the standard GitHub fork and pull request workflow.

## Authors

Your Name

## License

This project is licensed under the [MIT License](LICENSE.txt) - see the LICENSE.txt file for details.
