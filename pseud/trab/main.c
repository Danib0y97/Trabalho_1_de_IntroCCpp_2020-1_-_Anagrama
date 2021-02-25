#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define TAM_LISTA 10

int main(){
  
  // Contadores de palavras
  int a, i = 0, j = 0, random = 0, sorteio = 0, c = 0, x = 0, score, decisao;  
  // Arquivo
  FILE *lista;
  // Palavras da lista
  char palavras[20], palavras2[20], anagrama[20], r[20], resposta[20]; 
  //Sorteia a palavra aleatória da lista
  char nsorteio;

  /*Abrindo o arquivo e lendo as palavras*/
  
  lista = fopen("palavras.txt", "r");
  if(lista == NULL){
    printf("O arquivo não pode ser aberto.\n");
    exit(1);
  }
  while(fscanf( lista, "%s", palavras) != EOF ){
    random++;
  }

  /*Sorteando palavras da lista*/
  a = 0;
  while (a <= TAM_LISTA){
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
      score = 10;
      score = score + 10;
      break;
    }
    fclose(lista);
    printf("%s \n", palavras);
  
  // Copiando a palavra
  
    strcpy(palavras2, palavras);
  //printf("Este é o strcpy: %s\n", palavras2);    
  
  
  //Embaralhando a palavra
  
    for(i = 0; i < strlen(palavras); i++){
      x = rand() % strlen(palavras);
      c = 0;
      if (i == 0){
        anagrama[i] = palavras[x];
        r[i] = x;
      }
      else{
        for(j = 0; j < i; j++){
          if(r[j] != x){
            c++;
          }
          else{
            x = rand()%strlen(palavras);
            c = 0;
            j = -1;
          }
          if(c == i){
            anagrama[i] = palavras[x];
            r[i] = x;
          }
        }    
      }
    }
    printf("%s\n", anagrama);
  
  //Resposta
    scanf("%s", resposta);
    if(strcmp (resposta, palavras) == 0){
   //Fazer uma lista de frases!
      printf("Acertou!\n\nSCORE: %d\n\nDeseja jogar mais?\n\n", score);
      printf("1.SIM!\n2.NAO!\n\n");
      scanf("%d", &decisao);
      if(decisao == 2){
        printf("Poxa! Você nao pode desistir agora, tenha determinação!\n\nDeseja realmente sair?\n\n");
        printf("1.SIM! ME DEIXA!\n2.NAO! Eu quero ficar mais um pouquinho!\n\n");
        scanf("%d", &decisao);
        if(decisao == 1){
          return 0;
        }
        else if(decisao == 2){
          printf("Te amo! <3\n");
          continue;
        }
      }
      else if(decisao == 1){
        printf("Brabo(a) tem nome!\n");
        continue; 
      }
    }
    else{
      printf("Nao foi dessa vez! Tente novamente!");
      continue;
    }
  } 
  return 0;
}
