#include "formas_de_vida.h"
#include "funcoes_dadas.h"
#define ORG 1 // Organismo
#define VAZ 0 // Vazio

void inicBlinker(int **m, int nL, int nC)
{
    int padrao[1][3] = {{ORG, ORG, ORG}};
    int i, j, xInic = nL / 2, yInic = nC / 2;

    limpaMatriz(m, nL, nC);

    for (i = 0; i < 1; i++)
        for (j = 0; j < 3; j++)
            m[xInic + i][yInic + j] = padrao[i][j];
}

void inicBloco(int **m, int nL, int nC)
{
    int padrao[2][2] = {{ORG, ORG},
                         {ORG, ORG}};
    int i, j, xInic = nL / 2, yInic = nC / 2;

    limpaMatriz(m, nL, nC);

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            m[xInic + i][yInic + j] = padrao[i][j];
}

void inicSapo(int **m, int nL, int nC)
{

    int padrao[2][4] = {{VAZ, ORG, ORG, ORG},
                        {ORG, ORG, ORG, VAZ}};
    int i, j, xInic = nL / 2, yInic = nC / 2;

    limpaMatriz(m, nL, nC);

    for (i = 0; i < 2; i++)
        for (j = 0; j < 4; j++)
            m[xInic + i][yInic + j] = padrao[i][j];
}

void inicGlider(int **m, int nL, int nC)
{
    int padrao[3][3] = {{ORG, ORG, ORG},
                        {ORG, VAZ, VAZ},
                         {VAZ, ORG, VAZ}};
    int i, j, xInic, yInic;

    limpaMatriz(m, nL, nC);

    xInic = nL - 4;
    yInic = nC - 4;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            m[xInic + i][yInic + j] = padrao[i][j];
}

void inicLWSS(int **m, int nL, int nC)
{
    int padrao[4][5] = {{VAZ, ORG, VAZ, VAZ, ORG}, 
                        {ORG, VAZ, VAZ, VAZ, VAZ}, 
                        {ORG, VAZ, VAZ, VAZ, ORG}, 
                        {ORG, ORG, ORG, ORG, VAZ}};
    int i, j, xInic, yInic;

    limpaMatriz(m, nL, nC);

    xInic = nL - 5;
    yInic = nC - 6;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 5; j++)
            m[xInic + i][yInic + j] = padrao[i][j];
}