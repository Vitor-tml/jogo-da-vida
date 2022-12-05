#include <stdlib.h>
#include <stdio.h>
#include "formas_de_vida.h"
#include "funcoes_dadas.h"
#include "funcoes.h"
//#define ORG 1 // Organismo
//#define VAZ 0 // Vazio

int ORG = 1;
int VAZ = 0;
void inicBlinker(Tabuleiro *blinker)
{
    int padrao[1][3] = {{ORG, ORG, ORG}};
    int i, j;
    int xInic = blinker->nl / 2, yInic = blinker->nc / 2;
    if(blinker->nl < 3 || blinker->nc < 6)
    {
        xInic = 0;
        yInic = 0;
    }
    limpaMatriz(blinker);

    for (i = 0; i < 1; i++)
        for (j = 0; j < 3; j++)
            blinker->m[xInic + i][yInic + j] = padrao[i][j];
}

void inicBloco(Tabuleiro *bloco)
{
    int padrao[2][2] = {{ORG, ORG},
                        {ORG, ORG}};
    int i, j, xInic = bloco->nl / 2, yInic = bloco->nc / 2;
    if(bloco->nl < 4 || bloco->nc < 4)
    {
        xInic = 0;
        yInic = 0;
    }
    limpaMatriz(bloco);

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            bloco->m[xInic + i][yInic + j] = padrao[i][j];
}

void inicColmeia(Tabuleiro *colmeia)
{
    int padrao[3][4] = {{VAZ, ORG, ORG, VAZ},
                        {ORG, VAZ, VAZ, ORG},
                        {VAZ, ORG, ORG, VAZ}};
    int i, j, xInic = colmeia->nl / 2, yInic = colmeia->nc / 2;
    if(colmeia->nl < 6 || colmeia->nc < 8)
    {
        xInic = 0;
        yInic = 0;
    }
    limpaMatriz(colmeia);

    for (i = 0; i < 4; i++)
        for (j = 0; j < 3; j++)
            colmeia->m[xInic + i][yInic + j] = padrao[i][j];
}

void inicSapo(Tabuleiro *sapo)
{

    int padrao[2][4] = {{VAZ, ORG, ORG, ORG},
                        {ORG, ORG, ORG, VAZ}};
    int i, j, xInic = sapo->nl / 2, yInic = sapo->nc / 2;
    
    if(sapo->nl < 4 || sapo->nc < 8)
    {
        xInic = 0;
        yInic = 0;
    }
    limpaMatriz(sapo);

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
    
    limpaMatriz(glider);

    xInic = glider->nl - 4;
    yInic = glider->nc - 4;

    if(glider->nl < 6 || glider->nc < 6)
    {
        xInic = 0;
        yInic = 0;
    }

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
    
    limpaMatriz(LWSS);

    xInic = LWSS->nl - 5;
    yInic = LWSS->nc - 6;

    if(LWSS->nl < 8 || LWSS->nc < 10)
    {
        xInic = 0;
        yInic = 0;
    }

    for (i = 0; i < 4; i++)
        for (j = 0; j < 5; j++)
            LWSS->m[xInic + i][yInic + j] = padrao[i][j];
}