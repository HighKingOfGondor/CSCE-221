// please implement it
#include "Graph.hpp"

void Graph::buildGraph()
{
    int vnumber = 0, enumber = 0;
    bool marker = false;
    inputFile.open("input.data");
    if (!inputFile)
        throw runtime_error("No file! ");
    while(!inputFile.eof())
    {
        inputFile >> vnumber;
        Vertex v(vnumber, marker);
        while (inputFile >> enumber)
        {
            if(enumber == -1)
                break;
            v.connectTo(enumber);
        }
        vertices.push_back(v);
    }
    inputFile.close();
}

void Graph::displayGraph()
{
    for (Vertex i : vertices)
    {
        cout << i.label << " is connected to: ";
        for(Edge e : i.edgeList)
        {
            cout << e.end << " ";
        }
        cout << endl;
    }
    cout << "Contents of sorted: ";
    for (int i = sorted.size() - 1; i >= 0; i--)
        cout << sorted[i].label;
}

void Graph::dfs_search(Vertex& vert_num)
{
    vert_num.marker = true;
    for(Edge v : vert_num.edgeList)
    {
        if (vertices[v.end-1].marker == false)
            dfs_search(vertices[v.end - 1]);
        for(int i = 0; i <sorted.size(); i++)
        {
            if(sorted[i].label == vert_num.label)
                throw runtime_error("No topological sort!!");
        }
    }
    sorted.push_back(vert_num);
}

void Graph::dfs_visit(Vertex start)
{
    for(Vertex v : vertices)
    {
        if(v.marker == false)
            dfs_search(v);
    }
}