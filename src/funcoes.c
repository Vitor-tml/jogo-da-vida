#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

// Códigos de escape ASCII para as cores
#define SELEC "\x1B[46;1m"
#define MORTO "\x1B[0;31m"
#define VIVO "\x1B[0;32m"
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
// Desaloca uma matriz passando seu endereço e o numero de linhas
void desalocaMatriz(int **m, int nl)
{
    int i;

    for(i = 0; i < nl; i++)
        free(m[i]);
    free(m);
}
// Imprime X para as cẽlulas vivas, O para as cẽlulas mortar e muda a cor de fundo da linha/coluna destaque
void imprimeMatriz(int **m, int nl, int nc, int linhaDestaque, int colunaDestaque, int destaque)
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
void copiaMatriz(int **m1, int **m2, int nl, int nc)
{
    int i, j;

    for ( i = 0; i < nl; i++)
        for ( j = 0; j < nc; j++)
            m1[i][j] = m2[i][j];
}
// Calcula as células vizinhas de tabuleiro[x][y].
int calculaVizinhos(int **celula, int nl, int nc, int x, int y)
{
    int vizinhos;
    int xmenos = (x!=0);
    int xmais = (x != nl - 1);
    int ymenos = (y != 0);
    int ymais = (y != nc - 1);
    vizinhos =  celula[x - xmenos][y - ymenos]  * (x!=0) * (y != 0)             +
                celula[x - xmenos][y]           * (x!=0)                        +
                celula[x - xmenos][y + ymais]   * (x!=0) * (y != nc - 1)        +

                celula[x][y - ymenos]           * (y != 0)                      +           
                celula[x][y + ymais]            * (y != nc - 1)                 +

                celula[x + xmais][y - ymenos]   * (x != nl - 1) * (y != 0)      +
                celula[x + xmais][y]            * (x != nl - 1)                 +
                celula[x + xmais][y + ymais]    * (x != nl - 1) * (y != nc - 1);

    return vizinhos;
}
// Calcula se uma célula vai viver ou morrer de acordo com o estado atual e os vizinhos
int sobrevivencia(int estado, int vizinhos)
{
    if(estado)
        return (vizinhos == 2 || vizinhos == 3)? 1: 0;
    else
        return (vizinhos == 3)? 1: 0;
}
// Aplica as regras do jogo no tabuleiro
void atualizaMat(int **mAtual, int **mAnt, int nl, int nc)
{
    int i, j, vizinhos;

    for(i = 0; i < nl; i++)
        for(j = 0; j < nc; j++)
        {
            vizinhos = calculaVizinhos(mAnt, nl, nc, i, j);
            mAtual[i][j] = sobrevivencia(mAnt[i][j], vizinhos);
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
int estruturaMenu(int nl, int nc, int nciclos, char nomePadrao[TAM])
{
    int opcaoMenu;
    asciiArt();
    printf("|=======================|\n");
    printf("|         MENU          |\n");
    printf("|          DE           |\n");
    printf("|     CONFIGURACOES     |\n");
    printf("|-----------------------|\n");
    printf("|n linhas  = %d          |\n", nl);
    printf("|n colunas = %d          |\n", nc);
    printf("|n ciclos  = %d          |\n", nciclos);
    printf("|Tipo de padrao inicial:|\n");
    printf("\t%s\t\n", nomePadrao);
    printf("|_______________________|\n\n");

    printf("\n Escolha as opções de configuracao do Jogo da Vida.\n\n ");
    printf("\t(1) Mudar linhas, colunas e ciclos\n\t(2) Mudar padrão inicial\n\t(3) Iniciar Jogo\n(4) Sair");
    printf("\nEntre com a opcao: ");
    scanf("%d", &opcaoMenu);
    return opcaoMenu;
}
// Inicia padrões do jogo
void menuInicJogo()
{
    int tipodeVida, vida;
    printf("\n=> Tipos de padrões iniciais disponíveis:\n\n");
    printf("\t(1) Vidas Paradas\n\t(2) Osciladores\n\t(3) Naves Espaciais\n\t(4) Voltar\n\nEntre com a opcao: ");
    scanf("%d", &tiposdeVida);
    
    switch (tiposdeVida)
    {
    case 1: // Vidas Paradas
        printf("\n=> Escolha as opções de 'Vidas Paradas':\n\n\t(1) Bloco\n\t(2) Colmeia\n\nEntre com a opcao: ");
        scanf("%d", &vida);
        switch (vida)
        {
        case 1:
            strcpy(nomePadrao, "Bloco");
            // inicBloco(mat, nl, nc); => criar uma variável para exportar o tipo
            break;
        case 2:
            strcpy(nomePadrao, "Colmeia");
            // inicColmeia(mat, nl, nc);  => criar uma variável para exportar o
            break;
        default:
            printf("Encolha inválida.\n") break;
        }
    break;

    case 2: // Osciladores
        printf("\n=> Escolha as opções de 'Osciladores':\n\n\t(1) Blinker\n\t(2) Sapo\n\nEntre com a opcao: ");
        scanf("%d", &vida);
        switch (vida)
        {
        case 1:
            strcpy(nomePadrao, "Blinker");
            // inicBlinker(mat, nl, nc); => criar uma variável para exportar o
            break;
        case 2:
            strcpy(nomePadrao, "Sapo");
            // inicSapo(mat, nl, nc); => criar uma variável para exportar o tipo
            break;
        default:
            printf("Escolha inválida.\n");
            break;
        }
    break;

    case 3: // Naves Espaciais
        printf("\n=> Escolha as opções de 'Naves Espaciais':\n\n\t(1) Glider\n\t(2) LightWeight\n\nEntre com a opcao: ");
        scanf("%d", &opcao3);
        switch (opcao3)
        {
        case 1:
            strcpy(nomePadrao, "Glinder");
            // inicGlider(mat, nl, nc); => criar uma variável para exportar o tipo
            break;
        case 2:
            strcpy(nomePadrao, "LWSS");
            // inicLWSS(mat, nl, nc); => criar uma variável para exportar o tipo
            break;
        default:
            printf("Escolha inválida.\n");
            break;
        }
    break;

    default: // Voltar
    break;
    }
}

// Edita tamanho do tabuleiro
void mudaTamanho()
{
    int nl, ic, nciclos;
    printf("Insira o numero de linhas: ");
    scanf("%d", &nl);
    printf("Insira o numero de colunas: ");
    scanf("%d", &nc);
    printf("Insira o numero de ciclos: ");
    scanf("%d", &nciclos);
    printf("\n\n");
}