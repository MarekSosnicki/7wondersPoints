#include "doctest.h"

#include <ExampleClass.hpp>

TEST_CASE("testing different something") {
    CHECK(ExampleClass().returnValue() == 3);
}