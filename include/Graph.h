
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
        int dest;
        /**
         * @brief Capacity of the line.
         * @details Number of simultaneously traveling trains in a line.
         */
        double dist;

    };
    struct Node {
        /**
         * @brief id.
         */
        int id;
        /**
         * @brief List of outgoing edges, to adjacent nodes.
         */
        std::list<Edge> adj;
         std::pair<string,string> coord;
         std::string label;
        /**
        * @brief Verifies if the node has been visited on a previous search.
        * @details This variable set to True means that the node has been visited and False otherwise.
        */
         bool visited;
         /**
         * @brief A list that stores another list with all the stations and services from the source all the way to the target node.
         */
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
    void addNode(const int &id,std::string label="");

    /**
     * @brief Add a node to the Graph using the name of the station as a key and the whole "Estacao" class as the value.
     * @details Time Complexity - O(|V| + |E|).
     * @details V is the number of vertices/nodes and E is the number of edges/links.
     * @param nome_estacao Name of the station.
     * @param estacao All of the station information.
     */
    void addNode(const int &id,std::string lng, std::string lat);
    /**
     * @brief Add an edge from a source station to a target station using the capacity of the line as the weight.
     * @details Time Complexity - O(|V| + |E|).
     * @details V is the number of vertices/nodes and E is the number of edges/links.
     * @param source_estacao The source airport.
     * @param target_estacao The target airport.
     * @param cap Number of simultaneously traveling trains in a line.
     * @param tipo Type of service used.
     */
    void addEdge(const int &id_source, const int &id_target,const double &dist);
    /**
     * @brief A hash table containing the conne/home/linus/DA/DA-QuickStartction between the name of the station and its node.
     * @details When searching the Time Complexity is O(1).
     */
     std::unordered_map<int, Node> nodes;
     void setUnvisited();
     bool HasEdge(const int &id_source, const int &id_target);
     };


#endif //DA_PROJETO_1_GRAPH_H
