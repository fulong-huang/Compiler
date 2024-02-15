cmake_minimum_required(VERSION 3.8)

project(Compiler)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(src include)

add_executable(Compiler
	main.cpp
	src/FileReader.cpp
)

