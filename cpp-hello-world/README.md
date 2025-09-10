# C++ Hello World Project

This project is a simple C++ application that prints "Hello, World!" to the console.

## Project Structure

```
cpp-hello-world
├── src
│   └── main.cpp
├── CMakeLists.txt
└── README.md
```

## Requirements

- CMake
- A C++ compiler (e.g., g++, clang++)

## Building the Project

1. Open a terminal and navigate to the project directory.
2. Create a build directory:
   ```
   mkdir build
   cd build
   ```
3. Run CMake to configure the project:
   ```
   cmake ..
   ```
4. Build the project:
   ```
   make
   ```

## Running the Application

After building the project, you can run the application with the following command:

```
./cpp-hello-world
```

You should see the output:

```
Hello, World!
```

## Runing the unit tests

After building the project, you can run unit tests with the command:

'''
ctest
'''
