
#include <iostream>
#include <string>
#include "../include/Menu.h"


long long int tempo;
Menu::Menu():gestor_(Gestor("../data/Toy-Graphs/stadiums.csv")) {}
void Menu::iniciarMenu() {
    while(true) {
        std::cout << "--------------------------------------------------------\n";
        std::cout << "|           Selecione o grafico a ser usado            |\n";
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
            if(opt <= '3' && opt >= '0')
                break;
            std::cout << "Opcao invalida, escolha outra.\n";
        }

        switch(opt) {
            case '1':
                EFC();
                break;
            case '2':
                Real();
                break;
            case '3':
                Toy();
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
            if(opt <= '3' && opt >= '0')
                break;
            std::cout << "Opcao invalida, escolha outra.\n";
        }

        switch(opt) {
            case '1':
                gestor_=Gestor("../data/Toy-Graphs/shipping.csv");
                ToyShow();
                break;
            case '2':
                gestor_=Gestor("../data/Toy-Graphs/stadiums.csv");
                ToyShow();
                break;
            case '3':
                gestor_=Gestor("../data/Toy-Graphs/tourism.csv");
                ToyShow();
                break;
            case '0':
                iniciarMenu();
                break;
        }
    }
}

void Menu::EFC()
{
    while(true) {
        std::cout << "--------------------------------------------------------\n";
        std::cout << "|           Selecione o gráfico a ser usado            |\n";
        std::cout << "|               (Extra-Fully Connected)                |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 1 - 25 Edges                                         |\n";
        std::cout << "| 2 - 50 Edges                                         |\n";
        std::cout << "| 3 - 75 Edges                                         |\n";
        std::cout << "| 4 - 100 Edges                                        |\n";
        std::cout << "| 5 - 200 Edges                                        |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 0 - Go back                                          |\n";
        std::cout << "--------------------------------------------------------\n";

        char opt;
        while(true) {
            std::cout << "\nOpcao: ";
            std::cin >> opt;
            if(opt <= '5' && opt >= '0')
                break;
            std::cout << "Opcao invalida, escolha outra.\n";
        }
        switch(opt) {
            case '1':
                gestor_=Gestor("../data/Extra_Fully_Connected_Graphs/edges_25.csv");
                EFCShow();
                break;
            case '2':
                gestor_=Gestor("../data/Extra_Fully_Connected_Graphs/edges_50.csv");
                EFCShow();
                break;
            case '3':
                gestor_=Gestor("../data/Extra_Fully_Connected_Graphs/edges_75.csv");
                EFCShow();
                break;
            case '4':
                gestor_=Gestor("../data/Extra_Fully_Connected_Graphs/edges_100.csv");
                EFCShow();
                break;
            case '5':
                gestor_=Gestor("../data/Extra_Fully_Connected_Graphs/edges_200.csv");
                EFCShow();
                break;
            case '0':
                iniciarMenu();
                break;
        }
    }
}
void Menu::Real()
{
    while(true) {
        std::cout << "--------------------------------------------------------\n";
        std::cout << "|           Selecione o gráfico a ser usado            |\n";
        std::cout << "|                  (Real-world Graphs)                 |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 1 - graph 1                                          |\n";
        std::cout << "| 2 - graph 2                                          |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 0 - Go back                                          |\n";
        std::cout << "--------------------------------------------------------\n";

        char opt;
        while(true) {
            std::cout << "\nOpcao: ";
            std::cin >> opt;
            if(opt <= '2' && opt >= '0')
                break;
            std::cout << "Opcao invalida, escolha outra.\n";
        }

        switch(opt) {
            case '1':
                gestor_=Gestor("../data/Real-world_Graphs/graph1/nodes.csv","../data/Real-world_Graphs/graph1/edges.csv");
                RealShow();
                break;
            case '2':
                gestor_=Gestor("../data/Real-world_Graphs/graph2/nodes.csv","../data/Real-world_Graphs/graph2/edges.csv");
                RealShow();
                break;
            case '0':
                iniciarMenu();
                break;
        }
    }
}
void Menu::ToyShow()
{
    while(true) {
        std::cout << "--------------------------------------------------------\n";
        std::cout << "|                     Toy Graph                        |\n";
        std::cout << "|                                                      |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 1 - Greedy                                           |\n";
        std::cout << "| 2 - Triangular Inequality                            |\n";
        std::cout << "| 3 - Backtracking                                     |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 0 - Go back                                          |\n";
        std::cout << "--------------------------------------------------------\n";

        char opt;
        while(true) {
            std::cout << "\nOpcao: ";
            std::cin >> opt;
            if(opt <= '5' && opt >= '0')
                break;
            std::cout << "Opcao invalida, escolha outra.\n";
        }
        double best=DBL_MAX;
        vector<int> preorder;
        switch(opt) {
            case '1':
                gestor_.startTimer();
                std::cout << "O melhor caminho tem: " << to_string(gestor_.Greedy()) << " . \n";
                tempo= gestor_.stopTimer();
                if(tempo<1000) std::cout << "Demorou : " << to_string(tempo) << " microssegundos \n";
                else if(tempo<1000000) std::cout << "Demorou : " << to_string(tempo/1000) << " milisegundos \n";
                else std::cout << "Demorou : " << to_string(tempo/1000000) << " segundos \n";
                break;
            case '2':
                gestor_.startTimer();
                gestor_.primMST();
                gestor_.PreorderTraversal(0, preorder);
                tempo= gestor_.stopTimer();
                std::cout << "O melhor caminho tem: " << to_string(gestor_.AddPreorder(preorder)) << " . \n";
                if(tempo<1000) std::cout << "Demorou : " << to_string(tempo) << " microssegundos \n";
                else if(tempo<1000000) std::cout << "Demorou : " << to_string(tempo/1000) << " milisegundos \n";
                else std::cout << "Demorou : " << to_string(tempo/1000000) << " segundos \n";
                break;
            case '3':
                gestor_.startTimer();
                gestor_.BackTracking(0,1,0,best);
                tempo= gestor_.stopTimer();
                std::cout << "O melhor caminho tem: " << to_string(best) << " . \n";
                if(tempo<1000) std::cout << "Demorou : " << to_string(tempo) << " microssegundos \n";
                else if(tempo<1000000) std::cout << "Demorou : " << to_string(tempo/1000) << " milisegundos \n";
                else std::cout << "Demorou : " << to_string(tempo/1000000) << " segundos \n";
                break;
            case '4':
                std::cout << "Size:" << to_string(gestor_.Get_Size()) << "\n";
                break;
            case '5':
                std::cout << "Parent ";
                gestor_.primMST();
                gestor_.VerAdj();
                break;

            case '0':
                Toy();
                break;
        }
    }
}
void Menu::RealShow()
{
    while(true) {
        std::cout << "--------------------------------------------------------\n";
        std::cout << "|                  Real World Graphs                   |\n";
        std::cout << "|                                                      |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 1 - Greedy                                           |\n";
        std::cout << "| 2 - Triangular Inequality                            |\n";
        std::cout << "| 3 - Backtracking                                     |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 0 - Go back                                          |\n";
        std::cout << "--------------------------------------------------------\n";

        char opt;
        while(true) {
            std::cout << "\nOpcao: ";
            std::cin >> opt;
            if(opt <= '3' && opt >= '0')
                break;
            std::cout << "Opcao invalida, escolha outra.\n";
        }
        double best=DBL_MAX;
        vector<int> preorder;
        switch(opt) {
            case '1':
                gestor_.startTimer();
                std::cout << "O melhor caminho tem: " << to_string(gestor_.Greedy()) << " . \n";
                tempo= gestor_.stopTimer();
                if(tempo<1000) std::cout << "Demorou : " << to_string(tempo) << " microssegundos \n";
                else if(tempo<1000000) std::cout << "Demorou : " << to_string(tempo/1000) << " milisegundos \n";
                else std::cout << "Demorou : " << to_string(tempo/1000000) << " segundos \n";
                break;
            case '2':
                gestor_.startTimer();
                gestor_.primMST();
                gestor_.PreorderTraversal(0, preorder);
                tempo= gestor_.stopTimer();
                std::cout << "O melhor caminho tem: " << to_string(gestor_.AddPreorder(preorder)) << " . \n";
                if(tempo<1000) std::cout << "Demorou : " << to_string(tempo) << " microssegundos \n";
                else if(tempo<1000000) std::cout << "Demorou : " << to_string(tempo/1000) << " milisegundos \n";
                else std::cout << "Demorou : " << to_string(tempo/1000000) << " segundos \n";
                break;
            case '3':
                gestor_.startTimer();
                gestor_.BackTracking(0,1,0,best);
                tempo= gestor_.stopTimer();
                std::cout << "O melhor caminho tem: " << to_string(best) << " . \n";
                if(tempo<1000) std::cout << "Demorou : " << to_string(tempo) << " microssegundos \n";
                else if(tempo<1000000) std::cout << "Demorou : " << to_string(tempo/1000) << " milisegundos \n";
                else std::cout << "Demorou : " << to_string(tempo/1000000) << " segundos \n";
                break;
            case '0':
                Real();
                break;
        }
    }
}

void Menu::EFCShow()
{
    while(true) {
        std::cout << "--------------------------------------------------------\n";
        std::cout << "|                 Extra-Fully Connected                |\n";
        std::cout << "|                                                      |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 1 - Greedy                                           |\n";
        std::cout << "| 2 - Triangular Inequality                            |\n";
        std::cout << "| 3 - Backtracking                                     |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 0 - Go back                                          |\n";
        std::cout << "--------------------------------------------------------\n";

        char opt;
        while(true) {
            std::cout << "\nOpcao: ";
            std::cin >> opt;
            if(opt <= '3' && opt >= '0')
                break;
            std::cout << "Opcao invalida, escolha outra.\n";
        }
        double best=DBL_MAX;
        vector<int> preorder;
        switch(opt) {
            case '1':
                gestor_.startTimer();
                std::cout << "O melhor caminho tem: " << to_string(gestor_.Greedy()) << " . \n";
                tempo= gestor_.stopTimer();
                if(tempo<1000) std::cout << "Demorou : " << to_string(tempo) << " microssegundos \n";
                else if(tempo<1000000) std::cout << "Demorou : " << to_string(tempo/1000) << " milisegundos \n";
                else std::cout << "Demorou : " << to_string(tempo/1000000) << " segundos \n";
                break;
            case '2':
                gestor_.startTimer();
                gestor_.primMST();
                gestor_.PreorderTraversal(0, preorder);
                tempo= gestor_.stopTimer();
                std::cout << "O melhor caminho tem: " << to_string(gestor_.AddPreorder(preorder)) << " . \n";
                if(tempo<1000) std::cout << "Demorou : " << to_string(tempo) << " microssegundos \n";
                else if(tempo<1000000) std::cout << "Demorou : " << to_string(tempo/1000) << " milisegundos \n";
                else std::cout << "Demorou : " << to_string(tempo/1000000) << " segundos \n";
                break;
            case '3':
                gestor_.startTimer();
                gestor_.BackTracking(0,1,0,best);
                tempo= gestor_.stopTimer();
                std::cout << "O melhor caminho tem: " << to_string(best) << " . \n";
                if(tempo<1000) std::cout << "Demorou : " << to_string(tempo) << " microssegundos \n";
                else if(tempo<1000000) std::cout << "Demorou : " << to_string(tempo/1000) << " milisegundos \n";
                else std::cout << "Demorou : " << to_string(tempo/1000000) << " segundos \n";
                break;
                break;
            case '0':
                EFC();
                break;
        }
    }
}

