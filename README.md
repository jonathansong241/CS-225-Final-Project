# CS 225 Final Project repository

## Contributors: Jonathan Song, Jinyu Ding, Ishan Khandelwal, Brendan Yim  
  
## Deliverables:
[presentation slides](https://docs.google.com/presentation/d/1Unx3Jza-Wm0rz6YRHsJB6Ez24I4EbsE4anKC6dMCe3g/edit?usp=sharing)

## Introduction
Our final project uses OpenFlights airports and routes data sets to construct a graph of airport vertices. BFS algorithm helps to traverse the graph with a specific starting airport. Djikstra algorithm is used to find the shortest path between two airports. Betweenness contrality algorithm is used to find the centrality degree for the each airport  
node.

## File description 
### data
Flies: `airports.dat`, `routes.dat`<br/>
Description: The airports and routes data sets from the Open Flights.
### Parsing
Files: `map.h/cpp` , `Airport.h/cpp`, `route.h/cpp`<br/>
Description: Created Parsing function to split the given dataset lines from the OpenFlight file datasets and used comas as delimeter and elimiated unnessary quotations. Map class serves as a graph connection for nodes and edges and collberates between other algrothims. Nodes and Edges are also made up of the Airports and Route class respectively. We also use a struct as Node to serve for the Airport connecting the hubs for the edges. 


### Breadth First Search (BFS)
Files: `BFS.h/cpp` <br>
Description: Implement the function to perform Breadth First Search on the graph with airports as vertices and routes as edges.

### Dijkstra Algorithm
Files: `Djikstras-Algorithm.h/cpp`

For each dataset/graph, create a new Dijkstras object with the constructor and input data (Map object(graph) using fileio, strings for source and destination). The test cases test the distance function and you can print out neighboring nodes as well as the path. The getMinDist function and  ShortestDijkstraPath will return the distance as an integer and shortest path of Airport objects for you. 

### Betweenness Centrality Algorithm
Files: `BC.h/cpp` <br>
Similar to Djikstra's, create a betweenness centrality object using the constructor and then run the main command FindCentrality() which will take in the airport and graph (Map object) and find the centrality of the airport to the graph. The test case checks the centrality of the airport. There is only one function in centrality and it makes use of Dijkstra's to find the paths.   

## Run the project
All testing and running of our code can be done within the individual test case files, located in tests/test.cpp under each algorithms folder. The sample dataset used for testing can be found in tests folders under each algorithm. 

To compile our project, you can run the following commands: <pr>
  
  
`cmake3 .`
  
`make`
 
  
You can run the following commands to run our test cases:<pr>


`./test.sh`


If you want to test one or several specific algoritms' test, just go to `test.sh` and comment out those part and do the steps above again.

## Acknowledgment
Thanks to Benjamin for being an amazing CA and helping us with this project
