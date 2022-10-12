#include <stdio.h>
#define TAMANHO 15

void imprimeTabuleiro(int tabuleiro[TAMANHO][TAMANHO]);
void copiaTabuleiro(int tab1[TAMANHO][TAMANHO], int tab2[TAMANHO][TAMANHO]);
int calculaVizinhos(int tabuleiro[TAMANHO][TAMANHO], int x, int y);
int sobrevivencia(int tabuleiro[TAMANHO][TAMANHO], int x, int y);
void jogaJogo(int tabuleiro[TAMANHO][TAMANHO]);

int main()
{
    int vida[TAMANHO][TAMANHO] = {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    };

    imprimeTabuleiro(vida);
    jogaJogo(vida);
    printf("-------------------------------\n");
    imprimeTabuleiro(vida);
    printf("\n%d -> %d", vida[0][2], calculaVizinhos(vida, 0, 2));
}

void imprimeTabuleiro(int tabuleiro[TAMANHO][TAMANHO])
{
    int i, j;

    for ( i = 0; i < TAMANHO; i++)
    {
        for ( j = 0; j < TAMANHO; j++)
        {
            printf("%c ", tabuleiro[i][j]? 'x': 'o');
        }
        printf("\n");
    }
    return;
}

int calculaVizinhos(int tabuleiro[TAMANHO][TAMANHO], int x, int y)
{
    int estado, vizinhos;

    estado = tabuleiro[x][y];
    tabuleiro[x][y] = 0;

    vizinhos =  tabuleiro[x - 1][y - 1] * (x!=0) * (y != 0)             +
                tabuleiro[x - 1][y] * (x!=0)                            +
                tabuleiro[x - 1][y + 1] * (x!=0) * (y != TAMANHO - 1)   +

                tabuleiro[x][y - 1] * (y != 0)                          +           
                tabuleiro[x][y + 1] * (y != TAMANHO - 1)                +

                tabuleiro[x + 1][y - 1] * (x != TAMANHO - 1) * (y != 0) +
                tabuleiro[x + 1][y] * (x != TAMANHO - 1)                +
                tabuleiro[x + 1][y + 1] * (x != TAMANHO - 1) * (y != TAMANHO - 1);
    tabuleiro[x][y] = estado;
    return vizinhos;
}

int sobrevivencia(int tabuleiro[TAMANHO][TAMANHO], int x, int y)
{
    int vizinhos = calculaVizinhos(tabuleiro, x, y);
    int estado = tabuleiro[x][y];

    if(estado)
        return (vizinhos == 2 || vizinhos == 3)? 1: 0;
    else
        return (vizinhos >= 3)? 1: 0;
    return;
}

void jogaJogo(int tabuleiro[TAMANHO][TAMANHO])
{
    int temp[TAMANHO][TAMANHO];
    int i, j;

    for ( i = 0; i < TAMANHO; i++)
        for ( j = 0; j < TAMANHO; j++)
            temp[i][j] = sobrevivencia(tabuleiro, i, j);
    
    copiaTabuleiro(tabuleiro, temp);
    return 0;
}

void copiaTabuleiro(int tab1[TAMANHO][TAMANHO], int tab2[TAMANHO][TAMANHO])
{
    int i, j;

    for ( i = 0; i < TAMANHO; i++)
        for ( j = 0; j < TAMANHO; j++)
            tab1[i][j] = tab2[i][j];

    return;   
}