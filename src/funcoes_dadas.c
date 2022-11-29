#include "funcoes_dadas.h"

void limpaMatriz(char **m, int nL, int nC)
{
    int i, j;
    for (i = 0; i < nL; i++)
        for (j = 0; j < nC; j++)
            m[i][j] = VAZ;
}

void menuInicJogo(char **mat, int nL, int nC)
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

    imprimeMatriz(mat, nL, nC); // TO DO

    printf("Se inicializacao correta digite qualquer tecla para iniciar o jogo...");
    while (getchar() != '\n');
    getchar();
}


void jogaJogoVida(char **mAtual, int nL, int nC, int nCiclos)
{
    char **mAnt;
    int c;

    // imprimindo na tela a matriz inicial
    system("cls");
    imprimeMatriz(mAtual, nL, nC); // TO DO
    // getchar();
    Sleep(100);

    mAnt = alocaMatriz(nL, nC); // TO DO

    for (c = 1; c <= nCiclos; c++)
    {
        copiaMatriz(mAnt, mAtual, nL, nC); // TO DO implemente a fun��o que copia uma matriz na outra, equivalendo a mAnt = mAtual;

        atualizaMat(mAtual, mAnt, nL, nC); // TO DO implemente nesta fun��o as regras que atualizam a matriz mAtual conforme o jogo da vida
                                           // lembre de usar os dados de mAnt como a matriz do jogo no ciclo anterior para atualizar mAtual
        system("cls");
        imprimeMatriz(mAtual, nL, nC); // TO DO
        // getchar();
        Sleep(100);
    }
    desalocaMatriz(mAnt, nL); // TO DO
}