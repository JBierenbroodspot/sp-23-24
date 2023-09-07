# GTest is a C++ framework so tests will be written in C++ instead of C.
enable_language(CXX)

enable_testing()
set(TEST_SRC_FILES test_datatypes.cpp)

add_executable(test_mastermind ${TEST_SRC_FILES})
target_link_libraries(test_mastermind GTest::gtest_main)

include(GoogleTest)