
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
    std::ifstream estacoes_input(fich);
    std::ifstream network_input("../data/network.csv");
    std::string line;
    //passar a primeira linha á frente pois tem dados desnecessários.
    getline(estacoes_input, line);
    getline(network_input, line);
    while(getline(estacoes_input, line)) {//n^2
        std::stringstream ss(line);

        std::string nome, distrito, concelho, localidade, linha;

        getline(ss, nome, ',');//n
        getline(ss, distrito, ',');
        getline(ss, concelho, ',');
        getline(ss, localidade, ',');
        getline(ss, linha, '\r');
        graph_->addNode(nome, estacao);//n

    }
    while(getline(network_input, line)) {
        std::stringstream ss(line);

        std::string source, target, cap, tipo;

        getline(ss, source, ',');
        getline(ss, target, ',');
        getline(ss, cap, ',');
        getline(ss, tipo, '\r');
        if(network_->nodes.find(source)!=network_->nodes.end() && network_->nodes.find(target)!=network_->nodes.end() )
        {
            network_->addEdge(source, target, std::stoi(cap), tipo);
            network_->addEdge(target, source, std::stoi(cap), tipo);
            for (auto itr=distritos.begin(); itr!=distritos.end(); itr++) {
                if (itr->getNome() == network_->nodes.at(source).estacao.getDistrito().getNome()) {
                    itr->updateCapacidade(std::stoi(cap));
                }
            }
            for (auto itr=municip.begin(); itr!=municip.end(); itr++) {
                if (itr->Mun_getNome() == network_->nodes.at(source).estacao.getConcelho().Mun_getNome()) {
                    itr->Mun_updateCapacidade(std::stoi(cap));
                }
            }
        }
    }
}

void Gestor::MostrarEstacoes() {
    for(auto est:network_->nodes)
    {
        cout << left << setw(6) << "Nome: " << setw(40) << est.second.estacao.getNome() << setw(10) << "Distrito: " << setw(30) << est.second.estacao.getDistrito().getNome() << "\n";
    }
}