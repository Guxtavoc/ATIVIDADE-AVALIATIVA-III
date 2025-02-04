#include "menu.h"
#include "funcoesEspecificas.h"
#include <stdio.h>
#include <string.h>
void menu(){
    int op;
    char posfixa[256],expressao[256];
    do{
        printf("1 - Definicao da expressao\n2 - definicao do valor das variaveis\n3 - Avaliacao da expressao\n0 - Sair\n");
        printf("Selecione a opcao que deseja: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                do {//loop para receber a expressao
                    printf("Digite a expressao: ");
                    scanf("%s",expressao);
                    printf("A expressao: %s esta correta?\n",expressao);
                    printf("1 - Sim 0 - Nao: ");
                    scanf("%d", &op);
                }while(op!=1);
                strcpy(posfixa,expressao);
                converterExpressao(posfixa,expressao);
                break;
            case 2:
                printf("Expressao original: %s\nExpressao posfixa: %s\n",expressao,posfixa);
                recebeVariaveis(posfixa);
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