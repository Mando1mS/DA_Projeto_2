
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
#include <limits.h>
#include <float.h>


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
        /**
         * @brief Auxiliary boolean variable that ensures the edge is present in a previous generated MST.
         */
        bool inMST;
    };
    struct Node {
        /**
         * @brief Id of the node.
         */
        int id;
        /**
         * @brief List of outgoing edges, to adjacent nodes.
         */
        std::list<Edge> adj;
        /**
         * @brief Pair of geometrical coordinates associated with a node.
         * @note Only Real-World Graphs provide such data.
         */
         std::pair<string,string> coord;
         /**
          * @brief Name associated with the node.
          * @note Only present in the tourism Toy graph.
          */
         std::string label;
        /**
        * @brief Verifies if the node has been visited on a previous search.
        * @details This variable set to True means that the node has been visited and False otherwise.
        */
         bool visited;
    };

public:
    /**
     * @brief Creates a new graph.
     * @details Constructor of the Graph class.
     * @details There are no parameters , the graph is always undirected.
     */
    Graph();
    /**
     * @brief Adds a node to the Graph with a optional label to it.
     * @details Time Complexity - O(|V| + |E|).
     * @details V is the number of vertices/nodes and E is the number of edges/links.
     * @param id Node's id.
     * @param label Name of the node.
     */
    void addNode(const int &id,std::string label="");

    /**
     * @brief Adds a node to the Graph with geometrical coordinates.
     * @details Overloading of the addNode function. Used to add geometrical coordinates instead of label.
     * @details Time Complexity - O(|V| + |E|).
     * @details V is the number of vertices/nodes and E is the number of edges/links.
     * @param id Node's id.
     * @param lng Longitude coordinate.
     * @param lat Latitude coordinate.
     */
    void addNode(const int &id,std::string lng, std::string lat);
    /**
     * @brief Adds an edge from a source node to a target node using the distance between them as the weight.
     * @details Time Complexity - O(|V| + |E|).
     * @details V is the number of vertices/nodes and E is the number of edges/links.
     * @param id_source Source node.
     * @param id_target Target node.
     * @param dist Distance between the source node and target node.
     */
    void addEdge(const int &id_source, const int &id_target,const double &dist);
    /**
     * @brief A hash table containing the connection between the Node's id and the node itself.
     * @details When searching the Time Complexity is O(1).
     */
     std::unordered_map<int, Node> nodes;
     /**
      * @brief Changes the status of all the nodes to unvisited.
      */
     void setUnvisited();
     /**
      * @brief Checks if exists a edge between 2 nodes and returns the distance between them.
      * @param id_source Source node.
      * @param id_target Target node.
      * @return Distance - If there is a edge between source and target node.
      * @return 0 - If there is no edge between source and target node.
      */
     double HasEdge(const int &id_source, const int &id_target);
     /**
      * @brief Changes the status of the edge as part of the previous generated MST.
      * @param id_source Source node.
      * @param id_target Target node.
      */
     void setEdge(const int &id_source, const int &id_target);
     };


#endif //DA_PROJETO_1_GRAPH_H
