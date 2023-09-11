# GTest is a C++ framework so tests will be written in C++ instead of C.
enable_language(CXX)

enable_testing()
set(TEST_SRC_FILES test_datatypes.cpp)

add_executable(mastermind_test ${TEST_SRC_FILES})
target_link_libraries(mastermind_test 
    GTest::gtest_main
    mastermind_lib
)

include(GoogleTest)
gtest_discover_tests(mastermind_test)
