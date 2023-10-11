# This file is used to configure the build process of a C project.

# Not entirely required but added to show that this part of the project is
# written in C as opposed to C++.
enable_language(C)

add_subdirectory(datatypes)

# These files will be compiled into an executable.
add_executable(mastermind "main.c" "secret_code.c")

target_include_directories(mastermind 
    PRIVATE "${PROJECT_SOURCE_DIR}/include/game")

# Define what libraries the target is allowd to use.
target_link_libraries(mastermind PRIVATE datatypes)
