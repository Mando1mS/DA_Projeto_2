#include "Gestor.h"

#ifndef DA_PROJETO_2_MENU_H
#define DA_PROJETO_2_MENU_H
/**
 * @brief Represents the menu.
 */
class Menu{
    /**
     * @brief A manager.
     */
    Gestor gestor_;
public:
    /**
     * @brief Constructor of the Menu class.
     * @details Also creates a new Manager to execute every action needed.
     */
    Menu();
    /**
     * @brief Initializes the main menu.
     */
    void iniciarMenu();
    /**
     * @brief Initializes the Toy Graph options menu.
     */
     void Toy();
    /**
    * @brief Initializes the Real-world Graph options menu.
    */
     void Real();
    /**
    * @brief Initializes the Extra-Fully Connected options menu.
    */
    void EFC();
    /**
     * @brief Initializes the User Interface for the Toy Graphs.
     */
    void ToyShow();
    /**
     * @brief Initializes the User Interface for the Extra-Fully Connected Graphs.
     */
    void EFCShow();
    /**
     * @brief Initializes the User Interface for the Real-world Graphs.
     */
    void RealShow();
};
#endif //DA_PROJETO_2_MENU_H
