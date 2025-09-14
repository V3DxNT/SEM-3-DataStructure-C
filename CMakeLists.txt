cmake_minimum_required(VERSION 3.16)
project(SEM_3_DS_C C)

set(CMAKE_C_STANDARD 11)

# Executable for DynamicArray program
add_executable(C1_DynamicArrayUsingPointer
        C1_DynamicArrayUsingPointer.c
        # add helper files here if any
)

# Executable for InfixToPostfix program
add_executable(C2_InfixToPostfix
        C2_InfixToPostfix.c
        # add helper files here if any
)

#cmake_minimum_required(VERSION 3.16)
#project(SEM_3_DS_C C)
#
#set(CMAKE_C_STANDARD 11)
#
## Get all C source files
#file(GLOB ALL_C_FILES "*.c")
#
## Lists to store programs and modules
#set(PROGRAMS "")
#set(MODULES "")
#
## Separate files with main (programs) from helper modules
#foreach(file ${ALL_C_FILES})
#    file(READ ${file} FILE_CONTENT)
#    if(FILE_CONTENT MATCHES "\\bmain\\s*\\(")
#        list(APPEND PROGRAMS ${file})
#    else()
#        list(APPEND MODULES ${file})
#    endif()
#endforeach()
#
## Create one executable per program, linking helper modules
#foreach(prog ${PROGRAMS})
#    # Get the program name without extension
#    get_filename_component(prog_name ${prog} NAME_WE)
#    add_executable(${prog_name} ${prog} ${MODULES})
#endforeach()
