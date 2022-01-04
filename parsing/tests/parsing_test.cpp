#include "catch2/catch.hpp"
#include "../include/map.h"

TEST_CASE("Parsing file test") {
    SECTION("Testing Airports Parsing") {

        Map map("../data/airportTest.txt", "../data/routesTest.txt");

        vector<string> test_airports = map.getAirports();


        REQUIRE(test_airports.size() == 11);
        REQUIRE(test_airports[0] == "LAN");
        REQUIRE(test_airports[1] == "BIX");
        REQUIRE(test_airports[2] == "LSF");
        REQUIRE(test_airports[3] == "NQI");
        REQUIRE(test_airports[4] == "FRI");
            
    }
}

TEST_CASE("Parsing file test2") {
    SECTION("Testing Routes Parsing") {

        Map map("../data/airportTest.txt", "../data/routesTest.txt");

        vector<Route> test_routes = map.getRoutes();


        REQUIRE(test_routes.size() == 10);
        REQUIRE(test_routes[3].getDest() == "UIO");
        REQUIRE(test_routes[3].getOrigin() == "OCC");
        REQUIRE(test_routes[4].getDest() == "GYE");
        REQUIRE(test_routes[4].getOrigin() == "SCY");
        REQUIRE(test_routes[5].getDest() == "BOG");
        REQUIRE(test_routes[5].getOrigin() == "UIO");
        REQUIRE(test_routes[6].getDest() == "GYE");
        REQUIRE(test_routes[6].getOrigin() == "UIO");

    }
}
