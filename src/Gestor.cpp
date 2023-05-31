
#include "../include/Gestor.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <set>
#include <algorithm>
#include <chrono>
#include <bits/stdc++.h>
typedef pair<int, int> iPair;

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
            std::cout << "MST: " << to_string(e.inMST) << " \n";
        }
    }
    else
    {
        cout << "Nao encontrado" << "\n";
    }
}

void Gestor::BackTracking(int currentNode, int count, double currentCost, double& bestCost){
    if(count==graph_->nodes.size() && graph_->HasEdge(currentNode, 0)!=0.0){
        bestCost = min(bestCost, currentCost + graph_->HasEdge(currentNode,0));
        return;
    }
    for(int i = 1; i<graph_->nodes.size(); i++){
        if(!graph_->nodes.find(i)->second.visited && graph_->HasEdge(currentNode, i)!=0.0){
            graph_->nodes.find(i)->second.visited = true;
            BackTracking(i, count+1, currentCost + graph_->HasEdge(currentNode,i), bestCost);
            graph_->nodes.find(i)->second.visited = false;
        }
    }
    return;
}

int Gestor::minQueue(vector<int> key, vector <bool> inMST) {
    int min = INT_MAX;
    int index = 0;
    for (int i = 0; i < key.size(); i++) {
        if (key[i] < min && inMST[i] == false) {
            min = key[i];
            index = i;
        }
    }
    return index;
}
void Gestor::mstPrim2() {
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    int n = graph_->nodes.size();

    vector <int> key(n, INT_MAX);
    vector <int> parent(n, -1);
    vector <bool> inMST(n, false);
    pq.push(make_pair(0, 0));
    key[0] = 0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(inMST[u])
        {
            continue;
        }
        inMST[u] = true;
        for (int v = 0; v < n; v++) {
            if (graph_->HasEdge(u, v) != 0 && !inMST[v] && graph_->HasEdge(u, v) < key[v]) {
                parent[v] = u;
                key[v] = graph_->HasEdge(u, v);
                pq.push(make_pair(key[v],v));
            }
        }
    }
    mstEdge(parent);
}
void Gestor::mstEdge(vector<int> parent) {
    int n = parent.size();
    for (int i = 1; i < n; i++) {
        graph_->setEdge(parent[i], i);
        graph_->setEdge(i, parent[i]);
    }
}

void Gestor::mstPrim() {
    int n = graph_->nodes.size();

    vector <int> key(n, INT_MAX);
    vector <int> parent(n, -1);
    vector <bool> inMST(n, false);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n-1; count++) {
        int u = minQueue(key, inMST);
        inMST[u] = true;
        for (int v = 0; v < n; v++) {
            if (graph_->HasEdge(u, v) != 0 && inMST[v] == false && graph_->HasEdge(u, v) < key[v]) {
                parent[v] = u;
                key[v] = graph_->HasEdge(u, v);
            }
        }
    }
    mstEdge(parent);
}

double Gestor::Get_Size()
{
    return graph_->HasEdge(1,12);
}

void Gestor::PreorderTraversal(int currentNode, vector<int>& preorder){
    graph_->nodes.find(currentNode)->second.visited = true;
    preorder.push_back(currentNode);
    for(auto edge : graph_->nodes.find(currentNode)->second.adj){
        if(edge.inMST && !graph_->nodes.find(edge.dest)->second.visited){
        PreorderTraversal(edge.dest, preorder);
        }
    }
}

double Gestor::AddPreorder(vector<int> preorder){
    graph_->setUnvisited();
    double cost=0;
    for(int i=0; i<preorder.size()-1; i++){
        cost += graph_->HasEdge(preorder[i], preorder[i+1]);
    }
    return cost + graph_->HasEdge(preorder.back(),preorder.front());
}

std::chrono::steady_clock::time_point startTime; /**< Variable that stores the start time of the timer */


void Gestor::startTimer() {
    startTime = std::chrono::steady_clock::now();
}

long long Gestor::stopTimer() {
    auto endTime = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
}