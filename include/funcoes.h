#ifndef _FUNCOES_
#define _FUNCOES_

int **alocaMatriz(int nl, int nc);
void imprimeTabuleiro(int **m, int nl, int nc, int linhaDestaque, int colunaDestaque, int destaque);
void jogaJogo(int **tabuleiro, int nl, int nc);
int sobrevivencia(int **tabuleiro, int nl, int nc, int x, int y);
void copiaTabuleiro(int **tab1, int **tab2, int nl, int nc);
int calculaVizinhos(int **tabuleiro, int nl, int nc, int x, int y);

#endif