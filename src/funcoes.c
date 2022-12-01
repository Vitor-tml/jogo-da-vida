#include <stdlib.h>
#include "funcoes.h"

// Códigos de escape ASCII para as cores
#define SELEC "\x1B[46;1m"
#define MORTO "\x1B[0;31m"
#define VIVO "\x1B[0;32m"
#define RESET "\x1B[0m"


// Aloca uma matriz por valor passando o numero de linhas e colunas.
int **alocaMatriz(int nl, int nc)
{
    int **m, i;

    m = (int **) calloc(nl, sizeof(int*));
    if(m == NULL)
    {
        printf("Erro ao alocar matriz\n");
        exit(1);
    }

    for(i = 0; i < nl; i++)
    {
        m[i] = (int *) calloc(nc, sizeof(int));
        if(m[i] == NULL)
        {
            printf("Erro ao alocar a linha %d\n", i);
            exit(1);
        }
    }
    return m;
}
// Desaloca uma matriz passando seu endereço e o numero de linhas
void desalocaMatriz(int **m, int nl)
{
    int i;

    for(i = 0; i < nl; i++)
        free(m[i]);
    free(m);
}
// Imprime X para as cẽlulas vivas, O para as cẽlulas mortar e muda a cor de fundo da linha/coluna destaque
void imprimeMatriz(int **m, int nl, int nc, int linhaDestaque, int colunaDestaque, int destaque)
{
    int i, j;

    for(i = 0; i < nl; i++)
    {
        for(j = 0; j < nc; j++)
        {
            if((i == linhaDestaque || j == colunaDestaque) && destaque)
                printf(SELEC);
            else
                if(m[i][j])
                    printf(VIVO);
                else
                    printf(MORTO);
            printf(" %c ", m[i][j]? 'x': 'o');
            printf(RESET);
        }
        printf("\n");
    }
}
// Copia o tabuleiro em outra matriz
void copiaMatriz(int **m1, int **m2, int nl, int nc)
{
    int i, j;

    for ( i = 0; i < nl; i++)
        for ( j = 0; j < nc; j++)
            m1[i][j] = m2[i][j];
}
// Calcula as células vizinhas de tabuleiro[x][y].
int calculaVizinhos(int **celula, int nl, int nc, int x, int y)
{
    int vizinhos;

    vizinhos =  celula[x - 1][y - 1] * (x!=0) * (y != 0)             +
                celula[x - 1][y]     * (x!=0)                        +
                celula[x - 1][y + 1] * (x!=0) * (y != nc - 1)        +

                celula[x][y - 1] * (y != 0)                          +           
                celula[x][y + 1] * (y != nc - 1)                     +

                celula[x + 1][y - 1] * (x != nl - 1) * (y != 0)      +
                celula[x + 1][y]     * (x != nl - 1)                 +
                celula[x + 1][y + 1] * (x != nl - 1) * (y != nc - 1);
    
    return vizinhos;
}
// Calcula se uma célula vai viver ou morrer de acordo com o estado atual e os vizinhos
int sobrevivencia(int estado, int vizinhos)
{
    if(estado)
        return (vizinhos == 2 || vizinhos == 3)? 1: 0;
    else
        return (vizinhos == 3)? 1: 0;
}
// Aplica as regras do jogo no tabuleiro
void atualizaMat(int **mAtual, int **mAnt, int nl, int nc)
{
    int i, j, vizinhos;

    for(i = 0; i < nl; i++)
        for(j = 0; j < nc; j++)
        {
            vizinhos = calculaVizinhos(mAnt, nl, nc, i, j);
            mAtual[i][j] = sobrevivencia(mAnt[i][j], vizinhos);
        }
}