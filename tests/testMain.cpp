#define CATCH_CONFIG_MAIN

// #include "catch.hpp"
#include <catch2/catch_test_macros.hpp>
#include "testClass.h"

TEST_CASE ("Startup", "[Startup]") {
    testClass myObject;
    REQUIRE ( myObject.serverStartup() == "Up and running");
}