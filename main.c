//Jogo da Forca by Anderson e João Augusto.
/*
  O jogo precisa: armazenar palavras, remover palavras, sair

*/
#include <stdio.h>

FILE *palavras; 

void adicionarPalavras() 
{
  char p[32];
  printf("Adicione uma palavra ao jogo (digite 0 para parar): \n");
  gets(p);
  palavras = fopen("palavras.txt", "at");
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
    printf("\t3-Sair\n\n");
    printf("Digite aqui: ");
    scanf("%hu", &entrada);
    if(entrada < 1 || entrada > 3) printf("Erro: número inválido, tente de novo.");
    system("clear"); //Limpar system("cls");
  
  }while(entrada < 1 || entrada > 3);
  return entrada;
}

int main(void) {
  unsigned short int op;  
  //palavras = fopen("palavras.text", "wt");
  //fprintf(palavras, "%s\n", "batata");//exemplo
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
        printf("\tObrigado por jogar o jogo!\nBy: Anderson Lopes e João Augusto\n\n");
        break;
    }
  }while(op!=3);
  return 0;
}