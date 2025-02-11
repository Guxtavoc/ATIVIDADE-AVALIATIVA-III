#include "funcoesPilha.h"
#include <stdio.h>
#include <stdlib.h>
int vazio(Pilha P){
    if(P->topo==-1)
        return 1;
    else 
        return 0;
}
int cheio(Pilha P){
    if(P->topo==P->max-1)
        return 1;
    else 
        return 0;
}
Pilha criarPilha(int n){
    Pilha P=malloc(sizeof(struct pilha));
    P->max=n;
    P->topo=-1;
    P->item=malloc((size_t)n*sizeof(Itemp));
    return P;
}
void empilha(Itemp x,Pilha P){
    if(cheio(P)){
        printf("Pilha cheia!\n");
        return;
    }
    P->topo++;
    P->item[P->topo] = x;
}
Itemp desempilha(Pilha P){
    if(!vazio(P)){
    Itemp x=P->item[P->topo];
    P->topo--;
    return x;
    }else
    printf("Pilha vazia\n");
        return 0;
}
Itemp topo(Pilha P){
    if(vazio(P)){
        printf("pilha vazia!\n");
        return 0;
    }
    return P->item[P->topo];
}
void destroi(Pilha *p){
    free((*p)->item);
    free(*p);
    *p = NULL;
}