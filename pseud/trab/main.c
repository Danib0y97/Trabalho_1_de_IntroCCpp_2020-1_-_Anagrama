#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_LISTA 9
#define TAM_PALAVRA 20

int main(){

  int i = 0, j=0, random = 0, sorteio;  /*contador de palavras*/
  FILE *lista;
  char palavras[20]; /*todas as palavras da lista*/
  char nsorteio; /*sorteia palavra aleatória da lista*/

  /*Abrindo o arquivo e lendos as palavras*/
  
  lista = fopen("palavras.txt", "r");
  if(lista == NULL){
    printf("O arquivo não pode ser aberto.\n");
    exit(1);
  }
  while(fscanf( lista, "%s", palavras) != EOF ){
    random++;
  }

  /*Sorteando palavras da lista*/
  
  while(1){
    rewind(lista);
    
    srand(time(NULL));
    sorteio = rand() % TAM_LISTA;  

    for(i = 0, j = 0; j < sorteio; i++){
      if(fgetc(lista) == '\n'){
        j++;
        fscanf(lista, "%s", palavras);
      }
    } 
    break;
  }
  fclose(lista);
  printf("%s \n", palavras);
  return 0;

}
