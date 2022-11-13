#include <stdlib.h>
#define SELEC "\x1B[46;1m"
#define MORTO "\x1B[0;31m"
#define VIVO "\x1B[0;31m"
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
// Imprime X para as cẽlulas vivas, O para as cẽlulas mortar e muda a cor de fundo da linha/coluna destaque
void imprimeTabuleiro(int **m, int nl, int nc, int linhaDestaque, int colunaDestaque, int destaque)
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
void copiaTabuleiro(int **tab1, int **tab2, int nl, int nc)
{
    int i, j;

    for ( i = 0; i < nl; i++)
        for ( j = 0; j < nc; j++)
            tab1[i][j] = tab2[i][j];

    return;   
}
// Calcula as células vizinhas de tabuleiro[x][y].
int calculaVizinhos(int **tabuleiro, int nl, int nc, int x, int y)
{
    int estado, vizinhos;

    estado = tabuleiro[x][y];
    tabuleiro[x][y] = 0;

    vizinhos =  tabuleiro[x - 1][y - 1] * (x!=0) * (y != 0)             +
                tabuleiro[x - 1][y]     * (x!=0)                        +
                tabuleiro[x - 1][y + 1] * (x!=0) * (y != nc - 1)        +

                tabuleiro[x][y - 1] * (y != 0)                          +           
                tabuleiro[x][y + 1] * (y != nc - 1)                     +

                tabuleiro[x + 1][y - 1] * (x != nl - 1) * (y != 0)      +
                tabuleiro[x + 1][y]     * (x != nl - 1)                 +
                tabuleiro[x + 1][y + 1] * (x != nl - 1) * (y != nc - 1);
    
    tabuleiro[x][y] = estado;
    return vizinhos;
}
// Calcula se a cálula tabuleiro[x][y] vai estar viva na próxima geração.
int sobrevivencia(int **tabuleiro, int nl, int nc, int x, int y)
{
    int vizinhos = calculaVizinhos(tabuleiro, nl, nc, x, y);
    int estado = tabuleiro[x][y];

    if(estado)
        return (vizinhos == 2 || vizinhos == 3)? 1: 0;
    else
        return (vizinhos >= 3)? 1: 0;
}
// Calcula próxima geração e escreve no tabuleiro atual
void jogaJogo(int **tabuleiro, int nl, int nc)
{
    int **temp;
    int i, j;

    temp = alocaMatriz(nl, nc);
    for ( i = 0; i < nl; i++)
        for ( j = 0; j < nc; j++)
            temp[i][j] = sobrevivencia(tabuleiro, nl, nc, i, j);
    
    copiaTabuleiro(tabuleiro, temp, nl, nc);
    free(temp);
}
//
void leCelula(int **tabuleiro, )