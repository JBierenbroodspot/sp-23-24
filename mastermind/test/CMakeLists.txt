# GTest is a C++ framework so tests will be written in C++ instead of C.
enable_language(CXX)

include(GoogleTest)
include(CTest)

enable_testing()
set(TEST_SRC_FILES test_datatypes.cpp)

include_directories(${mastermind_SOURCE_DIR}/src/include/)

add_executable(test_mastermind ${TEST_SRC_FILES})
target_link_libraries(test_mastermind GTest::gtest_main)

gtest_discover_tests(test_mastermind)
