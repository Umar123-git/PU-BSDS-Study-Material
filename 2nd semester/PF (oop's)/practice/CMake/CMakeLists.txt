cmake_minimum_required(VERSION 3.10)
project(CashMemoApp)

# Set the C++ standard to C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    main.cpp
    Date.cpp
    SaleLine.cpp
    CashMemo.cpp
)

add_executable(CashMemoApp ${SOURCES})
