


#include "../include/Graph.h"

using namespace std;
Graph::Graph() {}

void Graph::setUnvisited() {
    for(auto &it: nodes) {
        it.second.visited = false;
    }
}

void Graph::addNode(const int &id,string label) {
    auto find=nodes.find(id);
    if(find==nodes.end())
    {
        nodes.insert({ id, { id,{},{"",""},label,false}});//n
    }
}


void Graph::addNode(const int &id,std::string lng, std::string lat)
{
    auto find=nodes.find(id);
    if(find==nodes.end())
    {
        nodes.insert({ id, { id,{},{lng,lat},"",false}});//n
    }
}


void Graph::addEdge(const int &id_source, const int &id_target,const double &dist)
{
    auto source = nodes.find(id_source);
    auto target = nodes.find(id_target);
    if(source == nodes.end() || target == nodes.end() || source == target) return;
    source->second.adj.push_back({id_target,dist,false});
}

double Graph::HasEdge(const int &id_source, const int &id_target)
{
    for(auto edge: nodes.find(id_source)->second.adj)
    {
        if(edge.dest==id_target)
        {
            return edge.dist;
        }
    }
    return 0.0;
}




