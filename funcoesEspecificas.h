typedef struct{
    char variavel;
    float valor;
}variaveis;

void converterExpressao(char posfixa[],char expressao[]);
int prio(char op);
void recebeVariaveis();