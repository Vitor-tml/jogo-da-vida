#ifdef _WIN32
    #include <windows.h>
    #define LIMPA "cls"
#else
    #define LIMPA "clear"
#endif
#include "funcoes.c"

int **alocaMatriz(int nl, int nc);
void imprimeTabuleiro(int **m, int nl, int nc, int linhaDestaque, int colunaDestaque, int destaque);
void jogaJogo(int **tabuleiro, int nl, int nc);
int sobrevivencia(int **tabuleiro, int nl, int nc, int x, int y);
void copiaTabuleiro(int **tab1, int **tab2, int nl, int nc);
int calculaVizinhos(int **tabuleiro, int nl, int nc, int x, int y);