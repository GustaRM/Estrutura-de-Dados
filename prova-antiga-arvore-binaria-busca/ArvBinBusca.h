#include "NoArv.h"

class ArvBinBusca
{
public:
    ArvBinBusca();
    ~ArvBinBusca();
    bool vazia(); // verifica se a árvore está vazia
    bool busca(int val);
    void insere(int val);
    void remove(int val);
    void imprime();
    float mediaCaminho(int ch);

    //Exercícios -------------------------------------------
    int maior(); //Basta pegar o ultimo da direita 
    int menor(); //Basta pegar o ultimo da esquerda
    void removeMaior();
    void removeMenor();
    int contaParesCaminho(int x);

    int noMaisEsquerda();
    int noMaisDireita();
    int noMaisDireitaVal(NoArv* p, int val);
    int noMaisEsquerdaVal(NoArv* p, int val);

    //TVC's Anteriores --------------------------------------
    int impressaoParcial(int a, int b);
    void removeMenor(int val);
    void removeFilhoEsquerdaK(int k, int val);

    //TVC --------------------------------------------------
    int sucessor(int x, int y, int val);


private:
    NoArv *raiz; // ponteiro para o No raiz da árvore
    bool auxBusca(NoArv *p, int val);
    NoArv* auxInsere(NoArv *p, int val);
    NoArv* auxRemove(NoArv *p, int val);
    NoArv* menorSubArvDireita(NoArv *p);
    NoArv* removeFolha(NoArv *p);
    NoArv* remove1Filho(NoArv *p);
    void imprimePorNivel(NoArv* p, int nivel);
    NoArv* libera(NoArv *p);

    //Exercícios (Aux) -------------------------------------------
    int auxMaior(NoArv *p);
    int auxMenor(NoArv *p);
    int auxContaParesCaminho(NoArv *p, int x);
    

    //TVC's Anteriores (Aux) -------------------------------------
    int auxImpressaoParcial(NoArv* p, int a, int b);

    //TVC (Aux) --------------------------------------
    int auxSucessor(NoArv *p, int val);
};