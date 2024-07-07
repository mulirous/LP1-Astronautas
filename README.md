# LP1-Astronautas 🚀

Projeto da disciplina de Linguagem de Programação 1 (IMD0030), implementado em C++.

## Requisitos

Antes de iniciar, certifique-se de ter o compilador g++ instalado na sua máquina. Você pode instalar o g++ usando os comandos apropriados para seu sistema operacional.

## Como Compilar e Executar

1. **Compilação:**

    No terminal, navegue até o diretório onde estão os arquivos fonte e execute o seguinte comando para compilar o programa:


<code>      g++ ./src/main.cpp ./src/mod/astronauta.cpp ./src/mod/cemiterio.cpp ./src/mod/voo.cpp ./src/mod/tools.cpp -o comando -g -W     </code>

    Esse comando compila todos os arquivos necessários e gera um executável chamado <strong>comando</strong>.

2. **Execução**

    Após compilar com sucesso o programa na sua máquina, basta apenas digitar:

<code>      ./comando       </code>

    Assim, você irá executar o programa no terminal da sua máquina.

<p>Para iniciar o programa basta digitar em seu terminal, dentro do caminho dos arquivos o seguinte comando:</p>


## Principais Funcionalidades

Este programa oferece várias funcionalidades relacionadas ao gerenciamento de astronautas e voos espaciais:
<ul>
    <li>**Cadastro de Astronautas** : Permite cadastrar novos astronautas com CPF único, nome e idade dentro de faixas específicas.</li>

    <li>**Cadastro de Voos** : Possibilita o registro de novos voos com código único e destino.</li>

    <li>**Registro de Passageiros**  em um Voo: Permite adicionar astronautas a voos planejados, gerenciando suas disponibilidades.</li>

    <li>**Remoção de Passageiros**  de um Voo: Permite remover astronautas de voos planejados, liberando suas disponibilidades.</li>

    <li>**Listagem de Voos** : Mostra todos os voos disponíveis, indicando seu status (planejando, em voo, finalizado).</li>

    <li>**Lançamento e Finalização de Voos**: Gerencia o ciclo de vida dos voos, permitindo o lançamento e a finalização conforme necessário.</li>

    <li>**Gerenciamento de Astronautas** : Permite listar todos os astronautas cadastrados, indicando seu estado (vivo ou morto).</li>

    <li>**Busca de Voo**  por Destino: Permite encontrar voos pelo destino especificado.</li>
</ul>