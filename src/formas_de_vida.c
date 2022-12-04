#include "formas_de_vida.h"
#include "funcoes_dadas.h"
#include "funcoes.h"
#define ORG 1 // Organismo
#define VAZ 0 // Vazio


  
void inicBlinker(Tabuleiro *blinker)
{
    int padrao[1][3] = {{ORG, ORG, ORG}};
    int i, j, xInic = blinker->nl / 2, yInic = blinker->nc / 2;

    limpaMatriz(&blinker);

    for (i = 0; i < 1; i++)
        for (j = 0; j < 3; j++)
            blinker->m[xInic + i][yInic + j] = padrao[i][j];
}

void inicBloco(Tabuleiro *bloco)
{
    int padrao[2][2] = {{ORG, ORG},
                         {ORG, ORG}};
    int i, j, xInic = bloco->nL / 2, yInic = bloco->nC / 2;

    limpaMatriz(&bloco);

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            bloco->m[xInic + i][yInic + j] = padrao[i][j];
}

void inicColmeia(Tabuleiro *colmeia)
{
    int padrao[4][3] = {{VAZ, ORG, ORG,VAZ},
                         {ORG, VAZ, VAZ, ORG}
                        {VAZ, ORG, ORG, VAZ}};
    int i, j, xInic = colmeia->nL / 2, yInic = colmeia->nC / 2;

    limpaMatriz(&colmeia);

    for (i = 0; i < 4; i++)
        for (j = 0; j < 3; j++)
            bloco->m[xInic + i][yInic + j] = padrao[i][j];
}


void inicSapo(Tabuleiro *sapo)
{

    int padrao[2][4] = {{VAZ, ORG, ORG, ORG},
                        {ORG, ORG, ORG, VAZ}};
    int i, j, xInic = sapo->nL / 2, yInic = sapo->nC / 2;

    limpaMatriz(&sapo);

    for (i = 0; i < 2; i++)
        for (j = 0; j < 4; j++)
            sapo->m[xInic + i][yInic + j] = padrao[i][j];
}

void inicGlider(Tabuleiro *glider)
{
    int padrao[3][3] = {{ORG, ORG, ORG},
                        {ORG, VAZ, VAZ},
                         {VAZ, ORG, VAZ}};
    int i, j, xInic, yInic;

    limpaMatriz(&glider);

    xInic = glider->nL - 4;
    yInic = glider->nC - 4;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            glider->m[xInic + i][yInic + j] = padrao[i][j];
}

void inicLWSS(Tabuleiro *LWSS)
{
    int padrao[4][5] = {{VAZ, ORG, VAZ, VAZ, ORG}, 
                        {ORG, VAZ, VAZ, VAZ, VAZ}, 
                        {ORG, VAZ, VAZ, VAZ, ORG}, 
                        {ORG, ORG, ORG, ORG, VAZ}};
    int i, j, xInic, yInic;

    limpaMatriz(&LWSS);

    xInic = LWSS->nL - 5;
    yInic = LWSS->nC - 6;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 5; j++)
            LWSS->m[xInic + i][yInic + j] = padrao[i][j];
}