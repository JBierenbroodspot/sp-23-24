enable_testing()

set(TEST_SRC_FILES test_main.c test_datatypes.c)

add_executable(test_mastermind ${TEST_SRC_FILES})
target_link_libraries(test_mastermind GTest::gtest_main)

include(GoogleTest)