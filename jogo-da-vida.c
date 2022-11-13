#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#define TAM 15
int main()
{
    int **tabuleiro;
    int nl, nc;

    do{
        printf("Entre com a quantidade de linhas e colunas do tabuleiro(apenas valores entre 15 e 150): ");
        scanf("%d", &tamanhoTabuleiro);
    }while(tamanhoTabuleiro < 2 || tamanhoTabuleiro > 30);
    tabuleiro = alocaMatriz()
}