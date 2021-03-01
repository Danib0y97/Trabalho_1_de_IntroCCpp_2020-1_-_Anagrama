/*

  * Trabalho de Introdução a C/C++
  * Programa: Jogo de Anagrama
  * Autores: Julia Deroci & Daniel Ferreira
  * Data: 27/02/2021

*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>


#define TAM_LISTA 58


int main(){


  //Inteiros
  int i = 0, j = 0, c = 0, x = 0, npalavras = 0, score = 0, sorteio = 0, decisao, tam_resposta, tam_anagrama;

  //Arquivo
  FILE *lista;

  //Strings
  char palavra[TAM_LISTA], palavraslista[TAM_LISTA], anagrama[TAM_LISTA],
  r[TAM_LISTA], resposta[TAM_LISTA], * comparar;

  //Comando de Regionalização
  setlocale(LC_ALL, "");

  //Zerar String
  memset(anagrama, 0, sizeof(anagrama));



  menu:
  printf(" //////////////////////////// Seja Bem-Vindo(a)! /////////////////////////////\n\n\n");

  printf("    ______________________________________________________________________ \n");
  printf(" ________  __   __  ________  ________  _______  ________  ___  ___  ________ \n");
  printf("|   __   ||  | |  ||   __   ||   _____||  __   ||   __   ||   |/   ||   __   |\n");
  printf("|  |__|  ||    |  ||  |__|  ||  | ____ | |_ /  ||  |__|  ||        ||  |__|  |\n");
  printf("|   __   ||  |    ||   __   ||  |__|  ||      / |   __   ||  | /|  ||   __   |\n");
  printf("|__|  |__||__| |__||__| |___||________||__||__| |__|  |__||__|  |__||__|  |__|\n");
  printf("    ______________________________________________________________________  \n");

   printf("\n\nCreated by: Julia Deroci & Daniel Ferreira.\n\n");

  
  do{

    printf("\n\n\n\t1.Iniciar\n\t2.Como jogar?\n\t3.Sair\n\n\n");
    printf("\t");
    scanf("%d", &decisao);

    system("cls");
    switch(decisao){

      case 1:
        printf("\nPronto?!...");
        Sleep(2000);
        printf("Vamos lá!\n\t\n\t\n\t\n");
        break;
      case 2:
        printf("    _____________________________________________________________________\n");
        printf("\n\n\tO objetivo desse jogo é formar anagramas com as letras \n\tque serão apresentadas na tela.\n");
        printf("\n\n\tDigite:\n\n\t- 'RANDOM' para gerar novas letras.\n\t- '0' para voltar ao menu.\n\t- 'FIM' para sair do jogo.\n");
        printf("\n\tCARACTERES ESPECIAIS NÃO SERÃO CONSIDERADOS.\n");
        printf("\n\n\tDivirta-se!\n");
        printf("\n    _____________________________________________________________________");

        printf("\n\n\n\t1.Voltar\n\n");
        printf("\t");
        scanf("%d", &decisao);
        system("cls");

        if(decisao == 1){
          goto menu;
        }
        else{
          printf("\n\n\n\tEscolha entre umas das opções!\n\n");
          continue;
        }
      case 3:
        printf("\n\n\n\n\n\n\n\n\n\t\t\tTchau, amigo(a)! Até a próxima!\n\n\n\n\n\n\n\n\n\n\n");
        return 0;
      default:
        printf("\n\n\n\tEscolha entre umas das opções!\n\n");
        continue;
      }
    break;
  } while(1);

  //Abrindo o Arquivo e Lendo as Palavras
  lista = fopen("palavras.txt", "r");
  if(lista == NULL){
    printf("\n\n\n\n\tO arquivo não pode ser aberto.\n\n\n\n\n");
    exit(1);
  }

  while(fscanf( lista, "%s", palavra) != EOF ){
    npalavras ++;
  }

  printf("As letras são: ");

  while(1){

    //Sorteando Palavras da Lista
    rewind(lista);
    srand(time(NULL));
    sorteio = rand() % (npalavras + 1);

    for(i = 0; i < sorteio; i++){
      fscanf(lista, "%s", palavra);
    }

    //Zerando a String
    memset(anagrama, 0, sizeof(anagrama));

    start:
    //Embaralhando a Palavra
    for(i = 0; i < strlen(palavra); i++){

      x = rand() % strlen(palavra);
      c = 0;
      if (i == 0){
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
    }
    printf("%s\n\n", anagrama);
    printf("\n");

    //Resposta
    scanf("%s", resposta);

    //Tranformando em Letra Maiúscula
    tam_resposta = strlen(resposta);
    for(i = 0; i < tam_resposta; i++){
      resposta[i] = toupper(resposta[i]);
    }

    //Randomizar a Palavra
    if(strcmp(resposta,"RANDOM") == 0){
      printf ("\n\nAs novas letras são: ");
      continue;
    }

    //Condição de Parada
    if(strcmp(resposta,"FIM") == 0){
      break;
    }

    //Voltar ao Menu
    if(strcmp(resposta,"0") == 0){
      fclose(lista);
      system("cls");
      goto menu;
    }

    //Comparando Tamanho
    tam_anagrama = strlen(anagrama);

    if(tam_resposta != tam_anagrama){
      printf("Não é um anagrama!\n\n\nTente novamente: ");
      goto start;
    }

    //Comparando Char
	if (strspn(anagrama, resposta) != strlen(anagrama)) {
		printf("Não é um anagrama!\n\n\nTente novamente: ");
		goto start;
	}

    //Comparando com Palavras da Lista
    rewind(lista);
    while(fgets(palavraslista, sizeof(palavraslista), lista)){
      comparar = strstr(palavraslista, resposta);
      if (comparar){
        break;
      }
    }
    if (comparar){
      score = score + 10;
      printf("É um anagrama!\n\n\n");
      printf ("\nAs letras são: ");
      continue;
      }
      else{
        printf("Não é um anagrama!\n\n\nTente novamente: ");
        goto start;
      }
    }
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t  SCORE: %d\n\n\n", score);
    printf("\n\n\t\t\t Obrigado por jogar! Até mais!\n\n\n\n\n\n\n\n\n\n\n");
    fclose(lista);
  return 0;
}
