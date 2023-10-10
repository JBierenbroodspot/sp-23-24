enable_language(C)

add_library(datatypes "string.c" "code.c" "datatypes.c" "feedback.c" "guess.c")

target_include_directories(datatypes 
    PUBLIC "${PROJECT_SOURCE_DIR}/include/datatypes")

# m is the math library, needs to be linked before it can be used.
target_link_libraries(datatypes PRIVATE m)