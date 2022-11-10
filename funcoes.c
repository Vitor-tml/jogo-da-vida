#include <stdio.h>
#include <stdlib.h>

#define RED "\x1B{31m"

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

void imprimeTabuleiro(int **m, int nl, int nc, int colunaDestaque, int linhaDestaque)
{
    int i, j;

    for(i = 0; i < nl; i++)
        for(j = 0; i < nc; i++)
        {
            if(i == linhaDestaque || j == colunaDestaque)
                printf()
        }
}