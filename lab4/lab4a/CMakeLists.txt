cmake_minimum_required(VERSION 3.16)
project(lab4 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab4 main.c Model/general.h Model/BinTreeLib.c Model/BinTreeLib.h Model/utilLib.c Model/utilLib.h Controller/dialog.c Controller/dialog.h View/dialogTree.c View/dialogTree.h View/errorsLib.c View/errorsLib.h View/options.c View/options.h Model/fileTree.c Model/fileTree.h Model/freqWords.c Model/freqWords.h)
