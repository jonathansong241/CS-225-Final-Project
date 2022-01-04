#include "include/map.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main() {
    string node_file = "../data/airports.dat";
    string edge_file = "../data/routes.dat";

    Map map(node_file, edge_file);
    // string input = "3550, \"George Bush Intercontinental Houston Airport\",\"Houston\",\"United States\",\"IAH\",\"KIAH\",29.984399795532227,-95.34140014648438,97,-6,\"A\",\"America/Chicago\",\"airport\",\"OurAirports";
    // vector<string> test = map.parseCSVLine(input);

    // cout<< test.at(3) << endl;

    map.insertAirports();
    for (int i = 0; i < 5; i++) {
        cout << map.getAirports().at(i) << endl;
    }

    map.insertFlights();
    Route r = map.getRoutes()[0];
    cout << r.getOrigin() << " " << r.getDest() << endl;

    return 0;
}