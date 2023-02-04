cmake_minimum_required(VERSION 3.10)
project(JumpingFile-core)

# Boost
FIND_PACKAGE(Boost COMPONENTS program_options REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

# Test (Playground)
INCLUDE_DIRECTORIES("../include/jumpingkey/test")

# Application
add_executable(JumpingFile-core "../src/main/main.cpp")
target_sources(JumpingFile-core PRIVATE "../src/jumpingkey/test/testClass.cpp")
TARGET_LINK_LIBRARIES(JumpingFile-core ${Boost_LIBRARIES})

# Test Suite for the application
add_executable(JumpingFile-core-Test "../tests/testMain.cpp")
target_include_directories(JumpingFile-core-Test PRIVATE "../include")
target_sources(JumpingFile-core-Test PRIVATE "../src/jumpingkey/test/testClass.cpp")