//Jogo da Forca by Anderson e João Augusto.
/*
  O jogo precisa: armazenar palavras [check], remover palavras, sair[check], erros[check], ver as palavras[check].

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

FILE *palavras; 
char palavraescolhida[20];
int qtdChutes = 0;
char chutes[26];

void verificarArquivo()
{
  if(palavras == NULL) { 
    printf("\nErro: arquivo não encontrado ou corrompido!\n");
    exit(1);
  }
}

void dicionario()
{
  char c;
  palavras = fopen("palavras.txt", "r");
  verificarArquivo();
  while((c=fgetc(palavras))!=EOF) {
    printf("%c", c);
  }
  printf("\n\nDigite uma letra para sair...\n");
  scanf(" %c", &c);
  system("clear");
}

void adicionarPalavras() 
{
  char p[32];
  printf("Adicione uma palavra ao jogo (digite 0 para parar): \n");
  scanf(" %s", p);
  palavras = fopen("palavras.txt", "at");
  verificarArquivo();
  fprintf(palavras, "\n%s", p);
  fclose(palavras);

  //system("clear");
	
	//TODO: CHECAR SE CARACTERE É ALFABETICO
	//CONVERTER PARA MINUSCULAS
  do{
    printf("Adicione uma palavra ao jogo (digite 0 para parar): \n");
    scanf("  %s", p);
    if(p[0]=='0') break;
    palavras = fopen("palavras.txt", "at");
    fprintf(palavras, "\n%s", p);
    fclose(palavras);
    system("clear");
  }while(p[0]!='0');
    system("clear");
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
  rewind(palavras);
  //srand(time(0)); //Colocar números aleatórios
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
  do{
    printf("\t\tJogo da Forca\n");
    printf("\t1-Começar jogo\n");
    printf("\t2-Adicionar palavras\n");
    printf("\t3- Dicionario\n");
    printf("\t4-Sair\n\n");
    printf("Digite aqui: ");
    scanf(" %hu", &entrada);
    if(entrada < 1 || entrada > 4) printf("Erro: número inválido, tente de novo.");
    system("clear"); //Limpar system("cls");
  
  }while(entrada < 1 || entrada > 4);
  return entrada;
}

int letraexiste(char l) 
{
  for(int i = 0; i < strlen(palavraescolhida); i++) {
    if(l == palavraescolhida[i]) return 1;
  }
  return 0;
}

int qtdErros()
{
  int erros = 0;
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
  	scanf(" %s", &chute);
	} while(! isalpha(chute[0]));
  chute[0] = tolower(chute[0]);//coloca toda as letras digitadas em minúsculo
  fflush(stdin); 
  chutes[qtdChutes] = chute[0];
  qtdChutes++;
}

int chutado(char l)
{
  int flag = 0;
  for(int i = 0; i < qtdChutes; i++) {
    if(chutes[i] == l) {
      flag = 1;
      break;
    }
  }
  return flag; 
}

int ganhou()
{
  for(int i = 0; i < strlen(palavraescolhida); i++) {
    if(!chutado(palavraescolhida[i])) return 0;
  }
  return 1;
}

int perdeu()
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
	
  for(int i = 0; i < strlen(palavraescolhida); i++) {
	  if(chutado(palavraescolhida[i])) printf("%c ", palavraescolhida[i]);
	  else printf("_ ");
	}
}

void jogo()
{
  int erros = qtdErros();
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
		printf("\nCARALHO MERMÃO, TU É MT BURRO!\n");
    printf("FOI ENFORCADO CARA, JÁ ERA!\t\t\n");
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
    c = toupper(getchar());
  }while(c != 'S' && c != 'N');
  system("clear");
  return (c=='S') ? 1 : 0;
}
int main(void) 
{
  //system("clear");
  unsigned short int op;
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
        op = fimJogo();
        break;
      case 2: 
        adicionarPalavras();
        break;
      case 3:
        dicionario();
        break;
      case 4:
        printf("\tObrigado por jogar o jogo!\nBy: Anderson Lopes e João Augusto\n\n");
        break;
    }
  }while(op!=4);
  return 0;
}