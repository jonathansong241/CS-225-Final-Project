
using namespace std;
#include <string>
#include <vector>
#include "map.h"

class BFS {
    public:
        /**
         * Constructor to initialize BFS class and create adjacency list for the graph
         * @param airportFile The file of airports
         * @param routeFile The file of routes between airports
         */
        BFS(const string &airportFile, const string &routeFile);

        /**
         * Function to perform Breadth First Search on the graph
         * @param start String representing the starting vertex to perform BFS
         * @return vector of strings representing nodes in the order they were traversed
         */
        vector<string> BreadthFS(string start);
        
    private:
        /**
         * Helper function to create the adjacency list of the graph
         * @param adj Reference to the adjacency list to fill
         */
        void getAdjacent(map<string, vector<string>>& adj);

        // Adjacency list mapping node to its neighbors
        map<string, vector<string>> adj_;
        // The graph of airports and routes
        Map graph_;

        
};
