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
     * @brief Initializes the max trains' menu.
     */
     void Toy();
     void Real();
    void EFC();
     void ToyShow();
    void EFCShow();
    void RealShow();
};
#endif //DA_PROJETO_2_MENU_H
