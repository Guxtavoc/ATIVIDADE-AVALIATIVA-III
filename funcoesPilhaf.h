typedef float Itemf;//Declaração 

typedef struct pilhaf{
    int max;//Numero maximo de itens na pilha
    int topo;//POSIÇÃO do item que está no topo
    Itemf *item;//Vetor ou lista de elementos contidos na pilha
}*Pilhaf;

int vaziof(Pilhaf P);
int cheiof(Pilhaf P);
Pilhaf criarPilhaf(int n);
void empilhaf(Itemf x, Pilhaf p);
Itemf desempilhaf(Pilhaf p);
Itemf topof(Pilhaf p);
void destroif(Pilhaf *p);
int prio(char op);