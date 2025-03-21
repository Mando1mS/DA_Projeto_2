
#include "../include/Gestor.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <set>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <functional>
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



void Gestor::mstEdge(vector<int> parent) {
    int n = parent.size();
    for (int i = 1; i < n; i++) {
        graph_->setEdge(parent[i], i);
        graph_->setEdge(i, parent[i]);
    }
}



void Gestor::primMST() {
    int n = graph_->nodes.size();
    vector <int> key(n, INT_MAX);
    vector <int> parent(n, -1);
    vector <bool> inMST(n, false);
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto edge: graph_->nodes.find(u)->second.adj) {
            int v = edge.dest;
            int dist = edge.dist;

            if (!inMST[v] && dist < key[v]) {
                parent[v] = u;
                key[v] = dist;

                pq.push(make_pair(key[v], v));
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
        if(graph_->HasEdge(preorder[i], preorder[i+1])==0.0){
            cost += haversine(stod(graph_->nodes.find(preorder[i])->second.coord.second),
                              stod(graph_->nodes.find(preorder[i])->second.coord.first),
                              stod(graph_->nodes.find(preorder[i+1])->second.coord.second),
                              stod(graph_->nodes.find(preorder[i+1])->second.coord.first));
        }
        else cost += graph_->HasEdge(preorder[i], preorder[i+1]);
    }
    return cost + graph_->HasEdge(preorder.back(),preorder.front());
}

double Gestor::Greedy(){
    graph_->setUnvisited();
    double cost = 0;
    int count = 1;
    int currentNode = 0;
    int destNode = 0;
    while(count<graph_->nodes.size()){
        graph_->nodes.find(currentNode)->second.visited=true;
        double bestEdge = DBL_MAX;
        for(auto e : graph_->nodes.find(currentNode)->second.adj){
            if(e.dist<bestEdge && !graph_->nodes.find(e.dest)->second.visited){
                bestEdge = e.dist;
                destNode = e.dest;
            }
        }
        count++;
        cost+=bestEdge;
        currentNode=destNode;
    }
    graph_->setUnvisited();
    return cost+graph_->HasEdge(currentNode,0);
}

double Gestor::haversine(double lat1, double lon1, double lat2, double lon2) {
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;
    double a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

std::chrono::steady_clock::time_point startTime; /**< Variable that stores the start time of the timer */


void Gestor::startTimer() {
    startTime = std::chrono::steady_clock::now();
}

long long Gestor::stopTimer() {
    auto endTime = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
}