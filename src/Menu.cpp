
#include <iostream>
#include <string>
#include "../include/Menu.h"



Menu::Menu():gestor_(Gestor("../data/Toy-Graphs/stadiums.csv")) {}
void Menu::iniciarMenu() {
    while(true) {
        std::cout << "--------------------------------------------------------\n";
        std::cout << "|           Selecione o gráfico a ser usado            |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 1 - Extra_Fully_Connected                            |\n";
        std::cout << "| 2 - Real-world                                       |\n";
        std::cout << "| 3 - Toy Graphs                                       |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 0 - Exit                                             |\n";
        std::cout << "--------------------------------------------------------\n";

        char opt;
        while(true) {
            std::cout << "\nOpcao: ";
            std::cin >> opt;
            if(opt <= '3' && opt >= '0' || opt == '9')
                break;
            std::cout << "Opcao invalida, escolha outra.\n";
        }

        switch(opt) {
            case '1':
                Toy();
                break;
            case '2':

                break;
            case '3':
                break;
            case '9':
                break;
            case '0':
                exit(3);
        }
    }
}

void Menu::Toy()
{
    while(true) {
        std::cout << "--------------------------------------------------------\n";
        std::cout << "|           Selecione o gráfico a ser usado            |\n";
        std::cout << "|                   (Toy Graphs)                       |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 1 - Shipping                                         |\n";
        std::cout << "| 2 - Stadiums                                         |\n";
        std::cout << "| 3 - Tourism                                          |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 0 - Go back                                          |\n";
        std::cout << "--------------------------------------------------------\n";

        char opt;
        while(true) {
            std::cout << "\nOpcao: ";
            std::cin >> opt;
            if(opt <= '3' && opt >= '0' || opt == '9')
                break;
            std::cout << "Opcao invalida, escolha outra.\n";
        }

        switch(opt) {
            case '1':
                ToyShip();
                break;
            case '2':

                break;
            case '3':

                break;
            case '9':
                break;
            case '0':
                iniciarMenu();
                break;
        }
    }
}

void Menu::ToyShip()
{
    while(true) {
        std::cout << "--------------------------------------------------------\n";
        std::cout << "|                Toy Graph - Shipping                  |\n";
        std::cout << "|                                                      |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 1 - Mostrar                                          |\n";
        std::cout << "| 2 - Opcao 2                                          |\n";
        std::cout << "| 3 - Opcao 3                                          |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 0 - Go back                                          |\n";
        std::cout << "--------------------------------------------------------\n";

        char opt;
        while(true) {
            std::cout << "\nOpcao: ";
            std::cin >> opt;
            if(opt <= '3' && opt >= '0' || opt == '9')
                break;
            std::cout << "Opcao invalida, escolha outra.\n";
        }

        switch(opt) {
            case '1':
                gestor_.MostrarEstacoes();
                break;
            case '2':

                break;
            case '3':
                break;
            case '9':
                break;
            case '0':
                Toy();
                break;
        }
    }
}

