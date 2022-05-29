cmake_minimum_required(VERSION 3.16)
project(tmp C)

set(CMAKE_C_STANDARD 99)

add_executable(tmp main.c libTmp.c libTmp.h queueLib.c queueLib.h general.h)
