#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>

#define TAM_LISTA 50


int main(){


  /*Contadores*/
  int i = 0, j = 0, c = 0, x = 0, score = 0;  
  
  /*Arquivo*/
  FILE *lista;  
  
  /*Palavras da lista*/
  char palavra[TAM_LISTA], palavraslista[TAM_LISTA], anagrama[TAM_LISTA], 
  r[TAM_LISTA], resposta[TAM_LISTA], * comparar;
  
  /*Inteiros*/
  int sorteio = 0, decisao, tam_resposta, tam_anagrama;
 

  printf("////////// Seja bem-vindo(a) ao ANAGRAMA! //////////\n\n");
  
   printf("\nCreated by: Julia Deroci & Daniel Ferreira.\n\n");
  
  do{
    
    printf("\n1.Iniciar\n2.Como jogar?\n3.Sair\n\n");
    scanf("%d", &decisao);
  
    switch(decisao){
        
      case 1:
        printf("\nPronto?! Vamos lá!\n\n");
        break;
      case 2:
        printf("\nO objetivo desse jogo e formar um anagrama com as letras que serao apresentadas na tela.\nDigite RANDOM para gerar uma nova palavra e FIM para sair do jogo!\nCARACTERES ESPECIAIS NÃO SERÃO CONSIDERADOS.\n\nDivirta-se!\n");

        printf("\n1.Voltar\n2.Sair\n\n");
        scanf("%d", &decisao);
        if(decisao == 1){
          continue;
        }
        else if(decisao == 2){
          return 0;
        }
        else{
          printf("\nEscolha entre umas das opções!\n\n");
          continue;
        }   
      case 3:
        printf("\nTchau, amigo! Até a próxima!\n\n");
        return 0;
      default:
        printf("\nEscolha entre umas das opções!\n\n"); 
        continue;
      }
    break;
  } while(1);
  
  
  /*Abrindo o arquivo e lendo as palavras*/
    
    lista = fopen("palavras.txt", "r");
    if(lista == NULL){
      printf("O arquivo não pode ser aberto.\n");
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
        }
      }
      break;
    }


    /*Embaralhando a palavra*/

    for(i = 0; i < strlen(palavra); i++){

      x = rand() % strlen(palavra);
      c = 0;
      if (i == 0) {
        anagrama[i] = palavra[x];
        r[i] = x;
      }
      else {
        for(j = 0; j < i; j++){
          if(r[j] != x) {
            c++;
          }
          else {
            x = rand() % strlen(palavra);
            c = 0;
            j = -1;
          }
          if(c == i) {
            anagrama[i] = palavra[x];
            r[i] = x;
          }
        }  
      }
      //Consertando o erro (VER DEPOIS)
      if(isalpha(anagrama[i]) != 0 || strlen(anagrama) != strlen(palavra)){ 
        continue;
      }
    }  
    printf("%s\n\n", anagrama);
    

  /*Resposta*/
    
    scanf("%s", resposta);


  /*Tranformando em letra maiúscula*/
    
    tam_resposta = strlen(resposta);
    for(i = 0; i < tam_resposta; i++){
      resposta[i] = toupper(resposta[i]);
    }


  /*Randomizar a palavra*/
    
    if(strcmp(resposta,"RANDOM") == 0){
      printf ("\nNova palavra:\n\n");
      continue;
    }

  /*Condição de parada*/
    
    if(strcmp(resposta,"FIM") == 0){
      break;
    }
  
  /*Comparando tamanho e com palavras da lista*/
    
    tam_anagrama = strlen(palavra);
    if(tam_resposta != tam_anagrama){
      printf("Não é um anagrama!\n\n");
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
      printf("É anagrama!\n\n");
      continue;
      }
      else{
        printf("Não é anagrama!\n\n");
        continue;
      }  
    }      
    
    fclose(lista);  
    printf("\nSCORE: %d\nObrigado por jogar! Até mais!\n", score);
  return 0;
}
