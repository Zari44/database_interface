cmake_minimum_required(VERSION 3.8)
project(txstore)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/Database.h src/TransactionStore.cpp src/TransactionStore.h src/Tests.cpp)

add_subdirectory(googletest)

add_executable(txstore ${SOURCE_FILES})
target_link_libraries(txstore gtest_main)