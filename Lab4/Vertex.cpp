// please implement it

#include "Vertex.hpp"

void Vertex::connectTo(int end)
{
    Edge e(label, end);
    edgeList.push_back(e);
}
