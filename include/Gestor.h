
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
    Graph* network_;
    void LerFicheiros(std::string fich);
public:
    /**
     * @brief Creates a new manager.
     * @details Constructor of the "Gestor" class.
     */
    Gestor();
    /**
     * @brief Prints all of the stored stations.
     */
    void MostrarEstacoes();
    /**
     * @brief Prints all of the network connections.
     */
    void MostrarNetwork();
    /**
     * @brief Calculates the maximum amount of trains arriving at a given station.
     * @details Time Complexity - O(E).
     * @param station Station's name.
     * @return Maximum amount of trains arriving at a giving station
     */
    int MaxArrivingTrains(string station);
    /**
     * @brief Calculates the max flow between a source station and a target station.
     * @details Time Complexity - O(VE^2).
     * @details V is the number of vertices/nodes and E is the number of edges/links.
     * @param source Name of the source station.
     * @param target Name of the destination station.
     * @return Maxflow(source,target).
     */
    int maxFlow(const string source,const string target);
    /**
     * @brief Prints the top 4 pair of stations with the most amount of trains traveling between them
     * @details Time Complexity - O(V^2(VE^2)).
     * @return List of pairs of stations.
     */
    list<pair<string,string>> topestacoes();
    /**
     * @brief Displays the "n" number of districts with the most transportation needs.
     * @details Time Complexity - O(Nlog(N))
     * @details N is the number of districts.
     * @param n Number of districts to analyze.
     */
    void TransNeeds_Dist();
    /**
     * @brief Displays the "n" number of Municipalities with the most transportation needs.
     * @details Time Complexity - O(Nlog(N))
     * @details N is the number of municipalities.
     * @param n Number of districts to analyze.
     */
    void TransNeeds_Mun();
};
#endif //DA_PROJETO_1_GESTOR_H
