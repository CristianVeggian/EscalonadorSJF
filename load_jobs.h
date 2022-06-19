#ifndef _LOADJOBS
#define _LOADJOBS

#include "jobs.h"
#include "lista.h"

ITEM *loadJobs(char* file, int *tam){
    
    FILE *arq = fopen(file, "r");
    
    if(arq == NULL){
        printf("Erro abrindo arq");
    }
    
    ITEM *proc;
    proc = (ITEM*) malloc(2*sizeof(ITEM));
    
    char buffer[100], *aux;
    int c;
    
    for(int i = 0; !feof(arq); i++){
        if(i > 1){
            proc = (ITEM*) realloc(proc, (i+1)*sizeof(ITEM));
        }
        fscanf(arq, "%f ", &proc[i].tChegada);
        fscanf(arq, "%f ", &proc[i].tExec);
        proc[i].tRes = proc[i].tExec;
        c = 0;
        fgets(buffer, 100, arq);
        buffer[strcspn(buffer, "\n")] = 0;
        aux = strtok(buffer, " ");
        strcpy(proc[i].pname, aux);
        while(1) {    
            aux = strtok(NULL, " ");
            if(aux == NULL) break;
            proc[i].argv[c] = (char*) malloc(30*sizeof(char));
            strcpy(proc[i].argv[c], aux); 
            c++;
        }
        proc[i].argc = c;
        *tam = i + 1;
    }
    
    fclose(arq);

    return proc;
    
}


#endif
