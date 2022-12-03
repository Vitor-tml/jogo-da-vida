#ifndef _FUNCOES_
#define _FUNCOES_

int **alocaMatriz(int nl, int nc);
void desalocaMatriz(int **m, int nl);
void imprimeMatriz(int **m, int nl, int nc, int linhaDestaque, int colunaDestaque, int destaque);
int sobrevivencia(int estado, int vizinhos);
void copiaMatriz(int **m1, int **m2, int nl, int nc);
int calculaVizinhos(int **tabuleiro, int nl, int nc, int x, int y);
void atualizaMat(int **mAtual, int **mAnt, int nl, int nc);

void asciiArt();
int estruturaMenu(int nl, int nc, int nciclos, char nomePadrao[TAM])
void mudaPadrao();
void mudaTamanho();

typedef struct tab // Testar se essa declaração com valor funciona
{
    char nomeJogo[TAM] = "nenhum";
    int ciclosVida = 50;
    int nl = 15;
    int nc = 15;
    char **m;
} Tabuleiro;

#endif