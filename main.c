//Jogo da Forca by Anderson e João Augusto.
#include "forca.h"
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