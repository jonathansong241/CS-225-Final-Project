#pragma once

using namespace std;
#include "../parsing/include/airport.h"
#include "../parsing/include/route.h"
#include "../parsing/include/map.h"
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

 /**
     * @brief A structure containing tentative distance and airport
     * to help traverse the graph and find the Dijkstra distance.
     */
struct D_Node {
    double tentative_distance = -1; // -1 distance is taken equivalent infinity as distance cannot be negative.
    Airport airport;
    int index; // to keep track of previous nodes
};

class Dijkstra {

    public:
    /**
     * @brief Construct a new Dijkstra object
     * 
     * @param map the graph to traverse.
     */
    Dijkstra(Map map);

    /**
     * @brief Finds the shortest path from source to destination
     * 
     * @param map the graph to traverse in
     * @param source the starting airport
     * @param destination the final airport to reach
     * @return std::vector<Airport> vector of airports, detailing the required path
     */
    std::vector<Airport> ShortestDijkstraPath(Map map, string source, string destination);

    /**
     * @brief Get the Min Distance as an integer of the last Dijkstra call
     * 
     * @return int the distance of the shortest path.
     */
    int getMinDist();

    /**
     * @brief Get the Dijkstra Nodes object
     * 
     * @return unordered_map<string, Node> 
     */
    map<string, D_Node> getDijkstraNodes();


    private:
    // a map containing all the nodes with the key as the airport code
    unordered_map<string, Node> nodes_;

    // map containing D_Nodes with the key as the airport code
    map<string, D_Node> map_;

    // the priority queue to hold all the nodes of the graph as we traverse
    priority_queue<int> priQueue_;

    // a map containing airport code as the key and a boolean value to help traverse the graph
    unordered_map<string, bool> visited_;
    
    // the minimum distance of the last iteration Dijkstra was run on
    double minDist;

    // --------------- HELPER FUNCTIONS ----------------------------------

     /**
     * @brief Get the Neighbour Names for the required airport
     * 
     * @param source_airport the airport to find the neighbours of
     * @return std::vector<string> returns a vector containing 
     * all the codes of airports that are neighbor nodes for required node.
     */
    std::vector<string> getNeighbourNames(std::string source_airport);

    /**
     * @brief Get the distance along a route
     * 
     * @param source the source airport to start from
     * @param dest the destination airport code
     * @return double distance
     */
    double getRouteDistance(string source, string dest);
};