#include "../include/Dijkstra.h"
#include "../parsing/include/map.h"
#include "catch2/catch.hpp"

TEST_CASE("Dijkstra test1") {
    Map map_("../BFS/tests/airports_20.dat", "../BFS/tests/routes_20.dat");
    Dijkstra dj(map_);
    SECTION("Checking Distance") {
        vector<Airport> airports = dj.ShortestDijkstraPath(map_, "ORD", "BRL");
        int dist = dj.getMinDist();
        REQUIRE(dist == 371);
    }
    SECTION("Testing D_Nodes") {
        D_Node test;
        Airport airport = Airport();
        test.index = 0;
        REQUIRE(test.index == 0);
        REQUIRE(test.tentative_distance == -1);
        test.tentative_distance = 40;
        REQUIRE(test.tentative_distance == 40);
    }
    SECTION("Testing D_Nodes") {
        map<string, D_Node> myMap = dj.getDijkstraNodes();
        for (auto i : myMap) {
            // uncomment to print out all nodes in the basic graph structure for dijkstra with default values
            //cout << i.first << endl;
            //cout << i.second.tentative_distance << endl;
        }
    }
}