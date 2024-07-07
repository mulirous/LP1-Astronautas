# LP1-Astronautas 🚀

Projeto da disciplina de Linguagem de Programação 1 (IMD0030), implementado em C++.


## Requisitos

Antes de iniciar, certifique-se de ter o compilador g++ instalado na sua máquina. Você pode instalar o g++ usando os comandos apropriados para seu sistema operacional.

## Como Compilar e Executar

1. **Compilação:**

No terminal, navegue até o diretório onde estão os arquivos fonte e execute o seguinte comando para compilar o programa:

<code>g++ ./src/main.cpp ./src/mod/astronauta.cpp ./src/mod/cemiterio.cpp ./src/mod/voo.cpp ./src/mod/tools.cpp -o comando -g -W</code>

Esse comando compila todos os arquivos necessários e gera um executável chamado <strong>comando</strong>.

2. **Execução**

Após compilar com sucesso o programa na sua máquina, basta apenas digitar:

<code>./comando</code>

Assim, você irá executar o programa no terminal da sua máquina.


## Principais Funcionalidades

Este programa oferece várias funcionalidades relacionadas ao gerenciamento de astronautas e voos espaciais:
<ul>
<li><strong>Cadastro de Astronautas</strong>: Permite cadastrar novos astronautas com CPF único, nome e idade dentro de faixas escíficas.</li>
<li><strong>Cadastro de Voos</strong>: Possibilita o registro de novos voos com código único e destino.</li>
<li><strong>Registro de Passageiros  em um Voo</strong>: Permite adicionar astronautas a voos planejados, gerenciando suas disponibilidades.</li>
<li><strong>Remoção de Passageiros  de um Voo</strong>Remoção de Passageiros  de um Voo: Permite remover astronautas de voos planejados, liberando suas disponibidades.</li>
<li><strong>Listagem de Voos</strong>: Mostra todos os voos disponíveis, indicando seu status (planejando, em voo, finizado).</li>
<li><strong>Lançamento e Finalização de Voos</strong>: Gerencia o ciclo de vida dos voos, permitindo o lançamento e a finalização conforme necessário.</li>
<li><strong>Gerenciamento de Astronautas</strong>: Pmite listar todos os astronautas cadastrados, indicando seu estado (vivo ou morto).</li>
<li><strong>Busca de Voo  por Destino</strong>: Permite encotrar voos pelo destino especificado.</li>
</ul
