
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
     * @brief Prints all of the stored nodes.
     */
     void MostrarNodes();
     void VerAdj();
     void BackTracking(int n, int currentNode, int count, int currentCost, int &bestCost);
};
#endif //DA_PROJETO_1_GESTOR_H
