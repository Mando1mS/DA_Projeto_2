
#include "../include/Graph.h"
#include <vector>

#ifndef DA_PROJETO_1_GESTOR_H
#define DA_PROJETO_1_GESTOR_H

/**
 * @brief Represents the manager class used to connect the other classes with the user interface.
 */
class Gestor
{
private:
    /**
     * @brief A pointer to the network graph which contains all info about the train network.
     */
    Graph* graph_;
    /**
     * @brief Reads all the data , and stores them in the appropriate data struct.
     * @details Time Complexity O(N^2). N being the number of lines in a csv file.
     * @param fich Path to the chosen file
     */
    void LerFicheiros(std::string fich);
    /**
     * @brief Reads all the data , and stores them in the appropriate data struct.
     * @details Overloading of the LerFicheiros function. Used to read 2 files , available on Real-world Graphs.
     * @details Time Complexity O(N^2). N being the number of lines in a csv file.
     * @param fich
     * @param fich2
     */
    void LerFicheiros(std::string fich,std::string fich2);
public:
    /**
     * @brief Creates a new manager.
     * @details Constructor of the "Gestor" class.
     * @param fich Path to the chosen file.
     */
    Gestor(std::string fich);
    /**
     * @brief Creates a new manager.
     * @details Overloading of the "Gestor" class.
     * @details Used to read the data from Real-world Graphs which have 2 files to read.
     * @param fich Path to the chosen file of nodes.
     * @param fich2 Path to the chosen file of edges.
     */
    Gestor(std::string fich,std::string fich2);
    /**
    * @brief Function that shows the nodes of the graph.
    */
    void MostrarNodes();
    /**
    * @brief Function that shows the edges of a node.
    */
    void VerAdj();
    /**
    * @brief Function that uses the backtracking algorithm to solve the TSP
     * @details Time Complexity (!V). V is the number of nodes.
    * @param currentNode int with the current node
    * @param count int with the number of nodes visited
    * @param currentCost double with the current cost
    * @param bestCost double with the best cost
    */
     void BackTracking(int currentNode, int count, double currentCost, double &bestCost);
    /**
    * @brief Auxiliary function to solve the TSP problem using Triangular Inequality.
    * @details Calculates the new path to the TSP.
    * @param currentNode Current Node being searched.
    * @param preorder Vector including the TSP path.
     */
    void PreorderTraversal(int currentNode, vector<int>& preorder);
    /**
    * @brief Auxiliary function to add the weighs of the TSP path using Triangular Inequality.
    * @param preorder vector of ints that contains the key values
    * @return Total distance the Traveling Salesman has to travel.
     */
    double AddPreorder(vector<int> preorder);
    /**
     * @brief Function that solves the TSP problem using a greedy approach.
     * @details Time Complexity O(E V).
     * @return Total cost of the TSP problem.
     */
    double Greedy();
    /**
    * @brief Auxiliar function that changes the boolean inMST ina  Edge that belongs to the MST.
    * @param parent vector of ints that contains the parent of each node
    */
     void mstEdge(vector<int> parent);
    /**
    * @brief Function that calculates the minimum spanning tree using Prim's algorithm
    * @details Currently time complexity is O(E log(V))
    */
     void primMST();
    /**
     * @brief Function that calculates the distance between two coordinates
     * @param lat1 Latitude coordinates from node 1.
     * @param lon1 Longitude coordinates from node 1.
     * @param lat2 Latitude coordinates from node 2.
     * @param lon2  Longitude coordinates from node 2.
     * @return double with the distance between the two coordinates
     */
     double haversine(double lat1, double lon1, double lat2, double lon2);
    /**
    * @brief Function that starts the timer
    */
     void startTimer();
    /**
    * @brief Function that stops the timer
     * @return Time elapsed in microseconds;
    */
    long long int stopTimer();
    /**
     * Function used to test the distance between 2 nodes.
     * @return Distance between 2 testing nodes.
     */
    double Get_Size();
};
#endif //DA_PROJETO_1_GESTOR_H
