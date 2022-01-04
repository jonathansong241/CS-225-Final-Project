#pragma once

using namespace std;
#include "../parsing/include/airport.h"
#include "../parsing/include/map.h"
#include "../Djikstras-Algorithm/include/Dijkstra.h"
#include <string>
#include <vector>

class BetweennessCentrality {

    public:
        BetweennessCentrality();
        int FindCentrality(Node airport, Map map);

    private:

};