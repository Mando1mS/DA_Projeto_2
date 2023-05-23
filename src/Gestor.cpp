
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
void Gestor::LerFicheiros(std::string fich) {
    std::ifstream input(fich);
    std::string line;
    //passar a primeira linha á frente pois tem dados desnecessários.
    getline(input, line);
    while(getline(input, line)) {//n^2
        std::stringstream ss(line);

        std::string source, target, dist;

        getline(ss, source, ',');//n
        getline(ss, target, ',');
        getline(ss, dist, ',');
        graph_->addEdge(source,target,dist);

    }
}


void Gestor::MostrarEstacoes() {
    for(auto node:graph_->nodes)
    {
        cout << left << setw(6) << "Source: " << setw(40) << node.first << "\n";
    }
}