#include "NoArv.h"

class ArvBin
{
  public:
    ArvBin();
    ~ArvBin();
    int getRaiz();
    void cria(int x, ArvBin *sae, ArvBin *sad);
    void anulaRaiz();
    bool vazia(); // verifica se a árvore está vazia
    bool busca(int x);
    void preOrdem();
    void montaArvore();
    void insere(int x);

    //Exercícios ----------------------------------
    int contaNos();
    int contaNosFolhas();
    int contaImpar();
    int altura();
    int contaImpar(int k);
    void imprimeNivel(int k);
    float mediaNivel(int k);
    int min();
    int max();

    int inverte();
    int noMaisEsquerda();
    int noMaisDireita();

    //TVC's Anteriores --------------------------------------
    void contaElegante();
    void contaElegante1();
    void contagens(int val);

    //TVC ----------------------------------------------------
    int* criaVetDoisFilhos(int k, int *n);
    
    

  private:
    NoArv *raiz; // ponteiro para o No raiz da árvore
    NoArv* libera(NoArv *p);

    //Auxiliares
    bool auxBusca(NoArv *p, int x);
    void auxPreOrdem(NoArv *p);
    NoArv* auxMontaArvore();
    NoArv* auxInsere(NoArv *p, int x);

    //Exercicios (Op. Auxiliares)-----------------------------
    int auxContaNos(NoArv *p);
    int auxContaNosFolhas(NoArv *p);
    int auxAltura(NoArv *p);
    int auxContaImpar(NoArv *p);
    void auxImpNivel(NoArv *p, int k, int atual);
    void auxMediaNivel(NoArv *p, int k, int *soma, int *cont);
    void auxMin(NoArv *p, int *auxMin);
    void auxMax(NoArv *p, int *auxMax);

    void auxInverte(NoArv * p);

    //TVC's Anteriores (Auxiliares) -------------------------------
    void auxContaElegante(NoArv *p, int *contPares, int *contFpos);
    void auxContaElegante1(NoArv *p, int *cont2Filhos, int *contMult5);
    void auxContagens(NoArv *p, int val, int *contFolha1Filho, int *contMultVal);
    

    //TVC (Auxiliar)-------------------------------------
    int *auxCriaVetDoisFilhos(NoArv *p, int k, int atual, int pos, int n[]);

  
};
