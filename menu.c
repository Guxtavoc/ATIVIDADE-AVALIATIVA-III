#include "menu.h"
#include "funcoesEspecificas.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void menu(){
    int op;
    char posfixa[256],expressao[256];
    posfixa[0]='\0';
    variaveis *letra=NULL;
    do{
        printf("1 - Definicao da expressao\n2 - definicao do valor das variaveis\n3 - Avaliacao da expressao\n0 - Sair\n");
        printf("Selecione a opcao que deseja: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                do {
                    printf("Digite a expressao: ");
                    scanf("%s",expressao);
                    printf("A expressao: %s esta correta?\n",expressao);
                    printf("1 - Sim 0 - Nao: ");
                    scanf("%d", &op);
                }while(op!=1);
                strcpy(posfixa,expressao);
                converterExpressao(posfixa,expressao);
                letra=NULL;
                break;
            case 2:
            if(strlen(posfixa)!=0){
                printf("Expressao original: %s\nExpressao posfixa: %s\n",expressao,posfixa);
                letra=recebeVariaveis(posfixa);        
            }else{
                printf("Defina a expressao primeiro\n");
            }
                break;
            case 3:
                printf("Avaliacao da expressao\n");
                if(strlen(posfixa)!=0&&letra!=NULL){
                    float resultado=avaliaExpressao(posfixa,letra,letra->qnt);
                    printf("Resultado: %.2f\n",resultado);
                }else{
                    printf("Defina a expressao e as variaveis primeiro\n");
                }
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    }while(op!=0);
    if (letra!=NULL){
        free(letra);
    }   
}