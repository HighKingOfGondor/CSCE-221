#ifndef Edge_hpp
#define Edge_hpp

#include <stdio.h>

class Edge {
public:
    // start vertex's label
    int start;
    // end vertex's label
    int end;
    bool marker;
    int get_edge() {return end;}
    Edge(int start, int end) : start(start), end(end) {}
};

#endif /* Edge_hpp */

