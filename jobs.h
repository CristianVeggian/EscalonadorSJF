#ifndef _JOBS
#define _JOBS

#include <stdio.h>     
#include <stdlib.h>    
#include <unistd.h>   
#include <signal.h>    
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include "lista.h"
#include "load_jobs.h"

key_t key;
int shmid;
int *pos;

void iniciarProcessos(LISTA lista){

    key = ftok("/home", 'A');                     
    shmid = shmget(key, 1024, 0644 | IPC_CREAT);   
    pos = (malloc(sizeof(int)));                       
    pos = shmat(shmid, (void *)0, 0);             

    *pos = 0;
    
    while(*pos < lista.size + 1){
        
        pid_t pid;
        ITEM proc;
        //dlistGetPos(&lista, &proc, *pos);
        (*pos)++;
        
        pid = fork();
        
        if(pid < 0){
            perror("\n\nDeu ruim na criação do processo\n\n");
            return;
        }
        if(pid == 0){ //processo atual
            usleep(1000*1000*proc.tExec);
            printf("Processo executado: %s \n", proc.pname);
        }else{ 
            wait(getppid());
        }
    }
}


#endif
