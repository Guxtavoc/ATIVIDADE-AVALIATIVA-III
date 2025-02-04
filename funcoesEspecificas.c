#include "funcoesPilha.h"
#include "funcoesEspecificas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int prio(char op){
    switch(op){
        case '(':
        return 0;
        case '-':
        case '+':
        return 1;
        case '*':
        case '/':
        return 2;
    }
    return -1;
}
//achar um jeito de retornar a expressao posfixa para menu
void converterExpressao(char posfixa[],char expressao[]){//Completa
    //char expressao[256];
    int tamanho,j=0;
    //Mudando o loop para receber a expressão para o menu para salvar a expressao original
    /*int op;
    do {//loop para receber a expressao
        printf("Digite a expressao: ");
        scanf("%s",expressao);
        printf("A expressao: %s esta correta?\n",expressao);
        printf("1 - Sim 0 - Nao: ");
        scanf("%d", &op);
    }while(op!=1);*/
    tamanho=(int)strlen(expressao);
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
    destroi(&p);

}
//Criar uma função para identificar as diferentes variáveis e receber seus valores em ordem alfabética
//Criar uma strut para armazenar as variáveis e seus valores? FEITO! NECESSARIO TALVEZ...
void recebeVariaveis(char posfixa[]){//Completa, Ajustada para diferenciar variáveis minusculas e maiusculas
    variaveis *letra=NULL;
    int qtd=0;
    int tamanho=(int)strlen(posfixa);
    for(int i=0;i<tamanho;i++){
        if(isalpha(posfixa[i])){//Verifica se é uma letra
            int existe=0;//Redefine a variável para 0
            for(int j=0;j<qtd;j++){
                if(letra[j].variavel==posfixa[i]){
                    existe=1;
                    break;
                }
            }
            if(!existe){
                variaveis *temp=(variaveis*)realloc(letra, (size_t)(qtd + 1) * sizeof(variaveis));//Utilizar variavel auxialiar para realocar a memória para evitar bugs
                                                        //Casting para int para evitar warnings
                letra=temp;
                letra[qtd].variavel=posfixa[i];
                printf("Digite o valor de %c: ",letra[qtd].variavel);
                scanf("%f",&letra[qtd].valor);
                qtd++;
            }
        }
    }
    printf("\nVariaveis e seus valores:\n");
    for(int i=0;i<qtd;i++){
        printf("%c = %.2f\n",letra[i].variavel,letra[i].valor);
    }
    free(letra);
}

//Criar uma função para avaliar a expressão posfixa
//Criar uma função para calcular a expressão posfixa