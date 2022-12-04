#include <stdio.h>
#include <stdlib.h> // Verificar quais precisam estar aqui ou nao
#include "funcoes.h"
#include "formas_de_vida.h"
#include "funcoes_dadas.h"

#ifdef _WIN32
#include <Windows.h>
#define LIMPA "cls"
#else
#include <unistd.h>
#define LIMPA "clear"
#endif

#define ORG 1   // Organismo
#define VAZ 0   // Vazio
#define TAM 101 // Tamanho do nome do jogo.


int main()
{
    int menu;           // Opções do menu
    int jogo = 1;       // Flag do loop do jogo
    Tabuleiro tab;

    alocaMatriz(&tab);

    printf("Iniciando o Jogo da Vida");
    Sleep();
    
    while (jogo)
    {
        system("clear"); // Coloar o LIMPA
        asciiArt();

        menu = estruturaMenu(); // Mudar para struct

        switch (menu)
        {
        case 1: /// Muda tamanho do tabuleiro
            mudaTamanho(tab);
        break;

        case 2: // Muda padrão de inicialização
            menuInicJogo(tab);
        break;

        case 3: // Entra no jogo
            jogaJogoVida(tab);         
        break;

        default:
            printf("Saindo.\n");
            jogo = 0;
        break;
        }
    }

    return 0;
}