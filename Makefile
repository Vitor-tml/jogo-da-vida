all:
	gcc -c .\src\funcoes.c -I .\include -o .\obj\funcoes.o
	gcc -c .\src\formas_de_vida.c .\obj\funcoes_dadas.o -I .\include -o .\obj\formas_de_vida.o
	gcc -c .\src\funcoes_dadas.c .\obj\funcoes.o .\obj\formas_de_vida.o -I .\include -o .\obj\funcoes_dadas.o
	gcc .\programa\main.c .\obj\formas_de_vida.o .\obj\funcoes.o .\obj\funcoes_dadas.o -I .\include -o .\bin\main.exe
	.\bin\main.exe

criadas:
	gcc -c .\src\funcoes.c -I .\include -o .\obj\funcoes.o

dadas:
	gcc -c .\src\funcoes_dadas.c .\obj\funcoes.o .\obj\formas_de_vida.o -I .\include -o .\obj\funcoes_dadas.o

formas:
	gcc -c .\src\formas_de_vida.c .\obj\funcoes_dadas.o -I .\include -o .\obj\formas_de_vida.o
main:
	gcc .\programa\main.c .\obj\formas_de_vida.o .\obj\funcoes.o .\obj\funcoes_dadas.o -I .\include -o .\bin\main.exe

exe:
	.\bin\main.exe

clear:
	rm .\obj\funcoes.o
	rm .\obj\funcoes_dadas.o
	rm .\obj\formas_de_vida.o
	rm .\bin\main.exe
