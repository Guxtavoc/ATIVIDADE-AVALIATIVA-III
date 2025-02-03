#include "menu.h"
#include "funcoesEspecificas.h"
#include <stdio.h>

void menu(){
    int op;
    do{
        printf("1 - Definicao da expressao\n2 - definicao do valor das variaveis\n3 - Avaliacao da expressao\n0 - Sair\n");
        printf("Selecione a opcao que deseja: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Definicao da expressao\n");
                converterExpressao();
                break;
            case 2:
                printf("Definicao do valor das variaveis\n");
                break;
            case 3:
                printf("Avaliacao da expressao\n");
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    }while(op!=0);
}