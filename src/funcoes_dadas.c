#include "funcoes_dadas.h"
#include "funcoes.h"
#define VAZ 0 // Vazio

void limpaMatriz(int **m, int nL, int nC)
{
    int i, j;
    for (i = 0; i < nL; i++)
        for (j = 0; j < nC; j++)
            m[i][j] = VAZ;
}

void menuInicJogo(int **mat, int nL, int nC)
{
    int opcao;

    printf("(1)Bloco\n(2)Blinker\n(3)Sapo\n(4)Glider\n(5)LWSS\nEntre com a opcao: ");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        inicBloco(mat, nL, nC);
        break;
    case 2:
        inicBlinker(mat, nL, nC);
        break;
    case 3:
        inicSapo(mat, nL, nC);
        break;
    case 4:
        inicGlider(mat, nL, nC);
        break;
    case 5:
        inicLWSS(mat, nL, nC);
        break;
    }

    imprimeMatriz(mat, nL, nC, 0, 0, 0);

    printf("Se inicializacao correta digite qualquer tecla para iniciar o jogo...");
while (getchar() != '\n');
    getchar();
}


void jogaJogoVida(int **mAtual, int nL, int nC, int nCiclos) // Jogo real
{
    int **mAnt;
    int c;

    system("cls");
    imprimeMatriz(mAtual, nL, nC, 0, 0, 0);
    // getchar();
    Sleep(100);     //*========== Adaptar para win e linux

    mAnt = alocaMatriz(nL, nC);
    for (c = 1; c <= nCiclos; c++)
    { 
        copiaMatriz(mAnt, mAtual, nL, nC);
        printf("Chegei aqui2"); //========================================== Nao está chegando aqui
        getchar();
        atualizaMat(mAtual, mAnt, nL, nC); //===== REGRAS do jogo
        system("cls");                      //====== Mudar para compatível com as duas plataformas
        imprimeMatriz(mAtual, nL, nC, 0, 0, 0);
        getchar();
        Sleep(100);
    }
    desalocaMatriz(mAnt, nL);
}