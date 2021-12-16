# Matrix-Operation-in-Cpp

This is a high-performance, portable linear algebra library for a client who has an awful case of not-invented-here syndrome. As a start, the client has asked for just transpose and multiplication of MxN matrices.

This is a great opportunity to practice templates, polymorphism, overload and friends in C++ and it is implemented in standard C++11.

- With template in C++, we could make matrices of any type or class we want.

- With overload in C++, we could use operaters like "=", "<<" or "*" in matrices class difined by ourselve.

## Usage

You could simply include the "MatrixLib.h" to use this library.

'''bash
g++ test.cpp MatrixLib.h -o test -std=c++11 -lthread
test
'''

## Reference

https://github.com/andrea993/Matrix-Library-Cpp