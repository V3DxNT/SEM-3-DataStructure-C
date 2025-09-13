#cmake_minimum_required(VERSION 3.31)
#project(SEM_3_DS_C C)
#
#set(CMAKE_C_STANDARD 11)
#
## Automatically include all .c files in the project
#file(GLOB SOURCES "*.c")
#
#add_executable(SEM_3_DS_C ${SOURCES}
#        check.c)
#

cmake_minimum_required(VERSION 3.16)
project(SEM_3_DS_C C)

set(CMAKE_C_STANDARD 11)

# Create one executable per C file
file(GLOB SOURCES "*.c")
foreach(src_file ${SOURCES})
    # Get the filename without extension
    get_filename_component(exe_name ${src_file} NAME_WE)
    add_executable(${exe_name} ${src_file}
            C1_DynamicArrayUsingPointer.c
            C2_InfixToPostfix.c)
endforeach()
