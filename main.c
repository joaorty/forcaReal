//Jogo da Forca by Anderson e João Augusto.
/*
  O jogo precisa: armazenar palavras,

*/
#include <stdio.h>

FILE *palavras; 

void adicionarPalavras() 
{
  
  //scanf
  //abrir o arquivo no modo append
  //fprintf
  //do while (repetindo)
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
  op = menu();
  //palavras = fopen("palavras.text", "wt");
  //fprintf(palavras, "%s\n", "batata");//exemplo
  switch(op) 
  {
    case 1:
      //comecarJogo();
      break;
    case 2: 
      //adicionarPalavra();
      break;
    case 3:
      printf("\tObrigado por jogar o jogo!\nBy: Anderson Lopes e João Augusto\n\n");
      return 0;
  }
  return 0;
}