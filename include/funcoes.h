#ifndef _FUNCOES_
#define _FUNCOES_
#define TAM 101

typedef struct tab // Testar se essa declaração com valor funciona
{
    char nomeJogo[TAM];
    int nciclos;
    int nl;
    int nc;
    int **m;
}Tabuleiro;

void alocaMatriz(Tabuleiro*tab);
void desalocaMatriz(int **m, int nl);
void imprimeMatriz(Tabuleiro *tab, int linhaDestaque, int colunaDestaque, int destaque);
void copiaMatriz(Tabuleiro *m, Tabuleiro *tab);
void atualizaMat(Tabuleiro tab, Tabuleiro *novaGeracao);
void asciiArt();
void printbarra(int n, int tipo);
void menuInicJogo(Tabuleiro*tab); 
void mudaTamanho(Tabuleiro*tab);
void leCSV(Tabuleiro *tab, char nomeDoArquivo[TAM + 4]);
void entradaArquivo(Tabuleiro *tab);
int sobrevivencia(int estado, int vizinhos);
int calculaVizinhos(Tabuleiro celula, int x, int y);
int estruturaMenu(Tabuleiro *tab);
const char *centerAlignText(char *field, unsigned int fieldWidth, const char *text);

#endif