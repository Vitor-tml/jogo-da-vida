# Jogo da Vida em C
> O jogo da vida é um autómato celular desenvolvido pelo matemático britânico John Horton Conway em 1970. 
> 
> É o exemplo mais bem conhecido de autômato celular. [Wikipédia](https://pt.wikipedia.org/wiki/Jogo_da_vida)

---

Este repositório tem a intenção de implementar o jogo e suas regras em um programa em C para fins acadêmicos.

### Objetivos:

- [x] Lógica do jogo.
- [ ] Entrada de usuário.
- [ ] Tabuleiro de tamanho dinâmico.
- [ ] Pause entre gerações.
- [ ] Estruturas pré-prontas.

## Compilação:
Para compilar tudo apenas execute o comando 
Funções:
```
gcc -c .\src\funcoes.c -I .\include -o /obj/funcoes.o
```
Funções dadas:
```
gcc -c ./src/funcoes_dadas.c -I ./include -o /obj/funcoes_dadas.o
```
Formas de Vida
```
gcc -c .\src\formas_de_vida.c -I .\include -o .\obj\formas_de_vida.o
```
Main
```
gcc .\programa\main.c .\obj\formas_de_vida.o .\obj\funcoes.o .\obj\funcoes_dadas.o -I .\include -o .\bin\main.exe
```

