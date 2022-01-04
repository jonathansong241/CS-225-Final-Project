#include "../BC/includes/betweennescentrality.h"
#include "../parsing/include/Map.h"
#include "catch2/catch.hpp"

TEST_CASE("Parsing file test") {
    SECTION("Test basic file parsing") {

        Map map("../data/airportTest.txt", "../data/routesTest.txt");
        BetweennessCentrality bc = BetwennessCentrality();
        Node node = map.getDest().get(0);
        Airport airport = node.airport;
        cout << bc.FindCentrality(airport) << endl;        
    }
}