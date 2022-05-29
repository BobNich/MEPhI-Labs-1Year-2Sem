cmake_minimum_required(VERSION 3.16)
project(lab4b C)

set(CMAKE_C_STANDARD 99)

add_executable(lab4 main.c Model/general.h Model/TreeLib.c Model/TreeLib.h Model/utilLib.c Model/utilLib.h Controller/controller.c Controller/controller.h View/dialog.c View/dialog.h View/errs.c View/errs.h View/options.c View/options.h Model/file.c Model/file.h Model/graphvizLib.c Model/graphvizLib.h Model/fastFinding.c Model/fastFinding.h)
