typedef struct{
    char variavel;
    float valor;
    int qnt;
}variaveis;
void converterExpressao(char posfixa[],char expressao[]);
int prio(char op);
variaveis* recebeVariaveis();
float avaliaExpressao(char posfixa[], variaveis *letra, int qtdVariaveis);