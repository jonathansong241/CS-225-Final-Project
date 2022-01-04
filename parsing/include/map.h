#pragma once
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <tuple>
#include <bits/stdc++.h>
#include "route.h"
#include "airport.h"
#include "../include/great_circle.h"

using std::vector;
using std::map;

struct Node {
    Airport airport;
    std::vector<Route> edges;
};

class Map {


    public:
        /**
         * Constructor to initialize Map class
         * @param airportFile The file of airports
         * @param routeFile The file of routes between airports
         */
        Map(const string &airportFile, const string &routeFile);

        /**
         * 
         *  constructor helper that
         *  creates graph containing Airports and Flights
         */
        void constructMap();

        /**
         * 
         *  adds airports to map seprates each line
         *  into vectors, and puts airport onto map
         */
        void insertAirports();

        /**
         * 
         *  adds flights connecting airports on map
         *  and also seperates each line into vectors,
         *  and connects airports on map (without distances calculated)
         */
        void insertFlights();

        /**
         * 
         *  A helper funciton for creating hubs at destination airports
         *  meaning the edges to each node are filled acorrding to their origin and destitination
         */
        void createHub();

        /**
         * 
         *  Takes single CSV line and seperates values in vector
         *  Also sanitizes quotation marks from output vector
         *  Inputed as "item1, "item2", etc 
         *  Outputed as vector([0]: item1, [1]: item2, [2]: etc)
         * @param line file line inputed to parse
         * @return vector of strings that are parsed 
         */
        vector<string> parseCSVLine(const string &line);

        /**
         * 
         *  getter for our graph "map" containing just nodes of airporst
         * @return map of airports 
         */
        map<string, Airport> getMap();

        /**
         * 
         * getter for our graph data structure 
         * @return unorder map of ints to routes 
         */
        unordered_map<int, Route> getGraph();

        /**
         * 
         * getter for our map of nodes
         * @return map of airports with its codes
         */
        unordered_map<string, Node> getNodes();

        /**
         * 
         * getter for list of airport codes
         * @return vector of airport codes
         */
        vector<string> getAirports();

        /**
         * 
         * getter for routes
         * @return vector of Routes object
         */
        vector<Route> getRoutes();

        /**
         * 
         * getter for all nodes
         * @return vector of Nodes
         */
        vector<Node> getDests();


    private:
        string airportFile_;
        string routeFile_;
        map<string, Airport> map_;
        unordered_map<int, Route> graph_;
        vector<string> airports_;
        vector <Node> dests_;
        vector<Route> routes_;
        unordered_map<string, Node> nodes_;
};