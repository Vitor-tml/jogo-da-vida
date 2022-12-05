#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funcoes.h"
#include "formas_de_vida.h"

#ifdef _WIN32
#include <Windows.h>
#define DORME Sleep(1000);
#else
#include <unistd.h>
#define DORME sleep(1);
#endif

#define ORG 1 // Organismo
#define VAZ 0 // Vazio

// Códigos de escape ASCII para as cores
#define SELEC "\x1B[46;1m"
#define MORTO "\x1B[0;31m"
#define VIVO "\x1B[0;32m"
#define RESET "\x1B[0m"
 
// Aloca uma matriz por valor passando o numero de linhas e colunas.
void alocaMatriz(Tabuleiro*tab)
{
    int i;

    tab->m = (int **)calloc(tab->nl, sizeof(int *));
    if (tab->m == NULL)
    {
        printf("Erro ao alocar matriz\n");
        exit(1);
    }

    for (i = 0; i < tab->nl; i++)
    {
        (tab->m)[i] = (int *)calloc(tab->nc, sizeof(int));
        if (tab->m[i] == NULL)
        {
            printf("Erro ao alocar a linha %d\n", i);
            exit(1);
        }
    }
}
// Desaloca uma matriz passando seu endereco e o numero de linhas
void desalocaMatriz(int **m, int nl)
{
    int i;

    for (i = 0; i < nl; i++)
        free(m[i]);
    free(m);
}
// Imprime X para as cẽlulas vivas, O para as cẽlulas mortar e muda a cor de fundo da linha/coluna destaque
void imprimeMatriz(Tabuleiro tab, int linhaDestaque, int colunaDestaque, int destaque)
{
    int i, j;

    for (i = 0; i < tab.nl; i++)
    {
        for (j = 0; j < tab.nc; j++)
        {
            if ((i == linhaDestaque || j == colunaDestaque) && destaque)
                printf(SELEC);
            else if (tab.m[i][j])
                printf(VIVO);
            else
                printf(MORTO);
            printf(" %c ", tab.m[i][j] ? 'x' : 'o');
            printf(RESET);
        }
        printf("\n");
    }
}
// Copia o tabuleiro em outra matriz
void copiaMatriz(Tabuleiro *m, Tabuleiro *tab)
{
    int i, j;

    for (i = 0; i < tab->nl; i++)
        for (j = 0; j < tab->nc; j++)
           m->m[i][j] = tab->m[i][j];
            
}
// Calcula as células vizinhas de tabuleiro[x][y].
int calculaVizinhos(Tabuleiro celula, int x, int y)
{
    int vizinhos;
    int xmenos = (x != 0);
    int xmais = (x != celula.nl - 1);
    int ymenos = (y != 0);
    int ymais = (y != celula.nc - 1);
    vizinhos = celula.m[x - xmenos][y - ymenos] * (x != 0) * (y != 0) +
               celula.m[x - xmenos][y] * (x != 0) +
               celula.m[x - xmenos][y + ymais] * (x != 0) * (y != celula.nc - 1) +

               celula.m[x][y - ymenos] * (y != 0) +
               celula.m[x][y + ymais] * (y != celula.nc - 1) +

               celula.m[x + xmais][y - ymenos] * (x != celula.nl - 1) * (y != 0) +
               celula.m[x + xmais][y] * (x != celula.nl - 1) +
               celula.m[x + xmais][y + ymais] * (x != celula.nl - 1) * (y != celula.nc - 1);

    return vizinhos;
}
// Calcula se uma célula vai viver ou morrer de acordo com o estado atual e os vizinhos
int sobrevivencia(int estado, int vizinhos)
{
    if (estado)
        return (vizinhos == 2 || vizinhos == 3) ? 1 : 0;
    else
        return (vizinhos == 3) ? 1 : 0;
}
// Aplica as regras do jogo no tabuleiro
void atualizaMat(Tabuleiro tab, Tabuleiro *novaGeracao)
{
    int i, j, vizinhos;

    for (i = 0; i < tab.nl; i++)
        for (j = 0; j < tab.nc; j++)
        {
            vizinhos = calculaVizinhos(tab, i, j);
            novaGeracao->m[i][j] = sobrevivencia(tab.m[i][j], vizinhos);
        }
}
// Frufruzinho para o inicio do game
void asciiArt()
{
    printf("       _                         _               _     _       \n");
    printf("      | |                       | |             (_)   | |      \n");
    printf("      | | ___   __ _  ___     __| | __ _  __   ___  __| | __ _ \n");
    printf("  _   | |/ _ \\ / _` |/ _ \\   / _` |/ _` | \\ \\ / / |/ _` |/ _` |\n");
    printf(" | |__| | (_) | (_| | (_) | | (_| | (_| |  \\ V /| | (_| | (_| |\n");
    printf("  \\____/ \\___/ \\__, |\\___/   \\__,_|\\__,_|   \\_/ |_|\\__,_|\\__,_|\n");
    printf("                __/ |                                          \n");
    printf("               |___/                                           \n\n\n");
}
// Interface do inicio do jogo
int estruturaMenu(Tabuleiro tab)
{
    int opcaoMenu;
    char nome[22];
    int barra = 186;

    printbarra(23, 1);    
    printf("%c         MENU          %c\n", barra, barra);
    printf("%c          DE           %c\n", barra, barra);
    printf("%c     CONFIGURACOES     %c\n", barra, barra);
    printbarra(23, 2);
    printf("%cn linhas  = %3d        %c\n", barra, tab.nl, barra);
    printf("%cn colunas = %3d        %c\n", barra, tab.nc, barra);
    printf("%cn ciclos  = %3d        %c\n", barra, tab.nciclos, barra);
    printf("%cTipo de padrao inicial:%c\n", barra, barra);
    printf("%c%s  %c\n", barra, centerAlignText(nome, 22, tab.nomeJogo), barra);
    printbarra(23, 3);

    printf("\nEscolha as opcoes de configuracao do Jogo da Vida.\n\n ");
    printf("\t(1) Mudar linhas, colunas e ciclos\n\t(2) Mudar padrao inicial\n\t(3) Iniciar Jogo\n\t(4) Sair");
    printf("\nEntre com a opcao: ");
    scanf("%d", &opcaoMenu);
    return opcaoMenu;
}
// Inicia padroes do jogo
void menuInicJogo(Tabuleiro *tab)
{
    int tiposdeVida, vida;
    printf("\n=> Tipos de padroes iniciais disponiveis:\n\n");
    printf("\t(1) Vidas Paradas\n\t(2) Osciladores\n\t(3) Naves Espaciais\n\t(4) Voltar\n\nEntre com a opcao: ");
    scanf("%d", &tiposdeVida);

    switch (tiposdeVida)
    {
    case 1: // Vidas Paradas
        printf("\nEscolha as opcoes de 'Vidas Paradas':\n\n\t(1) Bloco\n\t(2) Colmeia\n\nEntre com a opcao: ");
        scanf("%d", &vida);
        switch (vida)
        {
        case 1: // Opcao Bloco
            if(tab->nl < 2 || tab->nc < 2)
            {
                printf("\nTamanho de tabuleiro invalido.\n");
                DORME
                break;
            }
            strcpy(tab->nomeJogo, "Bloco");
            inicBloco(tab);
            break;
        case 2: // Opcao Colmeia
            if(tab->nl < 3 || tab->nc < 4)
            {
                printf("\nTamanho de tabuleiro invalido.\n");
                DORME
                break;
            }
            strcpy(tab->nomeJogo, "Colmeia");
            inicColmeia(tab);
            break;
        default: // Invalido
            printf("Encolha invalida.\n");
            break;
        }
        break;

    case 2: // Osciladores
        printf("\n=> Escolha as opcoes de 'Osciladores':\n\n\t(1) Blinker\n\t(2) Sapo\n\nEntre com a opcao: ");
        scanf("%d", &vida);
        switch (vida)
        {
        case 1: //Opcao Blinker
            if(tab->nl < 1 || tab->nc < 3)
            {
                printf("\nTamanho de tabuleiro invalido.\n");
                DORME
                break;
            }
            strcpy(tab->nomeJogo, "Blinker");
            inicBlinker(tab);
            break;
        case 2: // Opcao Sapo
            if(tab->nl < 2 || tab->nc < 4)
            {
                printf("\nTamanho de tabuleiro invalido.\n");
                DORME
                break;
            }
            strcpy(tab->nomeJogo, "Sapo");
            inicSapo(tab);
            break;
        default: 
            printf("Escolha invalida.\n");
            break;
        }
        break;

    case 3: // Naves Espaciais
        printf("\n=> Escolha as opcoes de 'Naves Espaciais':\n\n\t(1) Glider\n\t(2) LightWeight\n\nEntre com a opcao: ");
        scanf("%d", &vida);
        switch (vida)
        {
        case 1: // Opcao Glider
            if(tab->nl < 3 || tab->nc < 3)
            {
                printf("\nTamanho de tabuleiro invalido.\n");
                DORME
                break;
            }
            strcpy(tab->nomeJogo, "Glinder");
            inicGlider(tab);
            break;
        case 2: // Opcao LWSS
            if(tab->nl < 4 || tab->nc < 5)
            {
                printf("\nTamanho de tabuleiro invalido.\n");
                DORME
                break;
            }
            strcpy(tab->nomeJogo, "LWSS");
            inicLWSS(tab);
            break;
        default: 
            printf("Escolha invalida.\n");
            break;
        }
        break;

    default: // Voltar
        break;
    }
}

// Edita tamanho do tabuleiro
void mudaTamanho(Tabuleiro*tab)
{
    int i;
    int nlAntigo = tab->nl;
    printf("Insira o numero de linhas: ");
    scanf("%d", &tab->nl);
    printf("Insira o numero de colunas: ");
    scanf("%d", &tab->nc);
    printf("Insira o numero de ciclos: ");
    scanf("%d", &tab->nciclos);
    printf("\n\n");

    for(i = 0; i < nlAntigo; i++)
        tab->m[i] = (int *) realloc(tab->m[i], tab->nc * sizeof(int));
    tab->m = (int **) realloc(tab->m, tab->nl * sizeof(int *));
}

const char *centerAlignText(char *field, unsigned int fieldWidth, const char *text)
{
    if (fieldWidth == 0 || field == NULL) return "";

    fieldWidth--;
    unsigned int len = strlen(text);
    unsigned int padding = fieldWidth > len ? (fieldWidth+1 - len)/2 : 0;
    sprintf(field, "%*s%.*s%*s", padding, "", fieldWidth-1, text, padding>0 && len%2!=fieldWidth%2 ? padding-1 : padding, "");

    return (const char *)field;
}
void printbarra(int n, int tipo)
{
    int i = 0;
    char primeiro, segundo, barra = 205;
    printf(VIVO);
    if(tipo == 1)
    {
        primeiro = 201;
        segundo = 187;
    }
    if(tipo == 2)
    {
        primeiro = 204;
        segundo = 185;
    }
    if(tipo == 3)
    {
        primeiro = 200;
        segundo = 188;
    }
    printf("%c", primeiro);
    for(i = 0; i < n; i++)
        printf("%c", barra);
    printf("%c", segundo);
    printf("\n");
    printf(RESET);
}
