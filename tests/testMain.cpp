#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "testClass.h"

TEST_CASE ("My first test case", "[Test case]") {
    testClass myObject;
    REQUIRE ( myObject.printMessage() == "Good Morning Starshine!");
}