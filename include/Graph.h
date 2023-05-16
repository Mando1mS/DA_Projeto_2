
#ifndef DA_PROJETO_2_GRAPH_H
#define DA_PROJETO_2_GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
#include <list>
#include <unordered_map>
#include <unordered_set>


using namespace std;
/**
 * @brief Represents a Graph.
 */
class Graph {
private:
    struct Edge {
        /**
         * @brief Destination Node.
         * @details Uses only the name because of its unique nature.
         */
        std::string dest;
        /**
         * @brief Capacity of the line.
         * @details Number of simultaneously traveling trains in a line.
         */
        double dist;

    };
    struct Node {
        /**
         * @brief Station.
         */
        Estacao estacao;
        /**
         * @brief List of outgoing edges, to adjacent nodes.
         */
        std::list<Edge> adj;
        /**
         * @brief Verifies if the node has been visited on a previous search.
         * @details This variable set to True means that the node has been visited and False otherwise.
         */
        bool visited;
        /**
         * @brief A list that stores another list with all the stations and services from the source all the way to the target node.
         */
        list<list<pair<Estacao,string>>> travel_from_src;
        /**
         * @brief Stores the parent node of the child node.
         */
        string parent;
        /**
         * @brief Stores the path from the source node to the current node.
         */
        vector<string> path;
    };

public:
    Graph();
    /**
     * @brief Add a node to the Graph using the name of the station as a key and the whole "Estacao" class as the value.
     * @details Time Complexity - O(|V| + |E|).
     * @details V is the number of vertices/nodes and E is the number of edges/links.
     * @param nome_estacao Name of the station.
     * @param estacao All of the station information.
     */
    void addNode(const std::string &nome_estacao, const Estacao &estacao);
    /**
     * @brief Add an edge from a source station to a target station using the capacity of the line as the weight.
     * @details Time Complexity - O(|V| + |E|).
     * @details V is the number of vertices/nodes and E is the number of edges/links.
     * @param source_estacao The source airport.
     * @param target_estacao The target airport.
     * @param cap Number of simultaneously traveling trains in a line.
     * @param tipo Type of service used.
     */
    void addEdge(const std::string& source_estacao, const std::string& target_estacao,int cap, const std::string& tipo);
    /**
     * @brief A hash table containing the connection between the name of the station and its node.
     * @details When searching the Time Complexity is O(1).
     */
    std::unordered_map<std::string, Node> nodes;
    /**
     * @brief Set of lines favoured by the client.
     * @details Can be empty.
     */
    std::unordered_set<std::string> wanted_lines;
    /**
     * @brief Function used to do a Breadth-First Search (aka BFS).
     * @details Time Complexity - O(|V| + |E|).
     * @details V is the number of vertices/nodes and E is the number of edges/links.
     * @param nome_estacao Name of the station.
     */
    void bfs(const std::string &nome_estacao);
    /**
     * @brief A list that stores all the shortest paths between 2 stations.
     */
    list<list<string>> shortestpaths_;
    /**
     * @brief A alternative BFS to calculate the shortest paths between 2 stations.
     * @details Time Complexity - O(|V^2| + |E|).
     * @details V is the number of vertices/nodes and E is the number of edges/links.
     * @param nome_estacaoA Name of the source station.
     * @param nome_estacaoB Name of the destination station.
     */
    void bfs2p(const std::string &nome_estacaoA,const std::string &nome_estacaoB);
    /**
     * @brief Function used to do Edmonds-karp algorithm.
     * @details Time Complexity - O(VE^2).
     * @details V is the number of vertices/nodes and E is the number of edges/links.
     * @param nome_estacaoA Name of the source station.
     * @param nome_estacaoB Name of the destination station.
     */
    int maxFlow(string source, string target);
    /**
     * @brief Clears some variables in the graph to help implement other functions.
     * @details Clears every path from each node.
     * @details Sets all nodes to unvisited
     * @details Clears the list of the shortest paths.
     */
    void setUnvisited();
    /**
     * Yields the number of stations.
     * @return Number of stations present in the graph.
     */
    int getNumEstacoes() const;

};


#endif //DA_PROJETO_1_GRAPH_H
