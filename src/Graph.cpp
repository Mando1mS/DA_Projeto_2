


#include "../include/Graph.h"

using namespace std;
Graph::Graph() {}

void Graph::setUnvisited() {
    for(auto &it: nodes) {
        it.second.visited = false;
    }
}

void Graph::addNode(const std::string &id) {
    nodes.insert({ id, { id,{},false}});//n
}

void Graph::addEdge(const std::string &id_source, const std::string &id_target,std::string dist)
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




