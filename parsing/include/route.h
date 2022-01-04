#pragma once
#include <string>
#include <limits.h>

using namespace std;

enum routeCSVMeanings {
    ROUTE_AIRLINE,
    ROUTE_AIRLINEID,
    ROUTE_ORIGIN,
    ROUTE_ORIGINID,
    ROUTE_DESTINATION,
    ROUTE_DESTINATIONID
};


class Route {
    public:

        /**
         * Constructor to initialize Route Class
         * @param o origin
         * @param de destination
         */
        Route(string o, string de);

        /**
         * Constructor to initialize Route Class
         * @param o origin
         * @param de destination
         * @param di distance
         */
        Route(string o, string de, double di);

        /**
         * 
         *  getter for origin airport code
         */
        string getOrigin();

        /**
         * 
         *  getter for destination airport code
         */
        string getDest();

        /**
         * 
         *  getter for distance calculated
         *  @return distance
         */
        double getDist();

        /**
         *  distance setter
         *  @param di distance
         */
        void setDist(double di);

        /**
         * 
         *  Operator overload function for comparing routes
         *  which compares the weight of edges
         * @param other compared route
         * @return too see which is heavier
         */
        bool operator<<(const Route& other) const;

        /**
         * 
         *  Operator overload for comparing the routes
         *  @param other compared route
         *  @return to see if it is the same route
         */
        bool operator==(Route& other) const;
    
    private:
        string origin;  
        string dest;    
        double dist; 
};