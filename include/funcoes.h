#ifndef _FUNCOES_
#define _FUNCOES_

void alocaMatriz(Tabuleiro*tab)
void desalocaMatriz(int **m, int nl); //  Exista um funcao desalocaTabuleiro em funcao.c
void imprimeMatriz(Tabuleiro tab, int linhaDestaque, int colunaDestaque, int destaque);
int sobrevivencia(int estado, int vizinhos);
void copiaMatriz(int **m, Tabuleiro tab);
int calculaVizinhos(Tabuleiro celula, int x, int y);
void atualizaMat(Tabuleiro tab, int **novaGeracao);

void asciiArt();
const char *centerAlignText(char *field, unsigned int fieldWidth, const char *text);
void printbarra(int n, int tipo);
int estruturaMenu(Tabuleiro tab);
void menuInicJogo(Tabuleiro*tab); 
void mudaTamanho(Tabuleiro*tab);

typedef struct tab // Testar se essa declaração com valor funciona
{
    char nomeJogo[TAM];
    int ciclosVida;
    int nl;
    int nc;
    int **m;
} Tabuleiro;

#endif