typedef char Itemp;//Declaração 

typedef struct pilha{
    int max;//Numero maximo de itens na pilha
    int topo;//POSIÇÃO do item que está no topo
    Itemp *item;//Vetor ou lista de elementos contidos na pilha
}*Pilha;

int vazio(Pilha P);
int cheio(Pilha P);
Pilha criarPilha(int n);
void empilha(Itemp x, Pilha p);
Itemp desempilha(Pilha p);
Itemp topo(Pilha p);
void destroi(Pilha *p);
int prio(char op);