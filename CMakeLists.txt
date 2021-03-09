cmake_minimum_required(VERSION 3.17)
project(alg C)

set(CMAKE_C_STANDARD 99)

add_executable(alg main.c strstr_bf/strstr_bf.c strstr_bf/strstr_bf.h strstr_kmp/strstr_kmp.c strstr_kmp/strstr_kmp.h)