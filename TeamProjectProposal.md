# Team Final Proposal
## How can we make air travel more efficient?
We hope to find the smallest path between airports which can be covered by airplanes using graphical algorithms and use this  
data to hopefully make air travel more efficient. We also plan on finding important hub locations for airports which should   
be given emphasis to by airlines using these airports.

## Data Set
We plan on using the [OpenFlights](https://openflights.org/data.html) dataset to find the data on airlines and routes of airplanes  
and use this data to find the shortest path as well as important airports. We will download the data as a CSV file and plan on storing and  
using the data as a CSV file as well. We will make a class containing the airports to store the  
data from the dataset. If any information is missing we will give it a default value. For example, if it is an integer, float, etc. 
we will give it a value of -1 and use absolute values for distance throughout the program and for strings or chars we  
will give them a default empty character value. We will store the airports in a graph connecting them to each other according  
to the routes. We will be storing the Index Number, Name of the Airport, City, Country, ICAO, Latitude, Longitude. Routes will  
serve as our edges for our graph. An edge in our graph is defined as a route if it exists from Airport A to Airport B  
given that an airplane from the dataset has this as its beginning and end airport respectively.
  
## Graph Algorithms
We plan on implementing BFS order traversal for traversing through our graph. We will be using Dijkstra’s Algorithm to find the shortest  
paths between airports. We plan on converting the points of the airports on the earth from latitude  
and longitude into km distances between the airports using [great circle distance](https://en.wikipedia.org/wiki/Great-circle_distance).  
We will find the central angle between two points using their latitude and longitude using ![image](https://media.github-dev.cs.illinois.edu/user/13000/files/fd0acf5e-1a4b-4fd8-877c-f06e9142dd4d)

We will then find the distance between the two points using the central angle by converting it into km using ![image](https://media.github-dev.cs.illinois.edu/user/13000/files/8782b45e-7bc4-4eb0-a3d5-45712d02bd32)
and using these distances as weights for our graph. We will then use these airports as input and get the remaining data from the graph nodes  
using getters of the airport class if needed. The output of the Dijkstra's algorithm will be the shortest route and the output of the Betweennes Centrality algorithm  
will be the shortest unweighted path between two nodes which we can use to find the estimated shortest route between the airports. We will make  
any changes necessary project as seen needed.  

We will find and suggest a suitable hub for airlines using Betweenness Centrality to find the central airports in each route for allocating resources   
like building maintanence bases and upgrading terminals to make air travel more efficient. Betweenness Centrality will be used to find the airports  
most central to our routes between airports and these airports are suggested to be made into hubs for efficient travel. [Betweenness centrality](https://www.cl.cam.ac.uk/teaching/1718/MLRD/handbook/brandes.html) will  
also take in airports as input and will return the central airport to the route between the airports given as input for its output.  
  
## Runtimes
BFS traversal - O(V+E).  
Dijkstra's Algorithm - O(V^2).  
Betweenness Centrality Algorithm - O(VE).  

## Timeline
Data Acquisition - 15th November  
Data Processing - 20th November  
Completion of BFS - 1st December  
Completion of Each Dijkstra's Algorithm - 1st December  
Completion of Betweenness Centrality - 1st December  
Functional Code - 8th December  
Written Report of Project - 10th December  
Project Dememonstration Video - 10th December  
