// math-catch.cpp
// Bernard Laughlin 11/10/2021
// Uses Catch2 to test sin, atan, accumulate, and inner_product

#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <math.h>
#include <algorithm>
using std::accumulate;
using std::inner_product;
#include <vector>
using std::vector;
#define PI 3.14159265

TEST_CASE("Sin is computed", "[sin]") {
    REQUIRE( sin(0 * PI/180) == 0);
    REQUIRE( sin(30 * PI/180) == Approx(0.5));
    REQUIRE( sin(90 * PI/180) == 1);
}

TEST_CASE("arc tangent is computed", "[atan2]") {
    REQUIRE( (atan2(10.0,-10.0) * 180/PI) == Approx(135.0));
    REQUIRE( (atan2(10.0, 10.0) * 180/PI) == Approx(45.0));
}

TEST_CASE("accumulate is computed", "[accumulate]") {
    vector<int> v{1,2,3,4,5,6,7,8,9,10};
    vector<int> z{0,-10,10};
    REQUIRE( accumulate(v.begin(), v.end(), 0) == 55);
    REQUIRE( accumulate(z.begin(), z.end(), 0) == 0);

}

TEST_CASE("inner_product is computed", "[inner_product]") {
    vector<int> a{0,1,2,3,4};
    vector<int> b{5,4,2,3,1};
    REQUIRE( inner_product(a.begin(), a.end(), b.begin(), 0) == 21);
}

