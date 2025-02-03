#include "funcoesPilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void converterExpressao(){
    char expressao[256];
    int op,tamanho,j=0;
    do {//loop para receber a expressao
        printf("Digite a expressao: ");
        scanf("%s",expressao);
        printf("A expressao: %s esta correta?\n",expressao);
        printf("1 - Sim 0 - Nao: ");
        scanf("%d", &op);
    } while(op != 1);
    tamanho=(int)strlen(expressao);
    char posfixa[tamanho+1];
    posfixa[0]='\0';
    Pilha p=criarPilha(tamanho);//cria uma pilha com o tamanho da expressao
    for(int i=0;i<tamanho;i++){
        if(expressao[i]=='('){//se acha um parenteses abrindo, empilha
            empilha(expressao[i],p);
        }else if(expressao[i]==')'){//se acha um parenteses fechando, desempilha ate achar o parenteses abrindo
            while(topo(p)!='('){
                //printf("%c",desempilha(p));
                posfixa[j++]=desempilha(p);
            }
            desempilha(p);//Remove ( da pilha
        }else if(expressao[i]=='+'||expressao[i]=='-'||expressao[i]=='*'||expressao[i]=='/'){//se acha um operador, desempilha ate achar um operador de menor prioridade
            while(!vazio(p)&&prio(topo(p))>=prio(expressao[i])){//enquanto a pilha nao estiver vazia e o operador do topo da pilha for de maior ou igual prioridade
                //printf("%c",desempilha(p));
                posfixa[j++]=desempilha(p);
            }
            empilha(expressao[i],p);
        } else {//se acha um operando, imprime
            //printf("%c",expressao[i]);
            posfixa[j++]=expressao[i];
        }
    }
    while(!vazio(p)){
        //printf("%c",desempilha(p));
        posfixa[j++]=desempilha(p);
    }
    printf("\n");
    printf("Expressao posfixa: %s\n",posfixa);
    destroi(&p);
}