# This file is used to configure the build process of a C project.

# Not entirely required but added to show that this part of the project is
# written in C as opposed to C++.
enable_language(C)

add_library(mastermind SHARED "datatypes.c")

# Define in what directories the include files can be found for the 
# mastermind_lib library.
target_include_directories(mastermind
    PRIVATE "${PROJECT_SOURCE_DIR}/include/")

# These files will be compiled into an executable.
add_executable(mastermind_bin "main.c")

# Define what libraries the target is allowd to use.
target_link_libraries(mastermind_bin PRIVATE mastermind)
