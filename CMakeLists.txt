cmake_minimum_required(VERSION 3.17)
project(Regex_na_automat C)

set(CMAKE_C_STANDARD 99)

add_executable(Regex_na_automat main.c regex.c regex.h file.c)