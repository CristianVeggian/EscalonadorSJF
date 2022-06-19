#ifndef _SCHEDULER
#define _SCHEDULER

#include "jobs.h"


LISTA SchedNaoPreemptivo(ITEM *vetor, int tam){

    LISTA cronograma;

    iniciaLista(&cronograma);

    appendLista(&cronograma, vetor[0]); //adiciona o primeiro processo que chegou à lista.

    float menor = 10000.0;
    int indiceMenor = 0;

    for(int k = 0; k < tam - 1; k++){
        menor = 10000.0;
        for(int i = 1; i < tam; i++){
            //acha o menor tempo de execução válido
            if(vetor[i].tExec < menor && vetor[i].tRes != 0.0){
                menor = vetor[i].tExec;
                indiceMenor = i;
            }
        }
        
        appendLista(&cronograma, vetor[indiceMenor]);
        vetor[indiceMenor].tRes = 0.0;
    }

    return (cronograma);
    
}


void scheduler_init(char* jobs, float quantum);




#endif
