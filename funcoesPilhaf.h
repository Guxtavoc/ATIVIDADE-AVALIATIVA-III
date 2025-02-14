/*
Projeto: Avaliação 3
Arquivo: funcoesPilhaf.h -> Funções específicas para a manipulação de pilhas de floats
Nome: Gustavo Curado e Daniel Barros
Data: 13/02/2025
*/
typedef float Itemf;
typedef struct pilhaf{
    int max;
    int topo;
    Itemf *item;
}*Pilhaf;
int vaziof(Pilhaf P);
int cheiof(Pilhaf P);
Pilhaf criarPilhaf(int n);
void empilhaf(Itemf x, Pilhaf p);
Itemf desempilhaf(Pilhaf p);
Itemf topof(Pilhaf p);
void destroif(Pilhaf *p);
int prio(char op);