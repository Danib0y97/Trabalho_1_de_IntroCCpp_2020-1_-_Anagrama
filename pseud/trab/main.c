#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>

#define TAM_LISTA 20


int main(){

  /*Contadores*/
  int i = 0, j = 0, c = 0, x = 0, score = 0, decisao, tam_resposta, tam_anagrama;
  /*Arquivo*/
  FILE *lista;  
  /*Palavras da lista*/
  char palavra[TAM_LISTA], palavraslista[TAM_LISTA], anagrama[TAM_LISTA], 
  r[TAM_LISTA], resposta[TAM_LISTA], palavras_lidas[TAM_LISTA] = {0}, * comparar;
  /*Sorteia a palavra aleatória da lista*/
  int sorteio = 0;
 
  printf("////////// Seja bem-vindo a ANAGRAMA! //////////\n\n");

  do{
    printf("\n1.Iniciar\n2.Como jogar?\n3.Sair\n\n");
    scanf("%d", &decisao);
  
    switch(decisao){
        
      case 1:
        printf("\nPronto?! Vamos lá!\n\n");
        break;
      case 2:
        printf("\nO objetivo desse jogo e formar um anagrama com as letras que serao apresentadas na tela.\nDigite RANDOM para gerar uma nova palavra e FIM para sair do jogo!\n\nDivirta-se!\n");
        printf("\n1.Voltar\n2.Sair\n\n");
        scanf("%d", &decisao);
        if(decisao == 1){
          continue;
        }
        else if(decisao == 2){
          return 0;
        }
        else{
          printf("\nEscolha entre umas das opcoes!\n\n");
          continue;
        }   
      case 3:
        printf("\nTchau, amigo! Ate a proxima!\n\n");
        return 0;
      default:
        printf("\nEscolha entre umas das opcoes!\n\n"); 
        continue;
      }
    break;
  } while(1);
  
  
  /*Abrindo o arquivo e lendo as palavras*/
    
    lista = fopen("palavras.txt","r");
    if(lista == NULL) {
      printf("O arquivo nao pode ser aberto.\n");
      exit(1);
    }  


  while(1){  
    
    /*Sorteando palavras da lista*/
    
    while(fscanf(lista, "%s", palavra) != EOF){
      rewind(lista);
      srand(time(NULL));
      sorteio = rand() % TAM_LISTA;

      for(i = 0, j = 0; j < sorteio; i++){
        if(fgetc(lista) == '\n'){
          j++;
          fscanf(lista, "%s", palavra);
        }
      }
      break;
      fclose(lista);
    }
    printf("%s\n", palavra);


    /*Embaralhando a palavra*/    /*voltar*/

    for(i = 0; i < strlen(palavra); i++){

      x = rand() % strlen(palavra);
      c = 0;
      if (i == 0) {
        anagrama[i] = palavra[x];
        r[i] = x;
      }
      else {
        for(j = 0; j < i; j++) {
          if(r[j] != x) {
            c++;
          }
          else {
            x = rand()%strlen(palavra);
            c = 0;
            j = -1;
          }
          if(c == i) { 
            anagrama[i] = palavra[x];
            r[i] = x;
          }
        }  
      }
    }  
    printf("%s\n\n", anagrama);
    

  /*//////////Resposta//////////*/
    
    scanf("%s", resposta);


  /*Tranformando em letra maiúscula caso precise*/
    
    tam_resposta = strlen(resposta);
    for(i = 0; i < tam_resposta; i++){
      resposta[i] = toupper(resposta[i]);
    }


  /*Randomizar a palavra*/
    
    if(strcmp(resposta,"RANDOM") == 0){
      continue;
    }

  /*Condição de parada*/
    
    if(strcmp(resposta,"FIM")==0){
      printf("Obrigada por jogar! Ate mais!");
      return 0;
    }

  /////////////////* Não repetindo a palavra *////////////////////////

   /* for(i = 0; i < strlen(palavra); i++){
         n  =  palavras_lidas[0];
         palavras_lidas[0] = palavras_lidas[1];
         palavras_lidas[1] = palavras_lidas[0];
    } */
  
      
    //Comparando tamanho e com palavras da lista
    
    tam_anagrama = strlen(palavra);
    if(tam_resposta != tam_anagrama){
      printf("Nao e um anagrama!\n\n");
      printf("SCORE: %d\n\n", score);
      continue;
    }
    
    rewind(lista);
    while(fgets(palavraslista, sizeof(palavraslista), lista)){  
      comparar = strstr(palavraslista, resposta);
      if (comparar){
        break;
        
      }
    }
    if (comparar){
      score = score + 10;
      printf("E anagrama!\n\n");
      printf("SCORE: %d\n\n", score);
      continue;
      }
      else{
        printf("Nao e anagrama!\n\n");
        printf("SCORE: %d\n\n", score);
        continue;
      }  
    }  
    
    fclose(lista);  
  return 0;
}
