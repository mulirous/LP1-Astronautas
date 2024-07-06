#ifndef VOO_H
#define VOO_H

#include <list>
#include <string>
#include "astronauta.h"
#include "enumAstro.h"
#include "enumVoo.h"

using namespace std;

class Voo {
private:
    int codigoVoo;
    bool dispo = true;
    list<Astronauta> passageiros;
    vooStatus status = PLANEJANDO;
    string destino;

public:
    Voo(int codigo, const string& destinoNovo);

    int getCodigo() const;
    vooStatus getStatus() const;
    bool getDispo() const;
    string getDestino() const;
    void setStatus(vooStatus novoStatus);
    void setDestino(string novoDestino);
    void adicionarPassageiro(const Astronauta& astronauta);
    void lancarVoo();
    void visualizarPassageiros(const list<Astronauta>& astronautas) const;
    void removerPassageiro(const string& cpf);
    void finalizarVoo(list <Astronauta>& astronautas);
};

#endif
