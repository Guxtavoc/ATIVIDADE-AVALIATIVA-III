#include "funcoesPilha.h"
#include "funcoesPilhaf.h"
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
void converterExpressao(char posfixa[],char expressao[]){
    int tamanho,j=0;
    tamanho=(int)strlen(expressao);
    Pilha p=criarPilha(tamanho);
    for(int i=0;i<tamanho;i++){
        if(expressao[i]=='('){
            empilha(expressao[i],p);
        }else if(expressao[i]==')'){
            while(!vazio(p)&&topo(p)!='(') { 
                posfixa[j++]=desempilha(p);
            }
            if(!vazio(p)){
                desempilha(p);
            }else{
                printf("Expressao invalida - Parentese sem par\n");
                posfixa[0]='\0';
                destroi(&p);
                return;
            }
        }else if(expressao[i]=='+'||expressao[i]=='-'||expressao[i]=='*'||expressao[i]=='/'){ 
            while(!vazio(p)&&prio(topo(p))>=prio(expressao[i])){
                posfixa[j++]=desempilha(p);
            }
            empilha(expressao[i],p);
        }else if(isalnum(expressao[i])){
            posfixa[j++]=expressao[i];
        }
    }
    while(!vazio(p)){
        posfixa[j++]=desempilha(p);
    }
    posfixa[j]='\0';
    printf("Expressao posfixa: %s\n",posfixa);//debug
    if(posfixa[j-1]=='('){
        printf("Expressao invalida - Parentese sem par\n");
        posfixa[0]='\0';
        destroi(&p);
        return;
    }
    if(posfixa[j-1]=='+'||posfixa[j-1]=='-'||posfixa[j-1]=='*'||posfixa[j-1]=='/'){
    }else{
        printf("Expressao invalida - Falta operador binario 3\n");
        posfixa[0]='\0';
        destroi(&p);
        return;
    }
    int operando= 0,operador=0;
    for(int i=0;i<j;i++){
        if(isalpha(posfixa[i])){
            operando++;
        }else if(posfixa[i]=='+'||posfixa[i]=='-'||posfixa[i]=='*'||posfixa[i]=='/'){
            operador++;
            if(operando<2){
                printf("Expressao invalida - Falta operador binario 2\n");
                posfixa[0]='\0';
                destroi(&p);
                return;
            }
            operando--;
        }
    }
    destroi(&p);
}
variaveis* recebeVariaveis(char posfixa[]){
    variaveis *letra=NULL;
    int qtd=0;
    int tamanho=(int)strlen(posfixa);
    for(int i=0;i<tamanho;i++){
        if(isalpha(posfixa[i])){
            int existe=0;
            for(int j=0;j<qtd;j++){
                if(letra[j].variavel==posfixa[i]){
                    existe=1;
                    break;
                }
            }
            if(!existe){
                variaveis *temp=(variaveis*)realloc(letra, (size_t)(qtd + 1)*sizeof(variaveis));
                letra=temp;
                letra[qtd].variavel=posfixa[i];
                printf("Digite o valor de %c: ",letra[qtd].variavel);
                scanf("%f",&letra[qtd].valor);
                qtd++;
            }
        }
    }
    letra->qnt=qtd;
    return letra;
}
float avaliaExpressao(char posfixa[], variaveis *letra, int qtdVariaveis){
    Pilhaf p=criarPilhaf(256);
    int tamanho=(int)strlen(posfixa);
    for(int i=0;i<tamanho;){
        if(isalpha(posfixa[i])&&posfixa[i]!='\0'){
            for(int j=0;j<qtdVariaveis;j++){
                if(letra[j].variavel==posfixa[i]&&letra[j].variavel!='\0'){
                    empilhaf(letra[j].valor,p);
                    printf("iteracao %d Empilhando %c = %.2f\n",i,letra[j].variavel,letra[j].valor);
                    break;
                }
            }
            i++;
        }else if((posfixa[i]=='+'||posfixa[i]=='-'||posfixa[i]=='*'||posfixa[i]=='/')&&posfixa[i]!='\0'){
            float a=desempilhaf(p);
            float b=desempilhaf(p);
            printf("operador %c encontrado, desempilhando b = %.2f e a = %.2f\n",posfixa[i],b,a);
            switch(posfixa[i]){
                case '+':
                empilhaf(b+a,p);
                printf("iteracao %d Empilhando %.2f+%.2f, Topo = %.2f\n",i,
                b,a,topof(p));
                break;
                case '-':
                empilhaf(b-a,p);
                printf("iteracao %d Empilhando %.2f-%.2f, Topo = %.2f\n",i,b,a,topof(p));
                break;
                case '*':
                empilhaf(b*a,p);
                printf("iteracao %d Empilhando %.2f*%.2f, Topo = %.2f\n",i,b,a,topof(p));
                break;
                case '/':
                empilhaf(b/a,p);
                printf("iteracao %d Empilhando %.2f/%.2f, Topo = %.2f\n",i,b,a,topof(p));
                break;
            }
            i++;
        }else{
            i++;
        }
    }
    float resultado=desempilhaf(p);
    destroif(&p);
    return resultado;
}