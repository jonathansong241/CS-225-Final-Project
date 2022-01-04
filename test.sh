#!/bin/bash

# This is a shell script to run all tests sequentially.

TEST_PARSING="test-parsing"
TEST_BFS="test-bfs"
TEST_BC="test-bc"
TEST_DIJKSTRA="test-dijkstra"

# uncomment to run parsing test
echo "Testing Parsing" # "Print Testing Parsing"
cd parsing/ # Go into parsing/
./$TEST_PARSING # Run $TEST_PARSING
cd .. # Go into ../


# uncomment to run BFS test
#echo "Testing BFS"
#cd BFS/
#./$TEST_BFS
#cd ..

# uncomment to run BC test
#echo "Testing BC"
#cd BC/
#./$TEST_BC
#cd ..

# uncomment to run Dijkstras test
#echo "Testing Dijkstras"
#cd Djikstras-Algorithm/
#./$TEST_DIJKSTRA
#cd ..