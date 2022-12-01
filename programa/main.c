#include <stdio.h>
#include <stdlib.h> // Verificar quais precisam estar aqui ou nao
#include "funcoes.h"
#include "formas_de_vida.h"
#include "funcoes_dadas.h"

#ifdef _WIN32
#include <Windows.h>
#define LIMPA "cls"
#else
#include <unistd.h>
#define LIMPA "clear"
#endif

#define ORG 1 // Organismo
#define VAZ 0 // Vazio
#define TAM 101 // Tamanho do nome do jogo.

typedef struct tab
{                       // implementar como TAD, o tupedef fica no .h
    char nomeJogo[TAM]; // o nome do jogo deve ser relativo ao padrao
                        // de inicializacao. Por exemplo, JogoSapo ou JogoBloco
    int ciclosVida;     // Define quanto cada jogo vai rodar (ciclos)
    int dim1, dim2;     // dimensoes do tabuleiro linhas x colunas
    char **m;           // Atenção! Essa matriz terá que ser alocada dinamicamente
                        // para que a funcao que inicializa possa funcionar
} Tab;

int main()
{
    int **mat;

    int nl = 20, nc = 20, nCiclos = 50;
    int jogando = 1;
    mat = alocaMatriz(nl, nc);

    printf("Entre com o tamanho do tabuleiro: ");
    scanf("%d %d", &nl, &nc);
    printf("Entre com o numero de cilcos: ");
    scanf("%d", &nCiclos);

    do // Loop de vários jogos, até que o usuário queira sair.
    {
        menuInicJogo(mat, nl, nc);
        jogaJogoVida(mat, nl, nc, nCiclos); // Joga e exibe 1 jogo na tela.
    } while (jogando); //========================= criar essa variável

    desalocaMatriz(mat, nl);
}