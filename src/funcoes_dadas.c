#include <stdio.h>
#include "funcoes_dadas.h"
#include "funcoes.h"
#include "formas_de_vida.h"

#ifdef _WIN32
#include <Windows.h>
#define LIMPA "cls"
#else
#include <unistd.h>
#define LIMPA "clear"
#endif

#define ORG 1 // Organismo
#define VAZ 0 // Vazio

void limpaMatriz(Tabuleiro *tab)
{
    int i, j;
    for (i = 0; i < tab->nl; i++)
        for (j = 0; j < tab->nc; j++)
            tab->m[i][j] = VAZ;
}
/*
void menuInicJogo(int **mat, int nl, int nc)
{
    int opcao;

    printf("(1)Bloco\n(2)Blinker\n(3)Sapo\n(4)Glider\n(5)LWSS\nEntre com a opcao: ");
    scanf("%d", &opcao);
    switch (opcao)
    {
        case 1:
            inicBloco(mat, nl, nc);
            break;
        case 2:
            inicBlinker(mat, nl, nc);
            break;
        case 3:
            inicSapo(mat, nl, nc);
            break;
        case 4:
            inicGlider(mat, nl, nc);
            break;
        case 5:
            inicLWSS(mat, nl, nc);
            break;
    }

    imprimeMatriz(mat, nl, nc, 0, 0, 0);

    printf("Se inicializacao correta digite qualquer tecla para iniciar o jogo...");
    while (getchar() != '\n');
        getchar();
}
*/

void jogaJogoVida(Tabuleiro*tab) // Jogo real
{
    Tabuleiro proximoTab;
    int c;

    system("cls");
    imprimeMatriz(*tab, 0, 0, 0);
    // getchar();
    Sleep(100);     //*========== Adaptar para win e linux

    proximoTab = *tab;
    alocaMatriz(tab);

    for (c = 1; c <= tab->nciclos; c++)
    { 
        copiaMatriz(proximoTab.m, *tab);
        atualizaMat(*tab, &proximoTab); //===== REGRAS do jogo
        system("cls");                      //====== Mudar para compatível com as duas plataformas
        imprimeMatriz(*tab, 0, 0, 0);
        // getchar(); // Pausa a cada geração
        Sleep(100);
    }
    desalocaMatriz(proximoTab.m, tab->nl);
}