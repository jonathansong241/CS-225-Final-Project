#include "../include/map.h"
//  Constructor
Map::Map(const string &airportFile, const string &routeFile) {
    // copy files to private members
    airportFile_ = airportFile;
    routeFile_ = routeFile;
    constructMap();
}

//  constructor helper
//  creates graph containing Airports and Flights
void Map::constructMap(){
    insertAirports();
    insertFlights();
    createHub();
}


//  adds airports to map
void Map::insertAirports() {
    
    ifstream infile(airportFile_.c_str());
    string lines;

    // Seperates each line into vectors, and puts airport onto map
    while(getline(infile, lines)) {
        vector<string> line = parseCSVLine(lines);
        Node node = Node();
        Airport in_airport = Airport();
        in_airport.setCode(line[AIRPORT_IATA].c_str());
        in_airport.setLatitude(atof(line[AIRPORT_LATITUDE].c_str()) );
        in_airport.setLongitude(atof(line[AIRPORT_LONGITUDE].c_str()) );
        string code = line[AIRPORT_IATA].c_str();
        transform(code.begin(), code.end(), code.begin(), [](unsigned char c){return toupper(c); });
        
        node.airport = in_airport;

        nodes_[code] = node;
        dests_.push_back(node);
        airports_.push_back(code);

    }
    
    infile.close();
}


//  adds flights connecting airports on map
void Map::insertFlights() {
    ifstream infile(routeFile_.c_str());
    string lines;
    
    getline(infile, lines);
    
    while(getline(infile, lines)) {
        vector<string> line = parseCSVLine(lines);
        ////////////////////////////////////
        string origin = line[ROUTE_ORIGIN].c_str();
        string dest = line[ROUTE_DESTINATION].c_str();
        GCD gcd = GCD();
        double weight = gcd.great_circle_distance(map_[origin].getLatitude(), map_[origin].getLongitude(),
                map_[dest].getLatitude(), map_[dest].getLongitude());

        Route flight(origin, dest, weight);
        routes_.push_back(flight);
        
        ////////////////////////////////////////////////////
    }
    infile.close();
}

vector<string> Map::parseCSVLine(const string &line) {
    char current;
    bool isQuote = false;
    string builtStr = "";
    vector<string> outputStrings;

    for(size_t i = 0; i < line.size(); ++i) {
        current = line[i];
        if(!isQuote) {
            if(current == ',') {
                outputStrings.push_back(builtStr);
                builtStr = string();
            }
            else if(current == '"')
                isQuote = true;
            else
                builtStr += current;
        }
        else {
            if (current == '"' && i+1 < line.size()) {
                if (line[i+1] == '"') {
                    builtStr += '"';
                    ++i;
                }
                else
                    isQuote = false;
            }
            else
                builtStr += current;
        }
    }
    return outputStrings;
}

map<string, Airport> Map::getMap() {
    return map_;
}

unordered_map<int, Route> Map::getGraph() {
    return graph_;
}


void Map::createHub() {
    vector <Node> iter = getDests();
    vector<Route> routes = getRoutes();
    for (auto i : iter) {
        for (auto j : routes) {
            if (j.getOrigin() == (i.airport.getCode())) {
                i.edges.push_back(j);
            }
            if (j.getDest() == (i.airport.getCode())) {
                i.edges.push_back(j);
            }
        }
        
    }
}

unordered_map<string, Node> Map::getNodes() {
    return nodes_;
}

std::vector<string> Map::getAirports() {
    return airports_;
}

vector<Route> Map::getRoutes() {
    return routes_;
}

vector<Node> Map::getDests() {
    return dests_;
}