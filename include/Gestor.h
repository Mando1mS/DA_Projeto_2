
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
public:
    /**
     * @brief Creates a new manager.
     * @details Constructor of the "Gestor" class.
     */
    Gestor(std::string fich);
    /**
     * @brief Prints all of the stored stations.
     */
};
#endif //DA_PROJETO_1_GESTOR_H
