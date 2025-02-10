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
void converterExpressao(char posfixa[],char expressao[]){//Completa
    int tamanho,j=0;
    tamanho=(int)strlen(expressao);
    Pilha p=criarPilha(tamanho);//cria uma pilha com o tamanho da expressao
    for(int i=0;i<tamanho;i++){
        if(expressao[i]=='('){//se acha um parenteses abrindo, empilha
            empilha(expressao[i],p);
        }else if(expressao[i]==')'){//se acha um parenteses fechando, desempilha ate achar o parenteses abrindo
            while(topo(p)!='('){
                posfixa[j++]=desempilha(p);
            }
            desempilha(p);//Remove ( da pilha
        }else if(expressao[i]=='+'||expressao[i]=='-'||expressao[i]=='*'||expressao[i]=='/'){//se acha um operador, desempilha ate achar um operador de menor prioridade
            while(!vazio(p)&&prio(topo(p))>=prio(expressao[i])){//enquanto a pilha nao estiver vazia e o operador do topo da pilha for de maior ou igual prioridade
                posfixa[j++]=desempilha(p);
            }
            empilha(expressao[i],p);
        } else {//se acha um operando, imprime
            posfixa[j++]=expressao[i];
        }
    }
    while(!vazio(p)){
        posfixa[j++]=desempilha(p);
    }
    destroi(&p);
}
variaveis* recebeVariaveis(char posfixa[]){//Completa, Ajustada para diferenciar variáveis minusculas e maiusculas
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
                variaveis *temp=(variaveis*)realloc(letra, (size_t)(qtd + 1)*sizeof(variaveis));//Utilizar variavel auxialiar para realocar a memória para evitar bugs
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
float avaliaExpressao(char posfixa[], variaveis *letra, int qtdVariaveis){//Completa
    Pilhaf p=criarPilhaf(256);
    int tamanho=(int)strlen(posfixa),cont=0;
    printf("qtdVariaveis = %d\n",qtdVariaveis);//debug
    printf("tamamho = %d\n",tamanho);//debug
    for(int i=0;i<tamanho;){
        if(isalpha(posfixa[i])&&posfixa[i]!='\0'){//Se achar uma letra, empilha o valor correspondente
            for(int j=0;j<qtdVariaveis;j++){
                if(letra[j].variavel==posfixa[i]&&letra[j].variavel!='\0'){
                    empilhaf(letra[j].valor,p);
                    printf("iteracao %d Empilhando %c = %.2f\n",i,letra[j].variavel,letra[j].valor);
                    cont++;
                    break;
                }
            }
            i++;
        }else if((posfixa[i]=='+'||posfixa[i]=='-'||posfixa[i]=='*'||posfixa[i]=='/')&&posfixa[i]!='\0'){//Se achar um operador, desempilha dois valores e empilha o resultado
            float a=desempilhaf(p);
            float b=desempilhaf(p);
            printf("operador %c encontrado, desempilhando b = %.2f e a = %.2f\n",posfixa[i],b,a);
            switch(posfixa[i]){
                case '+':
                empilhaf(b+a,p);
                printf("iteracao %d Empilhando %.2f+%.2f, Topo = %.2f\n",i,
                    b,a,topof(p));
                cont++;
                break;
                case '-':
                empilhaf(b-a,p);
                printf("iteracao %d Empilhando %.2f-%.2f, Topo = %.2f\n",i,b-a,topof(p));
                cont++;
                break;
                case '*':
                empilhaf(b*a,p);
                printf("iteracao %d Empilhando %.2f*%.2f, Topo = %.2f\n",i,b,a,topof(p));
                cont++;
                break;
                case '/':
                empilhaf(b/a,p);
                printf("iteracao %d Empilhando %.2f/%.2f, Topo = %.2f\n",i,b,a,topof(p));
                cont++;
                break;
            }
            i++;
        }else{
            i++;
        }
    }
    printf("cont = %d\n",cont);//debug
    float resultado=desempilhaf(p);
    destroif(&p);
    return resultado;
}