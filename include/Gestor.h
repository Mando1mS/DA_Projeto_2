
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
    void LerFicheiros(std::string fich);
    void LerFicheiros(std::string fich,std::string fich2);
public:
    /**
     * @brief Creates a new manager.
     * @details Constructor of the "Gestor" class.
     * @param fich Path to the chosen file.
     */
    Gestor(std::string fich);
    /**
     *
     * @param fich Path to the chosen file of nodes.
     * @param fich2 Path to the chosen file of edges.
     */
    Gestor(std::string fich,std::string fich2);
    /**
    * @brief Function that shows the nodes of the graph
    * @return void
    */
    void MostrarNodes();

    /**
    * @brief Function that shows the edges of a node
    * @return void
    */
    void VerAdj();

    /**
    * @brief Function that uses the backtracking algorithm to solve the TSP
    * @param currentNode int with the current node
    * @param count int with the number of nodes visited
    * @param currentCost double with the current cost
    * @param bestCost double with the best cost
    * @return void
    */
     void BackTracking(int currentNode, int count, double currentCost, double &bestCost);


    /**
    * @brief Auxiliar function to find the minimum spanning tree
    * @param key vector of ints that contains the key values
    * @param inMST vector of bools that indicates if a node is in the MST
    * @return int with the index of the minimum value
     */
    void PreorderTraversal(int currentNode, vector<int>& preorder);


    double AddPreorder(vector<int> preorder);

    double Greedy();

    /**
    * @brief Function that calculates the minimum spanning tree using Prim's algorithm
    * On average, the time complexity is O(V^2)
    * @return void
    */
     void mstPrim();
    void mstPrim2();
    /**
    * @brief Auxiliar function to find the minimum spanning tree
    * @param parent vector of ints that contains the parent of each node
    * @return void
    */
     void mstEdge(vector<int> parent);

    /**
     * @brief Auxiliar function to find the minimum spanning tree
     * @param key
     * @param inMST
     * @return int with the index of the minimum value
     */
     int minQueue(vector<int> key, vector <bool> inMST);

    /**
    * @brief Function that starts the timer
    * @return void
    */
     void startTimer();

    /**
    * @brief Function that stops the timer
    * @return void
    */
    long long int stopTimer();
    double Get_Size();
};
#endif //DA_PROJETO_1_GESTOR_H
