
#include <iostream>
#include <string>
#include "../include/Menu.h"


Menu::Menu() {}
void Menu::iniciarMenu() {
    while(true) {
        std::cout << "--------------------------------------------------------\n";
        std::cout << "|      Bem vindo a gestao ferroviaria de Portugal      |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 1 - Numero maximo de comboios                        |\n";
        std::cout << "| 2 - Vizualizar Rede                                  |\n";
        std::cout << "| 3 - Transportation needs                             |\n";
        std::cout << "|                                                      |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 9 - Settings                                         |\n";
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

                break;
            case '2':

                break;
            case '3':
                break;
            case '9':
                break;
            case '0':
                exit(3);
                return;
        }
    }
}



