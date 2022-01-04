#include "../BC/includes/betweennesscentrality.h"

BetweennessCentrality::BetweennessCentrality() {

}

int BetweennessCentrality::FindCentrality(Node airport, Map map) {

    vector<Node> nodes = map.getDests();
    unordered_map<Node, int> dict_of_measures;

    for(unsigned i = 0; i < nodes.size()-1; i++){
        for(unsigned j = i+1; j < nodes.size(); j++){
            Dijkstra dj = Dijkstra(map);
            vector<Airport> path = dj.ShortestDijkstraPath(map, nodes[i].airport.getCode(), nodes[j].airport.getCode());   
            vector<Airport> reversePath = dj.ShortestDijkstraPath(map, nodes[j].airport.getCode(), nodes[i].airport.getCode());
            if (path.size() > 2) {
                for(unsigned k = 1; k < path.size()-1; k++){
                    dict_of_measures[path[k]] = dict_of_measures[path[k]] + 1; 
                }
            }
            if (reversePath.size() > 2) {
                for(unsigned k = 1; k < reversePath.size()-1; k++){
                    dict_of_measures[reversePath[k]] = dict_of_measures[reversePath[k]] + 1;
                }
            }
        }
    }

    return dict_of_measures[airport];

}