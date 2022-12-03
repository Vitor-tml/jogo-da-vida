#include <stdlib.h>
#include <stdio.h>
#define TAM 101

void asciiArt();
int estruturaMenu(int nl, int nc, int nciclos, char nomePadrao[TAM])
void mudaPadrao();
void mudaTamanho();

int main()
{
    int menu;           // Opções do menu
    int jogo = 1;       // Flag do loop do jogo

    printf("Iniciando o Jogo da Vida");
    Sleep();

    while (jogo)
    {
        system("clear"); // Coloar o LIMPA
        asciiArt();

        menu = estruturaMenu(nl, nc, nc, nomePadrao); // Mudar para struct

        switch (menu)
        {
        case 1: /// Muda tamanho do tabuleiro
            mudaTamanho();
        break;

        case 2: // Muda padrão de inicialização
            mudaPadrao();
        break;

        case 3: // Entra no jogo
            jogaJogoVida();         
        break;

        default:
            printf("Saindo.\n");
            jogo = 0;
        break;
        }
    }

    return 0;
}

