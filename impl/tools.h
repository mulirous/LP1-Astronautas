#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <list>
#include "voo.h"

using namespace std;


void limpaTela();
void pausaParaLeitura();
void buscarVooPorDestino(const list<Voo>& voos, const list<Astronauta>& astronautas);

#endif 