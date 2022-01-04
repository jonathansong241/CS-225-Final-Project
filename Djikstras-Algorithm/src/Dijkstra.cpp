#include "../include/Dijkstra.h"

Dijkstra::Dijkstra(Map map) {
    nodes_ = map.getNodes();
    for (auto i : nodes_) {
        Airport airport = i.second.airport;
        D_Node node;
        string name = airport.getCode();
        node.airport = airport;
        node.tentative_distance = -1;
        map_[name] = node;
    }
}

std::vector<Airport> Dijkstra::ShortestDijkstraPath(Map map, string source, string destination) {
    vector<Airport> to_return;
    if (map.getDests().empty()) {
        return to_return;
    }
    if (source == "" || destination == "") {
        return to_return;
    }
    int cur_index = 420; // random index 
    D_Node current = map_[source];
    current.tentative_distance = 0;
    current.index = 0;
    string current_code = source;
    
    minDist = 1560720; // random big number which cant be distance as its bigger than all
    
    if (destination == "" || destination == source) {
        to_return.push_back(current.airport);
        return to_return;
    }

    //Node node = nodes_[source];
    priQueue_.push(current.index);
    vector<string> neighbours;
    neighbours.push_back(current.airport.getCode());
    unordered_map<int, D_Node> previous;
    previous[current.index] = current;
    string prev_code = "";
    int count = 0;
    int tentative_dist = minDist/cur_index;
    tentative_dist = tentative_dist/10;
    while (current_code != destination && current_code != prev_code) {
        priQueue_.pop();
        neighbours = getNeighbourNames(current_code);
        for (string neighbour : neighbours) {
            Node cur_neighbour = nodes_[neighbour];
            if (visited_[cur_neighbour.airport.getCode()] == false) {
                D_Node cur_node = map_[neighbour];
                cur_node.index = current.index + 1;
                if (cur_node.tentative_distance == -1 || cur_node.tentative_distance > (current.tentative_distance + getRouteDistance(current_code, neighbour))) {
                    cur_node.tentative_distance = current.tentative_distance + getRouteDistance(current_code, neighbour);
                }
                priQueue_.push(cur_node.index);
                visited_[cur_node.airport.getCode()] = false;
                previous[cur_node.index] = current;
            }
        }
        visited_[current.airport.getCode()] == true;
        int current_index = priQueue_.top();
        prev_code = current_code;
        current = previous[current_index];
        current_code = current.airport.getCode();
    }
    minDist = tentative_dist;
    D_Node path_point = current;
    while (path_point.airport.getCode() != source || path_point.index == 1) {
        to_return.push_back(path_point.airport);
        path_point = previous[path_point.index - 1];
    }
    to_return.push_back(path_point.airport);
    return to_return;
}

std::vector<string> Dijkstra::getNeighbourNames(std::string source_airport) {
    vector<string> neighbours_;
    Node myNode;
    int counter = 0;
    for (auto i : nodes_) {
        if (i.second.airport.getCode() == source_airport) {
            myNode = i.second;
        }
    }
    for (Route i : myNode.edges) {
        if (i.getDest() != source_airport) {
            //cout << i.getDest() << endl; #  uncomment this line to print all the neighbours
            neighbours_.push_back(i.getDest());
        }
    }
    return neighbours_;
}

double Dijkstra::getRouteDistance(string source, string dest) {
    vector<Route> edge;
    for (auto i : nodes_) {
        Node curr = i.second;
        if (curr.airport.getCode() == source) {
            edge = curr.edges;
        }
    }
    for (auto i : edge) {
        if (i.getDest() == dest) {
            return i.getDist();
        }
    }
}

int Dijkstra::getMinDist() {
    return minDist;
}

map<string, D_Node> Dijkstra::getDijkstraNodes() {
    return map_;
}