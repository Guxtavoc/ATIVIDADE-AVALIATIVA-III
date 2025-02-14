/*
Projeto: Avaliação 3
Arquivo: funcoesPilha.h -> Funções específicas para a manipulação de pilhas de caracteres
Nome: Gustavo Curado e Daniel Barros
Data: 13/02/2025
*/
typedef char Itemp;
typedef struct pilha{
    int max;
    int topo;
    Itemp *item;
}*Pilha;
int vazio(Pilha P);
int cheio(Pilha P);
Pilha criarPilha(int n);
void empilha(Itemp x, Pilha p);
Itemp desempilha(Pilha p);
Itemp topo(Pilha p);
void destroi(Pilha *p);
int prio(char op);