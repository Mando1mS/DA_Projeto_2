
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
    graph_->setUnvisited();
}

Gestor::Gestor(string fich,string fich2) {
    graph_=new Graph();
    LerFicheiros(fich,fich2);
    graph_->setUnvisited();
}
void Gestor::LerFicheiros(std::string fich) {
    std::ifstream input(fich);
    std::string line;
    //passar a primeira linha á frente pois tem dados desnecessários.
    getline(input, line);
    while(getline(input, line)) {//n^2
        std::stringstream ss(line);
        int src,trg;
        double dis;
        std::string source, target, dist,trec,label1,label2;

        getline(ss, source, ',');//n
        getline(ss, target, ',');
        getline(ss, dist, ',');
        src=stoi(source);
        trg=stoi(target);
        dis=stod(dist);
        if (ss >> trec) {
            // Handle the case with labels
            getline(ss, label1, ',');
            getline(ss, label2, '\r');
            graph_->addNode(src,label1);
            graph_->addNode(trg,label2);
        } else {
            // Handle the case without labels
            getline(ss, dist, '\r');
            graph_->addNode(src);
            graph_->addNode(trg);
        }
        graph_->addEdge(src,trg,dis);
        graph_->addEdge(trg,src,dis);
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
        int src;
        std::string source, lng, lat;
        getline(ss, source, ',');//n
        getline(ss, lng, ',');
        getline(ss, lat, '\r');
        src=stoi(source);
        graph_->addNode(src,lng,lat);
    }
    while(getline(input_edges, line))
    {
        std::stringstream ss(line);
        int src,trg;
        double dis;
        std::string source, target, dist;

        getline(ss, source, ',');//n
        getline(ss, target, ',');
        getline(ss, dist, '\r');
        src=stoi(source);
        trg=stoi(target);
        dis=stod(dist);
        graph_->addEdge(src,trg,dis);
        graph_->addEdge(trg,src,dis);
    }
}
void Gestor::MostrarNodes() {
    for(auto node:graph_->nodes)
    {
        cout << left << setw(6) << "Source: " << setw(40) << to_string(node.first) << "\n";
    }
}

void Gestor::VerAdj() {
    string nod;
    int a;
    cout << "Digite o node: ";
    cout << "\n";
    cin >> nod;
    a=stoi(nod);
    auto source =graph_->nodes.find(a);
    if(source!=graph_->nodes.end())
    {
        for (auto e:source->second.adj)
        {
            std::cout << "Destino: " << e.dest << " \n";
        }
    }
    else
    {
        cout << "Nao encontrado" << "\n";
    }
}

void Gestor::BackTracking(int n, int currentNode, int count, int currentCost, int& bestCost){
    if(count==n && ){
        bestCost = min(bestCost, currentCost + graph_.)
    }
}