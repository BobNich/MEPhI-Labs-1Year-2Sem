cmake_minimum_required(VERSION 3.16)
project(lab5 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab5 main.c Model/general.h Model/GraphLib.c Model/GraphLib.h Model/utilLib.c Model/utilLib.h Controller/controller.c Controller/controller.h View/dialog.c View/dialog.h View/errs.c View/errs.h Model/canada.c Model/canada.h Model/graphvizLib.c Model/graphvizLib.h Model/vector.c Model/vector.h)
