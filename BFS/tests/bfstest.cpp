// TODO: Write your tests here!
#include <vector>
#include <string>
#include <algorithm>
#include "catch2/catch.hpp"
#include "../include/bfs.hpp"
using std::string;
using std::cout;
using std::endl;

TEST_CASE("BFS test1") {
    SECTION("Traversing large connected component") {
        BFS bfs("../BFS/tests/airports_20.dat", "../BFS/tests/routes_20.dat");
        string input = "ORD";
        vector<string> test = bfs.BreadthFS(input);

        REQUIRE(test.size() == 14);
        REQUIRE(test[0] == "ORD");
        REQUIRE(test[2] == "DEC");
        REQUIRE(test[13] == "BOS");

        // Check if disconnected airports are not traversed
        REQUIRE(std::count(test.begin(), test.end(), "LAE") == 0);
        REQUIRE(std::count(test.begin(), test.end(), "YAY") == 0);
    }

    SECTION("Traversing disconnected vertex") {
        BFS bfs("../BFS/tests/airports_20.dat", "../BFS/tests/routes_20.dat");
        string input = "LAE";
        vector<string> test = bfs.BreadthFS(input);

        REQUIRE(test.size() == 1);
        REQUIRE(test[0] == "LAE");

        // Check if disconnected airports are not traversed
        REQUIRE(std::count(test.begin(), test.end(), "ORD") == 0);
        REQUIRE(std::count(test.begin(), test.end(), "YAY") == 0);
        REQUIRE(std::count(test.begin(), test.end(), "BOS") == 0);
    }
}


TEST_CASE("BFS test2") {
    SECTION("Test traversing_2") {
        BFS bfs("../BFS/tests/airports_30.dat", "../BFS/tests/routes_30.dat");
        string input = "JFK";
        vector<string> test = bfs.BreadthFS(input);

        REQUIRE(test.size() == 20);
        REQUIRE(test[0] == "JFK");
        REQUIRE(test[1] == "EZE");
        REQUIRE(test[4] == "AMM");
        REQUIRE(test[10] == "BNA");
        REQUIRE(test[19] == "CVG");
        REQUIRE(std::count(test.begin(), test.end(), "EGS") == 0);
        REQUIRE(std::count(test.begin(), test.end(), "RKV") == 0);
        REQUIRE(std::count(test.begin(), test.end(), "YAM") == 0);
    }
}




