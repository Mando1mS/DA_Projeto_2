


#include "../include/Graph.h"

using namespace std;
Graph::Graph() {}

void Graph::setUnvisited() {
    for(auto &it: nodes) {
        it.second.visited = false;
    }
}

void Graph::addNode(const std::string &id,string label) {
    auto find=nodes.find(id);
    if(find==nodes.end())
    {
        nodes.insert({ id, { id,{},{"",""},label,false}});//n
    }
}


void Graph::addNode(const std::string &id,std::string lng, std::string lat)
{
    auto find=nodes.find(id);
    if(find==nodes.end())
    {
        nodes.insert({ id, { id,{},{lng,lat},"",false}});//n
    }
}
void Graph::addEdge(const std::string &id_source, const std::string &id_target,std::string &dist)
{
    auto source = nodes.find(id_source);
    auto target = nodes.find(id_target);
    if(source == nodes.end() || target == nodes.end() || source == target) return;
    source->second.adj.push_back({id_target,dist});
}




