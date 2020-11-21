//Jogo da Forca by Anderson e João Augusto.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "forca.h"
#define TAMANHO_MAX 20

FILE *palavras; 
char palavraescolhida[TAMANHO_MAX];
unsigned short int qtdChutes = 0;
char chutes[26];

//Limpar tela 
/*
void limpar_tela() {

  #ifdef _WIN32
  system("cls");
  #endif
  #ifdef __linux__
  system("clear");
  #endif

}
*/ 
void verificarArquivo()
{
  if(palavras == NULL) { 
    printf("\nErro: arquivo não encontrado ou corrompido!\n");
    exit(1);
  }
}

void dicionario()
{
  int c;
  char entrada;
  palavras = fopen("palavras.txt", "r");
  verificarArquivo();
  while((c=fgetc(palavras))!=EOF) {
    printf("%c", c);
  }
  printf("\n\nDigite uma letra para sair...\n");
  scanf(" %c", &entrada);
  system("clear");
}

unsigned short int ehAlfabetica(char p[]) {
  unsigned short int x = strlen(p);
  for(int i = 0; i < x; i++) {
      if(!(isalpha(p[i]))) {
        return 1;
      } 
    }
    return 0;
}

void recebePalavra(char p[]) {
  do{
      printf("Adicione uma palavra ao jogo (digite 0 para parar): \n");
      scanf("  %s", p);
      if(p[0]=='0') break;
      if(ehAlfabetica(p)) {
        printf("\n\nErro: algum caractere não faz parte do alfabeto, tente novamente!\n\n");
      }
    }while(ehAlfabetica(p));
}

void adicionarPalavras() 
{
  char p[TAMANHO_MAX];
  unsigned short int i;
  do{
    recebePalavra(p);
    if(p[0]!='0') {
      for(i = 0; i < strlen(p); i++) {
      p[i] = tolower(p[i]);
      }//Converter a string para minúscula 
      palavras = fopen("palavras.txt", "at");
      fprintf(palavras, "\n%s", p);
      fclose(palavras);
    }
    system("clear");
  }while(p[0]!='0');
}

void escolherPalavra()
{
  int randomico, qtd = 1;
  int c; //EOF é um inteiro, então é preciso ser inteiro 
  palavras = fopen("palavras.txt", "r");
  verificarArquivo();
  while((c = fgetc(palavras)) != EOF) {
    if(c == '\n') qtd++;
  }
  rewind(palavras); //Volta pro começo pra contar linhas
  srand(time(0)); //Colocar números aleatórios
  randomico = rand() % qtd; //entre 0 e qtd
  for(int i = 0; i < randomico; i++) 
  {
      fscanf(palavras, "%s", palavraescolhida); //Escolher a palavra indo até a linha (randomica) e pegando a palavra;
  }
  fclose(palavras);
}

unsigned short int menu() //Menu 
{
  unsigned short int entrada;
  system("clear");
  do{
    printf("\t\tJogo da Forca\n");
    printf("\t1-Começar jogo\n");
    printf("\t2-Adicionar palavras\n");
    printf("\t3-Dicionario\n");
    printf("\t4-Sair\n\n");
    printf("Digite aqui: ");
    scanf(" %hu", &entrada);
    if(entrada < 1 || entrada > 4) {
      printf("Erro: número inválido, tente de novo.");
      system("clear");
    }
  }while(entrada < 1 || entrada > 4);
  system("clear");
  return entrada;
}

unsigned short int letraexiste(char l) 
{
  for(int i = 0; i < strlen(palavraescolhida); i++) {
    if(l == palavraescolhida[i]) return 1;
  }
  return 0;
}

unsigned short int qtdErros()
{
  unsigned short int erros = 0;
  for(int i = 0; i < qtdChutes; i++) {
    if(!letraexiste(chutes[i])) erros++;
  }
  return erros;
}

void chute() 
{
  //Chute foi declarado como vetor para evitar o erro de digitar mais que 1 caractere.
  char chute[2];
  printf("\nDigite a letra: ");
	do {
  	scanf(" %s", chute);
	} while(! isalpha(chute[0]));
  chute[0] = tolower(chute[0]);//coloca toda as letras digitadas em minúsculo
  scanf("%*c"); //limpa buffer de entrada
  chutes[qtdChutes] = chute[0];
  qtdChutes++;
}

unsigned short int chutado(char l)
{
  unsigned short int flag = 0;
  for(int i = 0; i < qtdChutes; i++) {
    if(chutes[i] == l) {
      flag = 1;
      break;
    }
  }
  return flag; 
}

unsigned short int ganhou()
{
  unsigned short int x = strlen(palavraescolhida); // Para não chamar a função toda hora
  for(int i = 0; i < x; i++) {
    if(!chutado(palavraescolhida[i])) return 0;
  }
  return 1;
}

unsigned short int perdeu()
{
  return (qtdErros() >= 5);
}

void forca(int erros) 
{
  printf("  _______       \n");
	printf(" |/      |      \n");
	printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
	printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
	printf(" |       %c     \n", (erros>=2?'|':' '));
	printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
	printf(" |              \n");
	printf("_|___           \n");
	printf("\n\n");
	unsigned short int x = strlen(palavraescolhida);
  for(int i = 0; i < x; i++) {
	  if(chutado(palavraescolhida[i])) printf("%c ", palavraescolhida[i]);
	  else printf("_ ");
	}
}

void jogo()
{
  unsigned short int erros = qtdErros();
  forca(erros);
  chute();
  system("clear");
}

unsigned short int fimJogo()
{
  char c;
  if(ganhou()) 
  {
		printf("\nParabéns, você ganhou!\n\n");

		printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");
	} else {
    printf("\nQue pena, você perdeu!\n");
		printf("A palavra era **%s**\n\n", palavraescolhida);

		printf("    _______________         \n");
		printf("   /               \\       \n"); 
		printf("  /                 \\      \n");
		printf("//                   \\/\\  \n");
		printf("\\|   XXXX     XXXX   | /   \n");
		printf(" |   XXXX     XXXX   |/     \n");
		printf(" |   XXX       XXX   |      \n");
		printf(" |                   |      \n");
		printf(" \\__      XXX      __/     \n");
		printf("   |\\     XXX     /|       \n");
		printf("   | |           | |        \n");
		printf("   | I I I I I I I |        \n");
		printf("   |  I I I I I I  |        \n");
		printf("   \\_             _/       \n");
		printf("     \\_         _/         \n");
		printf("       \\_______/           \n\n");
  }
  do{
    printf("\n\nVoce deseja jogar de novo? (S/N): \n\n");
    scanf(" %c", &c);
    c = toupper(c);
  }while(c != 'S' && c != 'N');
  system("clear");
  return (c=='S') ? 1 : 0;
}

int main(void) 
{
  system("clear");
  //TODO: RESOLVER A GAMBIARRA DO VETOR
  unsigned short int op, flag = 1; 
  do{
    op = menu();
    switch(op) 
    {
      case 1:
        escolherPalavra();
        qtdChutes = 0;
        do{
          jogo();
        }while(!ganhou() && !perdeu()); //Continua enquanto não ganha ou não perde
        flag = fimJogo();
        break;
      case 2: 
        adicionarPalavras();
        break;
      case 3:
        dicionario();
        break;
      case 4:
        break;
    }
    if(!flag) break;
  }while(op!=4);
  printf("\tObrigado por jogar o nosso jogo!\nBy: Anderson Lopes e João Augusto\n\n");
  return 0;
}