cmake_minimum_required(VERSION 3.13)
project(project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(project1 main.cpp Expression.h UnaryExpression.h Neg.cpp Neg.h BinaryExpression.h
        Div.cpp
        Div.h
        Expression.h
        Minus.cpp
        Minus.h
        Mul.cpp
        Mul.h
        Number.cpp
        Number.h
        Plus.cpp
        Plus.h)