/*
Projeto: Avaliação 3
Arquivo: menu.c -> Função que exibe o menu do programa e chama as funções de acordo com a escolha do usuário
Nome: Gustavo Curado e Daniel Barros
Data: 13/02/2025
*/
#include "menu.h"
#include "funcoesEspecificas.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void menu(){
    int op;
    char posfixa[256],expressao[256];
    posfixa[0]='\0';
    variaveis *letra=NULL;
    do{
        printf("1 - Definicao da expressao\n2 - definicao do valor das variaveis\n3 - Avaliacao da expressao\n4 - Informacoes adicionais\n0 - Sair\n");
        printf("Selecione a opcao que deseja: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Operacoes validas: + - * / ^ #\n");
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
                if(strlen(posfixa)!=0&&letra!=NULL){
                    float resultado=avaliaExpressao(posfixa,letra,letra->qnt);
                    if(isnan(resultado)){
                        printf("Erro na expressao\n");
                    }else{
                        printf("Resultado: %.2f\n",resultado);
                    }
                    
                }else{
                    if(strlen(posfixa)==0){
                        printf("Defina a expressao primeiro\n");
                }else{
                    printf("Defina as variaveis primeiro\n");
                }
                }
                break;
                case 4:
                printf("A expressao deve ser digitada sem espacos\nVariaveis maiuculas e minusculas sao lidas individualmente\nOperacoes validas: + - * / ^ #\n");
                printf("O simbolo # representa a raiz, sendo necessario indicar o exponte\nAs equacoes consideram apenas o resultado positivo de uma raiz com expoente par\n");
                printf("O programa processa raizes negativas, contanto que o expoente seja impar \nExemplo: 4#2 = 2\nExenplo: -8#3 = -2\nA cada vez que uma expressao eh inserida as variaveis anteriores sao resetadas\n");
                printf("O Programa NAO aceita expressoes com colchetes ou chave\n\n");
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