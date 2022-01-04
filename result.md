# Final Project Result


## Overview <br/>
We successfully implemented our traversals and algorithms based on Open Flights data sets within our project.<br/>
Additionally, our code is a solution to our leading question: What is the fastest path between two airports based on the Open Flights dataset.<br/>
Our project also has real life application such as finding the distance between two places given their coordinates and it isn't limited to just planes and their routes. Our code is also flexible and by changing a bit of code in our parsing, it's able to determine distances from different datasets as long as there's coordinates.
Our project is evidence of our team's learning and application of concepted learned throughout the semester such as graphs, cleaning, parsing data, and writing test suites.

## Parsing <br/>
Dataset was two CSV files one for airports and one for airplane routes.
We created routes, airports and map classes for our future implementation.
For example, airports contain its ID, Name, City, Country, IATA, ICAO, Latitude, Longitude, Altitude, Timezone, DST, Type, and Source.
Routes contain its Airline, Airline ID, Soure Airport, Source AIrport ID, Destination Airport, Destination Airport ID, Codeshare, Stops, and  Equipment.<pr/>

At first we loads CSV Data into a graph implementation where airports are nodes and routes are edges, then parsing special characters with certain attributes and use variables to store them.<br/>
After that we use exisiting airports and routes vectors to create a weighted graph based on their distance and airport codes.<pr/>

If we 
We wrote test cases for parsing and all tests passed.<br/>
![image](https://media.github-dev.cs.illinois.edu/user/12055/files/cf5b15f1-ca93-4649-925c-f4e5f202bc08)


## Betweenness Centrality <br/>
For the betweenness centrality algorithm, we included similar graphs,
involving cycles for additional complexity. The betweenness centrality function takes in a vertex
and returns an int representing the number of paths going through that vertex, so we needed to
make sure the functionality does not vary between different types of graphs. More detailed
information regarding this test is found in the test file for Betweeness Centrality



## BFS<br/>
BFS function takes in the starting node as input, then after traversing the graph, it will return a vector of string that contains the nodes in the order they were visited.<br/>

To implement the function, we first created a helper function to generate the adjacency list of the graph. It’s a map from each node to its neighbors. In the BFS algorithm, I used a queue to store and pop each visited nodes. While the queue is not empty, we pop a node from the queue then get its neighbors from adjacency list. We add each of these neighbors to the queue if they have not been visited. Then mark them as visited.
Finding the adjacency list of the graph helps us get the adjacent nodes quickly, and marking node as visited or not could let us avoid visiting and storing duplicate nodes.<br/>

If we use small sample to call BFS function, we can see that from ORD airports, we will traverse all the nodes in the order they were visited. <br/>
![image](https://media.github-dev.cs.illinois.edu/user/12055/files/6150e8c5-c4d8-4983-a4e9-7319ab6e5aa0)



For the **test** part, since the Open Flights data files are too big to test, what we did was create 2 small data samples. Then we called my BFS function on these 2 samples. We tested the size of the returned vectors, the airports in vectors or not and the order of the output. All test cases have passed.
![image](https://media.github-dev.cs.illinois.edu/user/12055/files/e307066b-68eb-4027-9fa7-d307e4a82688)




## Dijkstras<br/>
Dijkstras function, for its input, takes in the Map object (the graph) as well as the starting and destination airport as a string (airport code). It returns a vector of airports which is in order for the path. It also keeps track of the distance traveled as an integer which can be accessed with the getMinDist function.

To implement the function, we first had to create a new node structure called D_Node. In D_Node we stored the tentative distance, the airport as well as an index (int). We first had the constructor fill out a map for d_node structure which was used in traversing through the nodes. We also used the node structure from Map.h to find all the edges for each route which had the origin as the source airport so that we could find all the neighboring nodes.

Furthermore, we used a binary heap priority queue to go through the neighborhood. We traversed the neighbor for each node and took the path with the shortest tentative distance and return the path as well as calculate the total distance for the path.

For testing, we tested the helper functions as well as the new D_Node structure. We also printed out the neighboring values as well as the D_Node structures of the total dataset.

## Dijkstras<br/>
Dijkstras function, for its input, takes in the Map object (the graph) as well as the starting and destination airport as a string (airport code). It returns a vector of airports which is in order for the path. It also keeps track of the distance traveled as an integer which can be accessed with the getMinDist function.

To implement the function, we first had to create a new node structure called D_Node. In D_Node we stored the tentative distance, the airport as well as an index (int). We first had the constructor fill out a map for d_node structure which was used in traversing through the nodes. We also used the node structure from Map.h to find all the edges for each route which had the origin as the source airport so that we could find all the neighboring nodes.

Furthermore, we used a binary heap priority queue to go through the neighborhood. We traversed the neighbor for each node and took the path with the shortest tentative distance and return the path as well as calculate the total distance for the path.

For testing, we tested the helper functions as well as the new D_Node structure. We also printed out the neighboring values as well as the D_Node structures of the total dataset.

![image](https://media.github-dev.cs.illinois.edu/user/13000/files/bea81109-3273-40e5-b814-558b86c30d93)
![image](https://media.github-dev.cs.illinois.edu/user/13000/files/6b93d783-b7a9-4105-b171-fe0d9e0f1133)



