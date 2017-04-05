//
//  main.cpp
//  Wheeler-Jared-A4
//
//  Created by Jared Wheeler on 7/31/16.
//  Copyright (c) 2016 Jared Wheeler. All rights reserved.
//
#include <fstream>
#include <iostream>
#include "Graph.hpp"
#include "Edge.hpp"
#include "Vertex.hpp"


int main()
{
    try
    {
        Graph g("input2.data");
        g.buildGraph();
        g.dfs_visit(g.vertices[0]);
        g.displayGraph();
        /*
        Graph g2("input2.data");
        g2.buildGraph();
        g2.dfs_visit(g.vertices[0]);
        g2.displayGraph();
        Graph g3("input3.data");
        g3.buildGraph();
        g3.dfs_visit(g.vertices[0]);
        g3.displayGraph();
         */
    }
    catch(exception &e)
    {
        cerr << "Issue! " << e.what();
    }
    catch(string e)
    {
        cerr << "Issue! " << e;
    }
    catch(...)
    {
        cerr << "Issue! Not identified! ";
    }
}
