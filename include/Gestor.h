
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
    * @brief Auxiliar function to find the minimum spanning tree
    * @param key vector of ints that contains the key values
    * @param inMST vector of bools that indicates if a node is in the MST
    * @return int with the index of the minimum value
     */
    void PreorderTraversal(int currentNode, vector<int>& preorder);
    /**
    * @brief Auxiliar function to find the minimum spanning tree
    * @param preorder vector of ints that contains the key values
    * @return
     */
    double AddPreorder(vector<int> preorder);
    /**
     * @brief Function that solves the TSP problem using a greedy approach.
     * @return Total cost of the TSP problem.
     */
    double Greedy();
    /**
    * @brief Function that calculates the minimum spanning tree using Prim's algorithm
    * @details On average, the time complexity is O(V^2)
    */
     void mstPrim();
    /**
   * @brief Function that calculates the minimum spanning tree using Prim's algorithm
   * @details Currently time complexity is O(V^2), not optimized to O(E log(V))
   * @return void
   */
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
    */
     void startTimer();

    /**
    * @brief Function that stops the timer
     * @return Time elapsed in microseconds;
    */
    long long int stopTimer();
    /**
     *
     * @return
     */
    double Get_Size();
};
#endif //DA_PROJETO_1_GESTOR_H
