#ifndef FORCA_H //impedir múltiplas definições da mesma função
#define FORCA_H
#include <stdio.h> //Incluído para usar FILE
extern FILE *palavras;
extern char palavraescolhida[20];
extern unsigned short int qtdChutes;
extern char chutes[26];
void verificarArquivo();
void dicionario();
unsigned short int ehAlfabetica(char p[]);
void recebePalavra(char p[]);
void adicionarPalavras();
void escolherPalavra();
unsigned short int menu();
unsigned short int letraexiste(char l);
unsigned short int qtdErros();
void chute();
unsigned short int chutado(char l);
unsigned short int ganhou();
unsigned short int perdeu();
void forca(int erros);
void jogo();
unsigned short int fimJogo();

#endif