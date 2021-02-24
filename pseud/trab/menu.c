#include <stdio.h>
#include <locale.h>

int main(void) {
 
 int intro, nivel;

  printf("///////Seja bem-vindo a ANAGRAMA!///////\n");

  printf("0.Sair\n1.Iniciar\n");
  scanf("%d", &intro);

  if ( intro == 1){
    printf("Escolha um nível para jogar:\n1.Fácil\n2.Médio\n3.Difícil\n");
    scanf("%d", &nivel);
  
    if (nivel == 1){
      printf("Voce escolheu o nível %d - Fácil\n", nivel);
    }
    else if (nivel == 2){
      printf("Voce escolheu o nível %d - Médio\n", nivel);
    }
    else if (nivel == 3){
      printf("Voce escolheu o nível %d - Difícil\n", nivel);
    }
    else{
      return 0;
    } 
  }
  else{
    return 0;
  }
  return 0;