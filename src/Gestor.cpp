
#include "../include/Gestor.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <set>

using namespace std;

Gestor::Gestor(string fich) {
    graph_=new Graph();
    LerFicheiros(fich);
}

Gestor::Gestor(string fich,string fich2) {
    graph_=new Graph();
    LerFicheiros(fich,fich2);
}
void Gestor::LerFicheiros(std::string fich) {
    std::ifstream input(fich);
    std::string line;
    //passar a primeira linha á frente pois tem dados desnecessários.
    getline(input, line);
    while(getline(input, line)) {//n^2
        std::stringstream ss(line);

        std::string source, target, dist,trec,label1,label2;

        getline(ss, source, ',');//n
        getline(ss, target, ',');
        getline(ss, dist, ',');
        if (ss >> trec) {
            // Handle the case with labels
            getline(ss, label1, ',');
            getline(ss, label2, '\r');
            graph_->addNode(source,label1);
            graph_->addNode(target,label2);
        } else {
            // Handle the case without labels
            getline(ss, dist, '\r');
            graph_->addNode(source);
            graph_->addNode(target);
        }
        graph_->addEdge(source,target,dist);
        graph_->addEdge(target,source,dist);
    }
}

void Gestor::LerFicheiros(std::string fich,std::string fich2) {
    std::ifstream input_nodes(fich);
    std::ifstream input_edges(fich2);
    std::string line;
    //passar a primeira linha á frente pois tem dados desnecessários.
    getline(input_nodes, line);
    getline(input_edges, line);
    while(getline(input_nodes, line)) {//n^2
        std::stringstream ss(line);

        std::string source, lng, lat;

        getline(ss, source, ',');//n
        getline(ss, lng, ',');
        getline(ss, lat, '\r');
        graph_->addNode(source,lng,lat);
    }
    while(getline(input_edges, line))
    {
        std::stringstream ss(line);
        std::string source, target, dist;

        getline(ss, source, ',');//n
        getline(ss, target, ',');
        getline(ss, dist, '\r');
        graph_->addEdge(source,target,dist);
        graph_->addEdge(target,source,dist);
    }
}
void Gestor::MostrarEstacoes() {
    for(auto node:graph_->nodes)
    {
        cout << left << setw(6) << "Source: " << setw(40) << node.first << "\n";
    }
}