CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(JumpingFile-core)

# Catch2
FIND_PACKAGE(Catch2 3 REQUIRED)

# Boost
#FIND_PACKAGE(Boost COMPONENTS program_options REQUIRED)
FIND_PACKAGE(Boost COMPONENTS log_setup log)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

# Crow
FIND_PACKAGE(Crow)

# PThread for Boost Asio
SET(THREADS_PREFER_PTHREAD_FLAG ON)
FIND_PACKAGE(Threads REQUIRED)

# Application
ADD_EXECUTABLE(JumpingFile-core "src/main/main.cpp")
TARGET_LINK_LIBRARIES(JumpingFile-core PRIVATE 
    ${Boost_LIBRARIES}
    Crow::Crow
)
TARGET_INCLUDE_DIRECTORIES(JumpingFile-core PRIVATE 
    "include/jumpingkey/core/configuration"
    "include/jumpingkey/core/webservices"
    "include/jumpingkey/core/log"
)
target_sources(JumpingFile-core PRIVATE 
    "src/jumpingkey/core/configuration/JumpingfileConfiguration.cpp"
    "src/jumpingkey/core/webservices/StatusWebService.cpp"
    "src/jumpingkey/core/log/JumpingFileLogger.cpp"
    "src/jumpingkey/core/log/Logger.cpp"
)

# Test Suite for the application
ADD_EXECUTABLE(JumpingFile-core-Test "tests/testMain.cpp")
TARGET_LINK_LIBRARIES(JumpingFile-core-Test PRIVATE 
    Catch2::Catch2WithMain
    Threads::Threads
)
TARGET_INCLUDE_DIRECTORIES(JumpingFile-core-Test PRIVATE 
    "include/jumpingkey/test"
)
TARGET_SOURCES(JumpingFile-core-Test PRIVATE 
    "src/jumpingkey/test/testClass.cpp"
    "src/jumpingkey/test/testRunListener.cpp"
)