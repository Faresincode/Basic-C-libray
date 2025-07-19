# Basic-C-libray
MyLib is a single-header C++ utility library with ready-to-use functions for dates, math, arrays, input/output, and more — perfect for small projects and learning.



# 📚 MyLib - Simple C++ Utility Library

**MyLib** is a single header file (`MyLib.h`) that contains a collection of useful C++ functions. It includes ready-made tools for working with dates, numbers, arrays, input/output, and more — perfect for students, competitive programmers, or anyone building quick C++ projects.

---

## 📦 What's Inside

`MyLib.h` provides:

- 🗓️ **Date Functions**
  - Add or subtract days, months, or years...etc
  - Compare dates, get today's date, check leap year...etc
- ➗ **Math Functions**
  - Check for prime, perfect, or palindrome numbers...etc
  - Count digits, reverse numbers, convert bases...etc
- 🔢 **Array Functions**
  - Shuffle arrays, filter even/odd, get min/max/sum...etc
- 🖨️ **Print Functions**
  - Print arrays and data in clean formats...etc
  - Print colored text (red, green, blue)...etc
- 📥 **Input Functions**
  - Get validated integer, float, or string input...etc
- 🎛️ **Utility Enums**
  - For states like Prime/NotPrime, Yes/No, Positive/Negative, ...etc.

---

## 🚀 How to Use

1. Copy `MyLib.h` into your project.
2. Include it in your `.cpp` file:

```cpp
#include "MyLib.h"

int main() {
    // Date usage
    stDate today = MyDateFunction::GetSystemDate();
    MyPrintFunction::PrintDate(today);

    // Math usage
    std::cout << "Is 7 prime? " << MyCmathFunction::IsPrime(7) << std::endl;

    // Array usage
    int numbers[] = {1, 2, 3, 4, 5};
    MyArrayFunction::ShuffleArray(numbers, 5);
    MyPrintFunction::PrintIntArray(numbers, 5);

    return 0;
}
```

---

## 🛠 Requirements

- Works with any **C++11 or later** compiler
- No external libraries required

---

## 📜 License

This project is licensed under the **MIT License** — free to use, modify, or share.

---

Made with ❤️ for learning, speed, and simple C++ development.
