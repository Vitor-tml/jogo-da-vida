#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 101
typedef struct tab // Testar se essa declaração com valor funciona
{
    char nomeJogo[TAM];
    int nciclos;
    int nl;
    int nc;
    int **m;
} Tabuleiro;

int estruturaMenu(Tabuleiro tab);

int main()
{
    Tabuleiro tab;
    strcpy(tab.nomeJogo, "nenhum");
    tab.nciclos = 50;
    tab.nc = tab.nl = 15;
    tab.m = NULL;
    estruturaMenu(tab);
    return 0;
}

int estruturaMenu(Tabuleiro tab)
{
    int opcaoMenu;

    char 
    printf("|════════════════════════|\n");
    printf("|         MENU          |\n");
    printf("|          DE           |\n");
    printf("|     CONFIGURACOES     |\n");
    printf("|-----------------------|\n");
    printf("|n linhas  = %d          |\n", tab.nl);
    printf("|n colunas = %d          |\n", tab.nc);
    printf("|n ciclos  = %d          |\n", tab.nciclos);
    printf("|Tipo de padrao inicial:|\n");
    printf("\t%s\t\n", tab.nomeJogo);
    printf("|══════════════════════════|\n\n");

    printf("\n Escolha as opções de configuracao do Jogo da Vida.\n\n ");
    printf("\t(1) Mudar linhas, colunas e ciclos\n\t(2) Mudar padrão inicial\n\t(3) Iniciar Jogo\n(4) Sair");
    printf("\nEntre com a opcao: ");
    scanf("%d", &opcaoMenu);
    return opcaoMenu;
}

const char *centerAlignText(char *field, unsigned int fieldWidth, const char *text){
    
    if (fieldWidth == 0 || field == NULL) return "";

    fieldWidth--;
    unsigned int len = strlen(text);
    unsigned int padding = fieldWidth > len ? (fieldWidth+1 - len)/2 : 0;
    sprintf(field, "%*s%.*s%*s", padding, "", fieldWidth-1, text, padding>0 && len%2!=fieldWidth%2 ? padding-1 : padding, "");

    return (const char *)field;
}