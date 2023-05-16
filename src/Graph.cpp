

#include "../../../../Desktop/DA_Projeto_2/include/Graph.h"
using namespace std;
Graph::Graph() {}

void Graph::setUnvisited() {
    for(auto &it: nodes) {
        it.second.visited = false;
        it.second.path.clear();
        it.second.travel_from_src.clear();
    }
    shortestpaths_.clear();
}

void Graph::addNode(const std::string &nome_estacao, const Estacao &estacao) {
    nodes.insert({ nome_estacao, { estacao,{},false,list<list<pair<Estacao,string>>>()}});//n
}

void Graph::addEdge(const std::string &source_estacao, const std::string &target_estacao,int cap,
                    const std::string &tipo)
{
    auto source = nodes.find(source_estacao);
    auto target = nodes.find(target_estacao);
    if(source == nodes.end() || target == nodes.end() || source == target) return;
    source->second.adj.push_back({target_estacao,tipo,cap});
}


int Graph::getNumEstacoes() const{
    return nodes.size();
}

void Graph::bfs(const std::string &nome_estacao) {
    setUnvisited();

    std::queue<std::string> q; // queue of unvisited nodes
    q.push(nome_estacao);
    nodes.at(nome_estacao).visited = true;
    nodes.at(nome_estacao).travel_from_src.push_back({ { nodes.at(nome_estacao).estacao, "" } });

    while(!q.empty()) {
        std::string u = q.front();
        q.pop();
        Node& node = nodes.at(u);
        for(const auto &e: node.adj) {
            std::string w = e.dest;

            if(!nodes.at(w).visited) {
                q.push(w);
                nodes.at(w).visited = true;
                for(auto n: node.travel_from_src) {
                    n.push_back({nodes.at(w).estacao, e.serv});
                    nodes.at(w).travel_from_src.push_back(n);
                }
            }
            else if (node.travel_from_src.front().size()+1==nodes.at(w).travel_from_src.front().size()){
                bool flag = true;
                for (auto n : nodes.at(w).travel_from_src) { //if all possibilities wanted comment this for loop
                    auto it = n.end();
                    std::advance(it,-2);
                    if (it->first==node.estacao) {
                        flag= false;
                        break;
                    }
                }
                if (!flag) continue;
                for(auto n: node.travel_from_src) {
                    n.push_back({nodes.at(w).estacao,e.serv});
                    nodes.at(w).travel_from_src.push_back(n);
                }
            }
        }
    }
}

int Graph::maxFlow(string nome_estacaoA, string nome_estacaoB) {
    queue<string> q;
    setUnvisited();
    int maxflow = 0;
    q.push(nome_estacaoA);

    while(!q.empty()) {
        string node = q.front();
        q.pop();
        auto neighbour= nodes.at(node);

        for(auto u=neighbour.adj.begin(); u!=neighbour.adj.end(); u++) {
            auto newnode=u->dest;
            int res_cap = u->cap - u->flow;

            if(!nodes.at(newnode).visited && res_cap > 0) {
                int newflow = min(u->flow + res_cap, res_cap);  //compare initial flow
                nodes.at(newnode).visited=true;
                nodes.at(newnode).parent = node;

                if(newnode == nome_estacaoB) {
                    string cur = nome_estacaoB;
                    while (cur != nome_estacaoA) {
                        string parent = nodes.at(cur).parent;
                        auto i = nodes.at(cur).adj.begin();
                        while (i != nodes.at(cur).adj.end() && i->dest != parent) {
                            i++;
                        }
                        if(i != nodes.at(cur).adj.end()) {
                            i->flow += newflow;
                        }
                        i = nodes.at(parent).adj.begin();
                        while (i != nodes.at(parent).adj.end() && i->dest != cur) {
                            i++;
                        }
                        if(i != nodes.at(parent).adj.end()) {
                            i->flow -= newflow;
                        }
                        cur = parent;
                    }
                    maxflow += newflow;
                    setUnvisited();
                    q.push(nome_estacaoA);
                    nodes.at(nome_estacaoA).visited = true;
                    return maxflow;
                }
                else {
                    q.push(newnode);
                }
            }
        }
    }
    return maxflow;
}
