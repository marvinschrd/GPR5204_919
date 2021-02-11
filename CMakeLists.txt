cmake_minimum_required(VERSION 3.18)

# set the project name
project(GPR5204)

find_package(GTest CONFIG REQUIRED)
    
file(GLOB_RECURSE SRC_FILES include/*.h src/*.cpp)
add_library(Common STATIC ${SRC_FILES})
target_include_directories(Common PUBLIC "include/")

file(GLOB_RECURSE TEST_FILES test/*.cpp)
add_executable(CommonTest ${TEST_FILES})
target_link_libraries(CommonTest PRIVATE Common)
target_link_libraries(CommonTest PRIVATE GTest::gtest GTest::gtest_main)