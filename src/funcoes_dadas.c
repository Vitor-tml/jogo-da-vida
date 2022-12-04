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

void limpaMatriz(Tabuleiro tab)
{
    int i, j;
    for (i = 0; i < tam.nL; i++)
        for (j = 0; j < tam.nC; j++)
            tab.m[i][j] = VAZ;
}
/*
void menuInicJogo(int **mat, int nL, int nC)
{
    int opcao;

    printf("(1)Bloco\n(2)Blinker\n(3)Sapo\n(4)Glider\n(5)LWSS\nEntre com a opcao: ");
    scanf("%d", &opcao);
    switch (opcao)
    {
        case 1:
            inicBloco(mat, nL, nC);
            break;
        case 2:
            inicBlinker(mat, nL, nC);
            break;
        case 3:
            inicSapo(mat, nL, nC);
            break;
        case 4:
            inicGlider(mat, nL, nC);
            break;
        case 5:
            inicLWSS(mat, nL, nC);
            break;
    }

    imprimeMatriz(mat, nL, nC, 0, 0, 0);

    printf("Se inicializacao correta digite qualquer tecla para iniciar o jogo...");
    while (getchar() != '\n');
        getchar();
}
*/

void jogaJogoVida(int **mAtual, int nL, int nC, int nCiclos) // Jogo real
{
    int **mAnt;
    int c;

    system("cls");
    imprimeMatriz(mAtual, nL, nC, 0, 0, 0);
    // getchar();
    Sleep(100);     //*========== Adaptar para win e linux

    mAnt = alocaMatriz(nL, nC);
    for (c = 1; c <= nCiclos; c++)
    { 
        copiaMatriz(mAnt, mAtual, nL, nC);
        atualizaMat(mAtual, mAnt, nL, nC); //===== REGRAS do jogo
        system("cls");                      //====== Mudar para compatível com as duas plataformas
        imprimeMatriz(mAtual, nL, nC, 0, 0, 0);
        // getchar(); // Pausa a cada geração
        Sleep(100);
    }
    desalocaMatriz(mAnt, nL);
}