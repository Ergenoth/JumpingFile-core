cmake_minimum_required(VERSION 3.10)
project(JumpingFile-core)

# Catch2
FIND_PACKAGE(Catch2 3 REQUIRED)

# Boost
FIND_PACKAGE(Boost COMPONENTS program_options REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

# Crow
FIND_PACKAGE(Crow)

# Test (Playground)
INCLUDE_DIRECTORIES("../include/jumpingkey/test")

# Application
add_executable(JumpingFile-core "../src/main/main.cpp")
TARGET_LINK_LIBRARIES(JumpingFile-core ${Boost_LIBRARIES})
TARGET_LINK_LIBRARIES(JumpingFile-core Crow::Crow)

# PThread for Boost Asio
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# Test Suite for the application
add_executable(JumpingFile-core-Test "../tests/testMain.cpp")
target_link_libraries(JumpingFile-core-Test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(JumpingFile-core-Test PRIVATE Threads::Threads)
target_sources(JumpingFile-core-Test PRIVATE "../src/jumpingkey/test/testClass.cpp")
target_sources(JumpingFile-core-Test PRIVATE "../src/jumpingkey/test/testRunListener.cpp")