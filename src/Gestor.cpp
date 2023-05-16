#include "../../../../Desktop/DA_Projeto_2/include/Gestor.h"
#include "../include/Estacao.h"
#include "../../../../CLionProjects/DA_Projeto_2/DA_Projeto_2/Menu.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <set>

using namespace std;

Gestor::Gestor(string linha) {
    network_=new Graph();
    LerFicheiros(linha);
}
void Gestor::LerFicheiros(std::string linha2) {
    std::ifstream estacoes_input("../data/stations.csv");
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
        District d;
        Municipality m;
        if(linha2=="Todos")
        {

            m.Mun_setNome(concelho);
            m.Mun_setCapacidade(0);
            if(!std::count(municip.begin(), municip.end(), m))
            {
                municip.push_back(m);
            }
            Estacao estacao = Estacao(nome, d, m, localidade, linha);

            bool found = false;
            for (auto x: distritos) {
                if (x.getNome() == distrito) {
                    estacao = Estacao(nome, x, m, localidade, linha);
                    found = true;
                    break;
                }
            }
            if (!found) {
                d.setCapacidade(0);
                d.setNome(distrito);
                distritos.push_back(d);
                estacao = Estacao(nome, d, m, localidade, linha);
            }
            network_->addNode(nome, estacao);//n
        }
        else
        {
            if(linha2==linha)
            {
                m.Mun_setNome(concelho);
                m.Mun_setCapacidade(0);
                if(!std::count(municip.begin(), municip.end(), m))
                {
                    municip.push_back(m);
                }
                Estacao estacao = Estacao(nome, d, m, localidade, linha);

                bool found = false;
                for (auto x: distritos) {
                    if (x.getNome() == distrito) {
                        estacao = Estacao(nome, x, m, localidade, linha);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    d.setCapacidade(0);
                    d.setNome(distrito);
                    distritos.push_back(d);
                    estacao = Estacao(nome, d, m, localidade, linha);
                }
                network_->addNode(nome, estacao);//n
            }
        }
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

void Gestor::MostrarNetwork()
{
    for(auto est:network_->nodes)
    {
        auto u=est.second;
        for(auto lig:u.adj)
        {
            cout << left << setw(13) << "Nome source: " << setw(40) << u.estacao.getNome() << setw(13) << "Nome destino: " << setw(30) << lig.dest << "\n";
        }
    }
    for(auto a: network_->nodes.at("Espinho").adj)
    {
        cout << a.dest << "\n";
    }

    for(auto x:distritos){
        cout << x.getNome() << "  " << x.getCapacidade() << "\n";
    }
}

int Gestor::MaxArrivingTrains(string station) {
    int res = 0;
    for (auto e: network_->nodes.at(station).adj) {
        res += e.cap;
    }
    return res;
}

int Gestor::maxFlow(const string source,const string target) {
    return network_->maxFlow(source,target);
}

list<pair<string,string>> Gestor::topestacoes()
{
    list<pair<string,string>> res;
    unordered_map<int,pair<string,string>> lista;
    set<int> keys;
    for(auto est1: network_->nodes)
    {
        for(auto est2: network_->nodes)
        {
            if(est1.first!=est2.first)
            {
                auto a =network_->maxFlow(est1.first,est2.first);
                lista.insert({a,{est1.first,est2.first}});
            }
        }
    }
    for(auto&it:lista)
    {
        keys.insert(it.first);
    }
    int c=0;
    for(auto& it:keys)
    {
        res.push_back({lista[it].first,lista[it].second});
        c++;
        if(c==4)
        {
            break;
        }
    }
    return res;
}

void Gestor::TransNeeds_Dist() {
    int n;
    cout << "Insere o numero total de distritos para vizualizar: ";
    cin >> n;
    cout << "\n";
    if(n>=1 && n <=18)
    {
        std::sort(distritos.begin(),distritos.end());
        for(int i=0;i<n;i++) {
            cout << "Distrito numero " << i << " - " << distritos[i].getNome() << " com capacidade total: "
                 << distritos[i].getCapacidade() << "\n";
        }
    }
    else
    {
        cout << "Nao existe mais que 18 distritos em Portugal. \n";
    }
}

void Gestor::TransNeeds_Mun() {
    int n;
    cout << "Insere o numero total de concelhos para vizualizar: ";
    cin >> n;
    cout << "\n";
    if(n>=1 && n <=60)
    {
        std::sort(municip.begin(),municip.end());
        for(int i=0;i<n;i++) {
            cout << "Concelho numero " << i << " - " << municip[i].Mun_getNome() << " com capacidade total: "
                 << municip[i].Mun_getCapacidade() << "\n";
        }
    }
    else
    {
        cout << "Numero maximo de 60 concelhos. \n";
    }
}
