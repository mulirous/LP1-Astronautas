// Falta para fazer:
// Acessar a lista de histórico de voos no case 9 e corrigir disponibilidade do astonata ao finalizar os voos

#include <iostream>
#include <list>
#include "mod/impl/astronauta.h"
#include "mod/impl/voo.h"
#include "mod/impl/cemiterio.h"

using namespace std;

void limpaTela() {
    cout << "\033[2J\033[1;1H";
}

void opcoes() {
    limpaTela();

    list<string> opcoes;
    opcoes.push_back("|||||||||||||||||||||||||||||||||||||||||||||||");
    opcoes.push_back("||            AGENCIA DE VOOS IMDir          ||");
    opcoes.push_back("|||||||||||||||||||||||||||||||||||||||||||||||");
    opcoes.push_back("||       1 - Cadastrar Astronauta            ||");
    opcoes.push_back("||       2 - Cadastrar Voo                   ||");
    opcoes.push_back("||       3 - Registrar Passageiros em um Voo ||");
    opcoes.push_back("||       4 - Remover passageiros de um Voo   ||");
    opcoes.push_back("||       5 - Listar Voos                     ||");
    opcoes.push_back("||       6 - Lancar Voo                      ||");
    opcoes.push_back("||       7 - Finalizar Voo                   ||");
    opcoes.push_back("||       8 - Listar astronautas              ||");
    opcoes.push_back("||       9 - Mencoes honrosas                ||");
    opcoes.push_back("||       0 - Sair                            ||");
    opcoes.push_back("|||||||||||||||||||||||||||||||||||||||||||||||");

    for (const auto& frase : opcoes) {
        cout << frase << endl;
    }

    cout << endl;
    cout << endl;
    cout << endl;
}

int main(void) {
    int controle = 0;
    list<Astronauta> astronautas;
    list<Voo> voos;
    Cemiterio cemiterio;

    while (controle != 1) {
        cout << endl;

        opcoes();

        int op;
        cout << "Digite uma opcao: ";
        cin >> op;

        cout << endl;

        switch (op) {
            case 1: {
                string cpf, nome;
                int idade, verificacao = 0;

                cout << "CPF do astronauta: ";
                cin >> cpf;
                for (auto& astronauta : astronautas) {
                    if (astronauta.getCPF() == cpf) {
                        cout << "O CPF invalido" << endl;
                        verificacao++;
                        break;
                    }
                }

                if ( verificacao == 1) {
                    cout << "Tente cadastrar outro astronauta" << endl;
                    break;
                }

                else {
                    cout << "Nome do astronauta: ";
                    cin.ignore(); // Ignora o caractere de nova linha pendente do cin >> op
                    getline(cin, nome);
                    cout << "Idade do astronauta: ";
                    cin >> idade;

                    if (idade < 18) {
                        cout << "O astronauta eh muito novo para ser cadastrado" << endl << "Cadastre outro astronauta" << endl;
                        break;
                    }
                    else if (idade > 85) {
                        cout << "O astronauta eh muito velho para ser cadastrado" << endl << "Cadastre outro astronauta" << endl;
                        break;
                    }
                    else {
                        Astronauta astronauta(cpf, nome, idade);
                        cout << endl << "Astronauta cadastrado: " << endl;
                        cout << "   CPF: " << astronauta.getCPF() << endl;
                        cout << "   Nome: " <<  astronauta.getNome() << endl;
                        cout << "   Idade: " << astronauta.getIdade() << endl;

                        astronautas.push_back(astronauta); // Armazenando astronauta em uma lista
                        break;
                    }    
                }  
            }

            case 2: {
                int numVoo, verificacao = 0;
                string destino;


                cout << "Codigo do voo: ";
                cin >> numVoo;

                for (auto& voo : voos) {
                    if (voo.getCodigo() == numVoo) {
                        cout << "Codigo de voo invalido" << endl;
                        verificacao = 1;
                        break;
                    }
                }

                if (verificacao == 1) {
                    cout << "Tente cadastrar outo voo" << endl;
                    break;
                }
                else {
                    cout << "Destino do voo: ";
                    cin.ignore(); // Ignora o caractere de nova linha pendente do cin >> numVoo
                    getline(cin, destino);

                    Voo novoVoo(numVoo, destino);
                    cout << "O voo com codigo " << novoVoo.getCodigo() << " com destino a " << novoVoo.getDestino() <<" ja esta em planejamento." << endl;

                    voos.push_back(novoVoo); // Armazenando Voo em lista

                    break;
                }
            }

            case 3: {
                cout << "Voos disponiveis (em planejamento): " << endl;

                for (const auto& voo : voos) {
                    if (voo.getStatus() == PLANEJANDO) {
                        cout << "   Voo Cod: " << voo.getCodigo() << endl;
                    }
                }

                cout << endl;

                int cod;
                cout << "Digite o codigo do Voo a ser adicionado Passageiros: ";
                cin >> cod;

                // Procurar Voo na lista de voos
                bool encontrado = false;
                for (auto it = voos.begin(); it != voos.end(); ++it) {
                    if (it->getCodigo() == cod && it->getStatus() == PLANEJANDO) {
                        cout << "Voo com destino a " << it->getDestino() << endl; // Diz qual o destino do voo

                        it->visualizarPassageiros(astronautas); // Passar a lista de astronautas como argumento
                        encontrado = true;
                        // Adicionar astronautas ao voo
                        while (true) {
                            string cpfAstronauta;
                            cout << "Digite o CPF do astronauta a ser adicionado ao voo ( [0] para sair ): ";
                            cin >> cpfAstronauta;
                            if (cpfAstronauta == "0") {
                                break;
                            }

                            bool astroFind = false;
                            for (auto& astronauta : astronautas) {
                                if (astronauta.getCPF() == cpfAstronauta && astronauta.getStatus() == VIVO && astronauta.getDisponibilidade()) {
                                    it->adicionarPassageiro(astronauta); // Adicionar passageiro ao voo encontrado
                                    astronauta.adicionarVoo(it->getCodigo());
                                    astronauta.setIndisponivel();
                                    astroFind = true; // Atualizar astroFind
                                    break;
                                }
                                else if (astronauta.getCPF() == cpfAstronauta && astronauta.getStatus() == MORTO){
                                    cout << "Este astronauta esta morto." << endl; // Verifica se o astronauta está morto
                                }
                                else if (astronauta.getCPF() == cpfAstronauta && !astronauta.getDisponibilidade()) {
                                    cout << "Este astronauta nao esta disponivel." << endl; // Verifica se o astronauta está indisponivel
                                }
                            }
                            if (astroFind) {
                                cout << endl << "Astronauta adicionado ao voo com sucesso!" << endl << endl;
                            }
                            else {
                                cout << "Astronauta nao localizado" << endl;
                            }
                        }
                        break; // Sair do loop de voos
                        }
                        else if (it->getCodigo() == cod && it->getStatus() == EMVOO) {
                            cout << endl << "O voo nao esta disponivel para se adicionar passageiros." << endl << endl;
                            break;
                        }
                }

                if (!encontrado) {
                    cout << "Voo nao encontrado!" << endl;
                }

                break;
            }

            case 4: {

                cout << "Voos disponiveis (em planejamento): " << endl;

                for (const auto& voo : voos) {
                    if (voo.getStatus() == PLANEJANDO) {
                        cout << "   Voo Cod: " << voo.getCodigo() << endl;
                    }
                }

                cout << endl;

                int cod;
                cout << "Digite o codigo do voo do qual deseja remover passageiros: ";
                cin >> cod;

                // Procurar o voo na lista de voos
                bool encontrado = false;
                for (auto& voo : voos) {
                    if (voo.getCodigo() == cod && voo.getStatus() == PLANEJANDO) {
                        encontrado = true;

                        // Exibir os passageiros do voo
                        cout << "Passageiros do voo [" << cod << "]:" << endl;
                        cout << endl;
                        voo.visualizarPassageiros(astronautas);
                        cout << endl;

                        // Remover passageiros
                        while (true) {
                            string cpfPassageiro;
                            cout << "Digite o CPF do passageiro que deseja remover ( [0] para sair ): ";
                            cin >> cpfPassageiro;

                            if (cpfPassageiro == "0") {
                                break;
                            }

                            // Remover o passageiro do voo
                            voo.removerPassageiro(cpfPassageiro);

                            // Atualizar o histórico de voos do passageiro 
                            for (auto& astronauta : astronautas) {
                                if (astronauta.getCPF() == cpfPassageiro) {
                                    astronauta.setDisponivel(); 
                                    auto& historico = astronauta.getHistoricoVoos(); // Obtém uma referência constante ao histórico de voos
                                    list<int> historicoModificado = historico; // Faz uma cópia do histórico de voos
                                    historicoModificado.remove(cod); // Remove o código do voo da cópia
                                    astronauta.setHistoricoVoos(historicoModificado); // Atualiza o histórico de voos do astronauta com a cópia modificada
                                    break;
                                }
                            }

                            cout << "Passageiro removido com sucesso!" << endl;
                        }

                        break; // Sair do loop de voos
                    }
                    else if (voo.getCodigo() == cod && voo.getStatus() != PLANEJANDO) {
                        cout << "O voo nao esta disponivel para remover passageiros." << endl << endl;
                        break;
                    }
                }

                if (!encontrado) {
                    cout << "Voo nao encontrado!" << endl;
                }

                break;
            }

            case 5: {

                cout << "Voos cadastrados:" << endl;

                for (const auto& voo : voos) {  // O for percorre a lista de voos cadastrados

                    if (voos.empty()) {
                        cout << "Nao ha voos cadastrados" << endl;
                        break;
                    }
                    else {
                        cout << "Codigo do Voo: " << voo.getCodigo() << endl;  // imprime as insformações do voo a partir do seu código (funciona como uma key)
                        cout << "   Status do Voo: ";
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

                        if (voo.getDispo()) cout << "   O voo esta disponivel" << endl;
                        else cout << "   O voo esta indisponivel" << endl;

                        cout << "   Destino do voo: " << voo.getDestino() << endl; // informa o destino do voo

                        voo.visualizarPassageiros(astronautas);

                        cout << endl;
                    }    
                }
                break;
            }

            case 6: {
                cout << "Voos disponiveis para lancamento: " << endl;

                for (const auto& voo : voos) {
                    if (voo.getStatus() == PLANEJANDO) {
                        cout << "   Voo Cod: " << voo.getCodigo() << endl;
                    }
                }

                cout << endl;


                int cod;
                cout << "Digite o codigo do voo a ser lancado: ";
                cin >> cod;

                bool encontrado = false;

                // Percorrer a lista de voos
                for (auto it = voos.begin(); it != voos.end(); ++it) { // Passagem por refêrencia
                    if (it->getCodigo() == cod && it->getStatus() == PLANEJANDO) {
                        it->lancarVoo(); // Chamar a função lancarVoo() neste voo
                        encontrado = true;
                        break;
                    }
                    else if (it->getCodigo() == cod && it->getStatus() == EMVOO) {
                        cout << "O voo ja foi lancado." << endl;
                        cout << "Ele esta a caminho de  " << it->getDestino() << endl;
                        break;
                    }
                    else if (it->getCodigo() == cod && it->getStatus() == DESTRUIDO) {
                        cout << "O voo foi explodido." << endl;
                        break;
                    }
                }

                if (!encontrado) {
                    cout << "Voo nao encontrado!" << endl;
                }
                break;
            }

            case 7: {

                cout << "Voos disponiveis para finalizar: " << endl;

                for (const auto& voo : voos) {
                    if (voo.getStatus() == EMVOO) {
                        cout << "   Voo Cod: " << voo.getCodigo() << endl;
                    }
                }

                cout << endl;


                int cod;
                cout << "Digite o codigo do voo a ser finalizado: ";
                cin >> cod;

                bool encontrado = false;

                // Percorrer a lista de voos
                for (auto& voo : voos) {
                    if (voo.getCodigo() == cod && voo.getStatus() == EMVOO) {
                        voo.finalizarVoo(); // Chamar a função finalizarVoo() neste voo
                        encontrado = true;
                        cout << "Voo finalizado com sucesso!" << endl;
                        break;
                    }
                    else if (voo.getCodigo() == cod && voo.getStatus() != EMVOO ) {
                        cout << "O voo não está disponivel para finalizar." << endl;
                        break;
                    }
                }
            

                if (!encontrado) {
                    cout << "Voo nao encontrado!" << endl;
                }

                break;
            }

            case 8: {
                cout << "Astronautas Cadastrados:" << endl << endl;

                if (astronautas.empty()) {
                    cout << "Nao ha astronautas cadastrados." << endl;
                }
                else {
                    for (auto& astronauta : astronautas) {
                        cout << "Nome: " << astronauta.getNome() << endl;
                        cout << "CPF: " << astronauta.getCPF() << endl;
                        cout << "Idade: " << astronauta.getIdade() << endl;
                        if (astronauta.getDisponibilidade()) cout << "Status: Disponivel" << endl;
                        else cout << "Status: Indisponivel" << endl;
                        cout << "Ultimo voo cadastrado: ";
                        if (astronauta.getHistoricoVoos().empty()) {
                            cout << "O astronauta nao esteve cadastrado em nenhum voo" << endl;
                        }
                        else {
                            cout << astronauta.getHistoricoVoos().back() << endl;
                        }
                        
                        cout << endl;
                    }
                }
                cout << endl;

                break;
            }
            case 9: {
                // Menções Honrosas para os astronautas tiveram os status alterados para mortos
                
                cout << "Mencoes Honrosas a" << endl << endl;;

                // Acessar a lista de astronautas mortos do cemitério
                const list<Astronauta>& astronautasMortos = Cemiterio::getAstronautasMortos();

                // Iterar sobre a lista de astronautas mortos e imprimir menções honrosas
                for (const auto& astronauta : astronautasMortos) {
                    cout << "   O astronauta " << astronauta.getNome() << " morreu bravamente" << endl;
                    cout << "   Aqui esta a lista de voos em que ele participou:" << endl;
                    for (const auto& cods : astronauta.getHistoricoVoos()) {
                        cout << "       Voo " << cods << endl;
                    }
                    cout << endl;
                }
                cout << endl;
                cout << endl << "Esses foram os herois que deram sua vida voando conosco" << endl << endl;

                break;
            }
            default:
                cout << "Saindo..." << endl;
                controle = 1;
                break;
        }
        cout << endl;
        cout << endl;
    }
    return 0;
}