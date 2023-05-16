


#include "../include/Graph.h"

using namespace std;
Graph::Graph() {}

void Graph::setUnvisited() {
    for(auto &it: nodes) {
        it.second.visited = false;
    }
}

void Graph::addNode(const int &id) {
    nodes.insert({ id, { id,{},false}});//n
}

void Graph::addEdge(const int &id_source, const int &id_target,double dist)
{
    auto source = nodes.find(id_source);
    auto target = nodes.find(id_target);
    if(source == nodes.end())
    {
        addNode(id_source);
    }
    if(target == nodes.end())
    {
        addNode(id_target);
    }
    source->second.adj.push_back({id_target,dist});
}




