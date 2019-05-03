#include "doctest.h"

#include <stdexcept>

#include <ExampleClass.hpp>

TEST_CASE("testing if true is true") {

    auto value = ExampleClass().returnValue();

    REQUIRE(ExampleClass().returnValue() == 3);

    SUBCASE("When multiplied by 3 should equal 9")
    {
        CHECK(value*3 == 9);
    }
    SUBCASE("When divided by 3 should equal 1")
    {
        value/= 3;
        CHECK(value == 1);
    }

    SUBCASE("When added 2 shall equal 5")
    {
        value += 2;
        CHECK(value == 5);

        SUBCASE("then when subtracted 2 shall equal 3")
        {
            value -= 2;
            CHECK(value == 3);

            SUBCASE("then when divided by 3 should equal 1")
            {
                value /= 3;
                CHECK(value == 1);
            }
            SUBCASE("When added 2 shall equal 5")
            {
                value += 2;
                CHECK(value == 5);
            }
        }
    }
}


TEST_CASE("Example matchers")
{
    CHECK_EQ(3, 3); // 3==3
    CHECK_NE(5, 4); // 5!=4

    CHECK_GT(7,5); // 7>5
    CHECK_LT(2,3); // 2<3

    CHECK_GE(5,4); // 5>=4
    CHECK_LE(3,3); // 3<=3

    CHECK(true);
    CHECK_FALSE(false);

    CHECK_EQ(3, 3); // 3==3 if fails fail testcase but it runs 
    REQUIRE_EQ(3, 3); // if fails break the testcase
    WARN_EQ(3, 3); // if fails just print message


    WARN_MESSAGE(3 == 5, " to jest message ktory sie wypisze ");
    CHECK_MESSAGE(3 == 3, " to jest message ktory sie wypisze ");

    auto func = [](){
        throw std::logic_error("e");
    };
    CHECK_THROWS_AS(func(), std::logic_error); // same as above
    CHECK_THROWS_WITH(func(), "e");

    REQUIRE(22.0/7 == doctest::Approx(3.141).epsilon(0.01)); // allow for a 1% error
}