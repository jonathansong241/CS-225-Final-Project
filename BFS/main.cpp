#include <vector>
#include <string>
#include <algorithm>
#include "include/bfs.hpp"
using std::string;
using std::cout;
using std::endl;

int main() {
    BFS bfs("BFS/tests/airports_20.dat", "BFS/tests/routes_20.dat");
    string input = "Chicago";
    vector<string> trav = bfs.BreadthFS(input);
    for (int i = 0; i < trav.size(); i++) {
        cout << trav[i] << endl;
    }
}
