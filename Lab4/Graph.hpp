#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

#include "Vertex.hpp"

using namespace std;

class Graph {
public:
    // we use a vector to store vertices in the graph
    // and use label (int) to be a subscript to access a vertex
    fstream inputFile;
    vector<Vertex> vertices;
    vector<Vertex> sorted;
    Graph(string inputPath) : inputFile(inputPath) {}
    // build a graph according to the input file
    void buildGraph();
    // display the graph
    void displayGraph();
    
    void dfs_search(Vertex&);
    void dfs_visit(Vertex);
    
    friend class Vertex;
};

#endif /* Graph_hpp */
