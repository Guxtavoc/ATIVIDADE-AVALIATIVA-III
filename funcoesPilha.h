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