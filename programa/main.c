#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "funcoes_dadas.h"
#include "formas_de_vida.h"

int main()
{
    int menu;           // Opções do menu
    int jogo = 1;       // Flag do loop do jogo
    Tabuleiro tab;

    tab.nl = tab.nc = 15;
    tab.nciclos = 3;
    strcpy(tab.nomeJogo, "nenhum");
    alocaMatriz(&tab);
    
    while (jogo)
    {
        system("clear"); // Coloar o LIMPA
        asciiArt();

        menu = estruturaMenu(tab); // Mudar para struct

        switch (menu)
        {
        case 1: /// Muda tamanho do tabuleiro
            mudaTamanho(&tab);
        break;

        case 2: // Muda padrão de inicialização
            menuInicJogo(&tab);
        break;

        case 3: // Entra no jogo
            jogaJogoVida(&tab);         
        break;

        default:
            printf("Saindo.\n");
            jogo = 0;
        break;
        }
    }

    return 0;
}