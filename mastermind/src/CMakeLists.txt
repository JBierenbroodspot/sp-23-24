enable_language(C)

add_library(mastermind_lib 
    datatypes.c
)

target_include_directories(mastermind_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(mastermind
    main.c
)

target_link_libraries(mastermind
    mastermind_lib
)