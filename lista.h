#ifndef LISTADUPLA_H
#define LISTADUPLA_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

#ifndef _STDBOOL_H
#include <stdbool.h>
#endif

#ifndef _STDIO_H
#include <stdio.h>
#endif

    typedef struct {
        char pname[30];
        int argc;
        float tChegada;
        float tExec;
        float tRes;
        char *argv[30];
    } ITEM;

    typedef struct NOLISTA* PTRNOLISTA;

    typedef struct NOLISTA {
        PTRNOLISTA forward;
        ITEM obj;
    } NOLISTA;

    typedef struct {
        PTRNOLISTA start;
        int size;
    } LISTA;

    void iniciaLista(LISTA *p) {
        p->start = NULL;
        p->size = 0;
    }

    bool isVazio(LISTA *p) {
        return (p->start == NULL);
    }

    bool appendLista(LISTA *p, ITEM obj) {
        PTRNOLISTA novo = (PTRNOLISTA) malloc(sizeof (NOLISTA));
        strcpy(novo->obj.pname, obj.pname);
        novo->obj.argc = obj.argc;
        novo->obj.tChegada = obj.tChegada;
        novo->obj.tExec = obj.tExec;
        for(int i = 0; i < obj.argc; i++){
            novo->obj.argv[i] = (char*) malloc(sizeof(obj.argv[i]));
            strcpy(novo->obj.argv[i], obj.argv[i]);
        }

        novo->forward = NULL;

        if (isVazio(p)) {
            p->start = novo;
        } else {
            PTRNOLISTA aux = p->start;
            while (aux->forward != NULL)
                aux = aux->forward;
            aux->forward = novo;
        }
        p->size++;
        return true;
    }

    void printaLista(LISTA *p) {
        PTRNOLISTA aux = p->start;
        while (aux != NULL) {
            printf("| Chegada em %.2f durante %.3f ut|\n", aux->obj.tChegada, aux->obj.tExec);
            printf("| Processo %s | \n| Argumentos ", aux->obj.pname);
            for(int i = 0; i < aux->obj.argc; i++)
                printf(" - %s ", aux->obj.argv[i]);
            printf("| \n *********************** \n");
            aux = aux->forward;
        }
        printf("\n");
    }

    bool removeLista(LISTA *p, ITEM *item) {
        if (isVazio(p))
            return false;
        
        PTRNOLISTA aux = p->start;

        p->start = p->start->forward;
        
        strcpy(item->pname, aux->obj.pname);
        item->argc = aux->obj.argc;
        item->tChegada = aux->obj.tChegada;
        item->tExec = aux->obj.tExec;
        
        for(int i = 0; i < aux->obj.argc; i++){
            item->argv[i] = (char*) malloc(sizeof(aux->obj.argv[i]));
            strcpy(item->argv[i], aux->obj.argv[i]);
        }
        
        free(aux);
        
        p->size--;
        return true;
    }

#ifdef __cplusplus
}
#endif

#endif /* LISTADUPLA_H */
