#include <stdio.h> 
#include <stdlib.h> // Verificar quais precisam estar aqui ou nao

#ifdef _WIN32 || _WIN64
    #include <Windows.h>
    #define LIMPA "cls"
#else
    #include <unistd.h>
    #define LIMPA "clear"
#endif

#define ORG 'X' // Organismo
#define VAZ '.' // Vazio
#define TAM 101

typedef struct tab // Implementar como TAD
{
    char nomeJogo[TAM]; // o nome do jogo deve ser relativo ao padrao
    // de inicializacao. Por exemplo, JogoSapo ou JogoBloco
    int ciclosVida; // Define quanto cada jogo vai rodar (ciclos)
    int dim1, dim2; // dimensoes do tabuleiro linhas x colunas
    char **m;       // Atenção! Essa matriz terá que ser alocada dinamicamente
    // para que a funcao que inicializa possa funcionar
} Tab;

int main()
{

    char **mat;

    int nL = 20, nC = 20, nCiclos = 50; // ou fornecidos pelo usuario

    mat = alocaMatriz(nL, nC); // TO DO

    // TODO la�o INdeterminado que repete enquanto o usuario quiser continuar jogando:
    // cada jogo equivale a nCiclos de um padr�o de inicializacao
    // por exemplo o usuario pode escolher jogar nCiclos do padr�o Sapo
    //  quando terminar jogar mais nCiclos do padr�o Blinker
    //  depois encerrar o programa
    menuInicJogo(mat, nL, nC);
    jogaJogoVida(mat, nL, nC, nCiclos); // TO DO complete essa fun��o
    // fim do laco indeterminado

    desalocaMatriz(mat, nL); // TO DO
}