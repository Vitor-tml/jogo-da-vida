#include <stdio.h>
#define TAMANHO 15

void imprimeTabuleiro(int tabuleiro[TAMANHO][TAMANHO]);
int calculaVizinhos(int tabuleiro[TAMANHO][TAMANHO], int x, int y);
void sobrevivencia(int tabuleiro[TAMANHO][TAMANHO], int x, int y);

int main()
{
    int vida[TAMANHO][TAMANHO] = {
        0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,
        0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,
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
    sobrevivencia(vida, 0, 2);
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

void sobrevivencia(int tabuleiro[TAMANHO][TAMANHO], int x, int y)
{
    int vizinhos = calculaVizinhos(tabuleiro, x, y);
    int estado = tabuleiro[x][y];

    if(estado)
        tabuleiro[x][y] = (vizinhos == 2 || vizinhos == 3)? 1: 0;
    else
        tabuleiro[x][y] = (vizinhos >= 3)? 1: 0;
    return;
}