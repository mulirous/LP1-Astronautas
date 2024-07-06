#include "../../impl/cemiterio.h"

list<Astronauta> Cemiterio::astronautasMortos;  // Inicializa sua lista de astronautas com o status de morto

Cemiterio::Cemiterio() {  // Construtor da classe Cemitério
    astronautasMortos = list<Astronauta>();
}

void Cemiterio::adicionarMorto(const Astronauta& astronauta) {  // Método que adiciona os astronautas de status morto ao final de sua lista
    astronautasMortos.push_back(astronauta);
}

const list<Astronauta>& Cemiterio::getAstronautasMortos() {  // Método que retorna a lista de astronautas de status morto
    return astronautasMortos;
}
