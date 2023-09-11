# This file is used to configure the build process of a C project.

# Not entirely required but added to show that this part of the project is
# written in C as opposed to C++.
enable_language(C)

# A library is created out of the source files to be able to link these to the
# test framework.
add_library(mastermind_lib 
    datatypes.c
)

# Define in what directories the include files can be found for the 
# mastermind_lib library.
target_include_directories(mastermind_lib
    # We use PUBLIC to indicate that not only the target can use these include
    # files but also anything that links to this library.
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# These files will be compiled into an executable.
add_executable(mastermind
    main.c
)

# Define what libraries the target is allowd to use.
target_link_libraries(mastermind
    # Note: Since we pubicly added include directories to this library the 
    # target can now make use of the definitions inside those headers.
    mastermind_lib
)