#!/bin/bash

# This is a shell script to help user run everything for the main method.

MAIN="BFS/main.cpp"

cd BFS/
./main.cpp "$@"
cd ..
./$MAIN