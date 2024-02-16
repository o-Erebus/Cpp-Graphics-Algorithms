
# C++ Graphics Algorithms with CLion

> A simple graphics algorithms written in C++ using the `graphics.h` library and compiled in CLion.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [How to Run](#how-to-run)
- [Adding External Header and Library in CLion](#adding-external-header-and-library-in-clion)
- [Credits](#credits)
- [License](#license)

## Introduction

This C++ graphics program is designed to illustrate fundamental drawing algorithms such as DDA line drawing, Bresenham line drawing, and circle drawing. The program creates a simple scene featuring a house and a sun.

## Features

- Implements DDA and Bresenham line drawing algorithms.
- Demonstrates circle drawing algorithms, including Midpoint and Bresenham.
- Draws a basic scene with a house and a sun.

## Prerequisites

Before running this program, ensure you have the following installed:

- CLion or any other C++ IDE.
- A compatible C++ compiler (e.g., MinGW) with support for the `graphics.h` library.
- The `libbgi.a` library file.
Note: Both `graphics.h` and `libbgi.a` are included in the "Cpp-Graphics-Algorithms/Graphics"


## How to Run

1. Clone or download this repository to your local machine.
2. Open the project in CLion.
3. Build and run the project.

## Adding External Header and Library in CLion

To add the `graphics.h` header in CLion, follow these steps:

1. Copy `graphics.h` to `path\to\CLion\bin\mingw\lib\gcc\x86_64-w64-mingw32\13.1.0\include` and `path\to\CLion\bin\mingw\lib\gcc\x86_64-w64-mingw32\13.1.0\include\c++`
2. Restart Clion.


To add the `libbgi.a` library to your project in CLion, follow these steps:

1. Copy `libbgi.a` to `path\to\CLion\bin\mingw\lib\gcc\x86_64-w64-mingw32\13.1.0`
2. Open your `CMakeLists.txt` file.
3. Use the `target_link_libraries()` function to link the library to your executable target.
   ```cmake
   target_link_libraries(YourProjextName "\path\to\CLion\bin\mingw\lib\gcc\x86_64-w64-mingw32\13.1.0\include\libbgi.a")
   ```
   Replace `YourProjextName` with the name of your Clion Project and `\path\to\` with the actual path to the Clion.
4. Save the changes and reload the CMake project in CLion.


## Credits

This program is created by **o-Erebus**.

## License

This project is licensed under the [MIT License](LICENSE).
