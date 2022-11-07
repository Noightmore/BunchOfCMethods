cmake_minimum_required(VERSION 3.23)
project(StringOperations C)

set(CMAKE_C_STANDARD 99)

add_executable(StringOperations main.c stringTools.c stringBackupTool.c fileOperations.c otherTools.c)
