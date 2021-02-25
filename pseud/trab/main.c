#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define TAM_LISTA 9

int menu (inicio) {
 
 int intro, nivel;

  printf("///////Seja bem-vindo a ANAGRAMA!///////\n");

  printf("0.Sair\n1.Iniciar\n");
  scanf("%d", &intro);
  if ( intro == 1){
    printf("Escolha um nível para jogar:\n1.Fácil\n2.Médio\n3.Difícil\n");
    scanf("%d", &nivel);

    switch (nivel){;
    case 1:
      printf("Voce escolheu o nível %d - Fácil\n", nivel);
      break;
    case 2:
      printf("Voce escolheu o nível %d - Médio\n", nivel);
      break;
    case 3:
       printf("Voce escolheu o nível %d - Difícil\n", nivel);
       break;
    }   
 }else {
     printf("Tchau amigo, até à próxima");
  }
  return 0;
}



int main(){
  
  /*Contadores de palavras*/
  int a, i = 0, j = 0, c = 0, x = 0, score = 0, decisao;  
  /*Arquivo*/
  FILE *lista;
  /* Palavras da lista*/
  char palavras[20], palavras2[20], anagrama[20], r[20], resposta[20]; 
  /*Sorteia a palavra aleatória da lista*/
  int random = 0, sorteio = 0, nivel;

  a = 0;
  while (a <= TAM_LISTA){
    menu(a);
    /* função do menu */
  
    /*Abrindo o arquivo e lendo as palavras*/
      if (nivel == 1){
        lista = fopen("facil.txt", "r");
        if(lista == NULL){
            printf("O arquivo não pode ser aberto.\n");
            exit(1);
        }
      }
       if (nivel == 2){
        lista = fopen("medio.txt", "r");
        if(lista == NULL){
            printf("O arquivo não pode ser aberto.\n");
            exit(1);
        }
       }
        if (nivel == 3){
        lista = fopen("dificil.txt", "r");
        if(lista == NULL){
            printf("O arquivo não pode ser aberto.\n");
            exit(1);
        } 
      }  

  
    //lista = fopen("palavras.txt", "r");
   // if(lista == NULL){
     // printf("O arquivo não pode ser aberto.\n");
     // exit(1);
    ///}
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
      score = score + 10;
      break;
    }
    fclose(lista);
    printf("%s\n", palavras);
  
    /*Copiando a palavra*/
    strcpy(palavras2, palavras);
    /*printf("Este é o strcpy: %s\n", palavras2); */   
  
  
    /*Embaralhando a palavra*/
  
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
            j= -1;
        
          
        }
          if(c == i){
            anagrama[i] = palavras[x];
            r[i] = x;
        }
      }    
    }
  }
    printf("\nResponda com letra maiuscula!\n\n");
    printf("%s\n\n", anagrama);
  
   /*Resposta*/
    scanf("%s", resposta);
    if(strcmp (resposta, palavras) == 0){
   /*Fazer uma lista de frases!*/
      printf("\nAcertou!\n\nSCORE: %d\n\nDeseja jogar mais?\n\n", score);
      printf("1.SIM!\n2.NAO!\n\n");
      scanf("%d", &decisao);
      
      if(decisao == 2){
        printf("\nPoxa! Voce nao pode desistir agora, tenha determinacao!\n\nDeseja realmente sair?\n\n");
        printf("1.SIM! ME DEIXA!\n2.NAO! Eu quero ficar mais um pouquinho!\n\n");
        scanf("%d", &decisao);
        
        if(decisao == 1){
          printf("\nOk, entao!\nAte logo! :c\n\n");
          return 0;
        }
        else if(decisao == 2){
          printf("\nTe amo! <3\n\n");
        }
      }
      else if(decisao == 1){
        printf("\nBrabo(a) tem nome!\n\n");
      }
    }
    else{
      printf("\nNao foi dessa vez! Tentar novamente?\n\n");
      printf("1.SIM!\n2.NAO!\n\n");
      
      if(decisao == 2){
        break;
      }
      else if(decisao == 1){
      }
    } 
    continue;
  }
  return 0;
}