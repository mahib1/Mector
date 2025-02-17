# Array Library

This C++ header file provides a custom dynamic array implementation using macros for easy creation of type-specific array classes. It supports common operations like push, pop, reverse, and more, while hiding the underlying implementation.

## Features
- **Dynamic Resizing**: Automatically resizes when the capacity exceeds 70%.
- **Range Safety**: Index checks to prevent out-of-bounds access.
- **Custom Types**: Easily create arrays for any data type using macros.
- **Common Operations**:
  - `push_back()`: Adds an element to the end.
  - `pop_back()`: Removes the last element.
  - `reverse()`: Reverses the array in-place.
  - `operator[]`: Access elements by index.
  - `size()`: Returns the number of elements.
  - `begin()` and `end()`: Iterator support for range-based loops.

## Installation
Simply include the header file in your project:
```cpp
#include "arrayBuilder.h"
```

## Usage Example
```cpp
#include "arrayBuilder.h"
ArrayClassBuilder(int)  // Create a dynamic array class for integers

int main() {
    Array(int) myArray;
    myArray.push_back(10);
    myArray.push_back(20);
    myArray.push_back(30);

    for (int *it = myArray.begin(); it != myArray.end(); ++it) {
        std::cout << *it << " ";
    }
    // Output: 10 20 30

    myArray.reverse();

    for (int *it = myArray.begin(); it != myArray.end(); ++it) {
        std::cout << *it << " ";
    }
    // Output: 30 20 10

    return 0;
}
```

## Why Use This Library?
This library is a lightweight alternative to `std::vector`, ideal for:
- Learning about dynamic array implementations.
- Custom requirements where a simpler, more controlled dynamic array is needed.
- Competitive programming where STL usage is restricted or not preferred.
- Thread-safe.

## Limitations
- Limited to basic operations; no support for advanced algorithms.
- Error handling uses exceptions for boundary checks.

## License
This project is licensed under the MIT License - feel free to use and modify it as needed.

## Contributing
Contributions are welcome! Feel free to open issues or submit pull requests.

---

This library provides an efficient way to manage dynamic arrays while keeping your source code private by using only the header file.
