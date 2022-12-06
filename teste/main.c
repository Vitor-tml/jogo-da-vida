#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 101
#define LINESIZE 1024
typedef struct tab // Testar se essa declaração com valor funciona
{
    char nomeJogo[TAM];
    int nciclos;
    int nl;
    int nc;
    int **m;
}Tabuleiro;


void leCSV(Tabuleiro *tab, char nomeDoArquivo[TAM]);
int main()
{
    Tabuleiro teste;
    return 0;
}
void leCSV(Tabuleiro *tab, char nomeDoArquivo[TAM + 4]) // Tamanho mais a extenção
{
    FILE *arquivo = fopen(nomeDoArquivo, "r");
    char line[LINESIZE+1];
    char *token;
    int linha = 1, coluna;
    if(arquivo == NULL)
    {
        printf("Abertura de arquivo inválida.\n");
        return;
    }
    
    while(fgets(line, LINESIZE, arquivo))
    {
        if(linha > tab->nl)
        {
            printf("Tamanho de forma imcopativel.\n");
            return;
        }
        token = strtok(line, ",");
        while (token)
        {
            token = strtok(NULL, ",");
            coluna = atoi(token);
            if(coluna > tab->nc)
            {
                printf("Tamanho de forma incompativel.\n");
                return;
            }
            tab->m[linha - 1][coluna - 1] = ORG;
        }
        linha++;   
    }    
    
    fclose(&arquivo);
}