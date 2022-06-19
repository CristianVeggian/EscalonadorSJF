#include "load_jobs.h"
#include "scheduler.h"

/*
Benchmarks 

*/

int tam;

int main(int argc, char* argv[]){

	// if(argc != 2){
	// 	printf("\n Erro de utilização \n\n Uso:\n\t ./broker 'lista_de_processos' \n\n"); 
	// 	return 1;
	// }
    
	ITEM *procs = loadJobs("processos.txt", &tam); //vetor com os processos na ordem de leitura. Vai ser enviado para o scheduler

    LISTA cronograma = SchedNaoPreemptivo(procs, tam);

    printaLista(&cronograma);
    

    //iniciarProcessos(procs);

	
	
    
	return 0;
}
