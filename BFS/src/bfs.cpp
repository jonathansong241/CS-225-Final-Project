#include "../include/bfs.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using std::string;
using std::vector;
using std::map;
using std::queue;
using std::cout;
using std::endl;


BFS::BFS(const string &airportFile, const string &routeFile) : graph_(airportFile, routeFile) {
    getAdjacent(adj_);
}
void BFS::getAdjacent(map<string, vector<string>>& adj) {
    for(auto e : graph_.getRoutes()) {
        // if e.start is in adj
        if(adj.find(e.getOrigin()) != adj.end()) {
            adj[e.getOrigin()].push_back(e.getDest());
        } else {
            // creat new empty vector if the node has not been seen before
            adj[e.getOrigin()] = std::vector<string>();
            adj[e.getOrigin()].push_back(e.getDest());
        }
        
    }
}
vector<string> BFS::BreadthFS(string start) {
    map<string, bool> visited;
    vector<string> trav;
    //Initially all the nodes as non-visited.
    for(string node : graph_.getAirports()) {
        visited[node] = false;
    }
    queue<string> q;
    q.push(start);
    visited[start] = true;

    //When it's not empty
    while(!q.empty()) {
        string temp = q.front();
        trav.push_back(temp);
        q.pop();
        // add neighbors to q
        for(size_t i = 0; i < adj_[temp].size(); i++) {
            if(visited[adj_[temp][i]] != true){
                q.push(adj_[temp][i]);
                visited[adj_[temp][i]] = true;
            }
        }
    }
    return trav;
}