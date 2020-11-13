#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
  
#define PENSAR 0        //Id para estado pensando
#define ESPERAR 1       //Id para estado esperando
#define COMER 2         //Id para estado comendo
 
typedef struct nfilosofos{      //Estrutura de dados dos filósofos
        int quantidadeF;              //Quantidade de filósofos
        int tempoPensar;             //Tempo para pensar
        int tempoComer;             //Tempo para comer
        int id;                 //Índice do filósofo
}NFilosofos;

int *estado;            //Vetor que armazena os estados de cada thread
sem_t macarrao;        //Representa a comida que os filosofos irão comer
sem_t *garfo;           //Vetor que representa os garfos
 
void *filosofo (void *F);
void comer (NFilosofos F);
void esperar (NFilosofos F);
void pensar (NFilosofos F);
void mostrar (int i);
void teste (int i,int quantidade);
  
