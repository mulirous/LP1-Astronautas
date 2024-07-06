#include "../../impl/tools.h"
#include "../../impl/voo.h"
#include <iostream>
#include <list>

using namespace std;

void limpaTela() {  // Função que limpa o terminal
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pausaParaLeitura() {  // Função que adiciona um comando para limpar o temrinal
    cout << endl << "Pressione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void buscarVooPorDestino(const list<Voo>& voos, const list<Astronauta>& astronautas) {  // Função de busca de voo pelo destino
    string destino;
    cout << "Digite o destino: ";
    cin.ignore(); 
    getline(cin, destino);

    bool vooEncontrado = false;

    cout << "Voos com destino a " << destino << ":" << endl;
    for (const auto& voo : voos) {
        if (voo.getDestino() == destino) {
            vooEncontrado = true;
            cout << "   Voo Cod: " << voo.getCodigo() << ", Status: ";
            switch (voo.getStatus()) {
                case PLANEJANDO:
                    cout << "em planejamento" << endl;
                    break;
                case DESTRUIDO:
                    cout << "o voo foi explodido" << endl;
                    break;
                case EMVOO:
                    cout << "Em voo" << endl;
                    break;
            }
            cout << "   Passageiros:" << endl;
            voo.visualizarPassageiros(astronautas);
        }
    }

    if (!vooEncontrado) {
        cout << "Nenhum voo encontrado para o destino " << destino << "." << endl;
    }
}
