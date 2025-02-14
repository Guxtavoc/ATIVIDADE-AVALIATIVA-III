/*
Projeto: Avaliação 3
Arquivo: funcoesEspecificas.h -> Funções específicas para a manipulação de expressões matemáticas
Nome: Gustavo Curado e Daniel Barros
Data: 13/02/2025
*/
typedef struct{
    char variavel;
    float valor;
    int qnt;
}variaveis;
void converterExpressao(char posfixa[],char expressao[]);
int prio(char op);
variaveis* recebeVariaveis();
float avaliaExpressao(char posfixa[], variaveis *letra, int qtdVariaveis);
