//Jogo da Forca by Anderson e João Augusto.
/*
  O jogo precisa: armazenar palavras [check], remover palavras, sair[check], erros[check], ver as palavras.

*/
#include <stdio.h>

FILE *palavras; 

void verificarArquivo()
{
  if(palavras == NULL){ 
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
  printf("\n\nDigite algo para sair...\n");
  system("clear");
}

void adicionarPalavras() 
{
  char p[32];
  printf("Adicione uma palavra ao jogo (digite 0 para parar): \n");
  gets(p);
  palavras = fopen("palavras.txt", "at");
  verificarArquivo();
  fprintf(palavras, "%s", p);  
  fclose(palavras);
  while(1) {
    printf("Adicione uma palavra ao jogo (digite 0 para parar): \n");
    gets(p);
    if(p[0]=='0') break;
    palavras = fopen("palavras.txt", "at");
    fprintf(palavras, "\n%s", p);
    fclose(palavras);
    system("clear");
  }
    system("clear");
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
    scanf("%hu", &entrada);
    if(entrada < 1 || entrada > 4) printf("Erro: número inválido, tente de novo.");
    system("clear"); //Limpar system("cls");
  
  }while(entrada < 1 || entrada > 4);
  return entrada;
}

int main(void) {
  system("clear");
  unsigned short int op;
  do{
    op = menu();
    switch(op) 
    {
      case 1:
        //comecarJogo();
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