cmake_minimum_required(VERSION 3.16)
project(lab3a C)

set(CMAKE_C_STANDARD 99)

add_executable(lab3 main.c dialog.c dialog.h tableUtilities.c tableUtilities.h lib.c lib.h funcDialog.c funcDialog.h general.h keySpacesLib.c keySpacesLib.h keySpace1.c keySpace1.h keySpace2.c keySpace2.h fTableLib.c fTableLib.h)
