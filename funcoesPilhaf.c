#include "funcoesPilhaf.h"
#include <stdio.h>
#include <stdlib.h>
int vaziof(Pilhaf P){
    if(P->topo==-1)
        return 1;
    else 
        return 0;
}
int cheiof(Pilhaf P){
    if(P->topo==P->max-1)
        return 1;
    else 
        return 0;
}
Pilhaf criarPilhaf(int n){
    Pilhaf P=malloc(sizeof(struct pilhaf));
    P->max=n;
    P->topo=-1;
    P->item=malloc((size_t)n*sizeof(Itemf));
    return P;
}
void empilhaf(Itemf x,Pilhaf P){
    if(cheiof(P)){
        printf("Pilha cheia!\n");
        return;
    }
    P->topo++;
    P->item[P->topo] = x;
}
Itemf desempilhaf(Pilhaf P){
    if(!vaziof(P)){
    Itemf x=P->item[P->topo];
    P->topo--;
    return x;
    }else
    printf("Pilha vazia\n");
        return 0;
}
Itemf topof(Pilhaf P){
    if(vaziof(P)){
        printf("pilha vazia!\n");
        return 0;
    }
    return P->item[P->topo];
}
void destroif(Pilhaf *p){
    free((*p)->item);
    free(*p);
    *p = NULL;
}