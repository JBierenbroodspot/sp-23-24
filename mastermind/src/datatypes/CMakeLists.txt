enable_language(C)

add_library(datatypes "string.c")

target_include_directories(datatypes 
    PUBLIC "${PROJECT_SOURCE_DIR}/include/datatypes")