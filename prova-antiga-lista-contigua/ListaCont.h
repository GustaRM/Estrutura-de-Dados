//#include "Ponto.h"

class ListaCont
{
  private:
    int max;
    int n;
    int *vet;

  public:
    ListaCont(int tam);
    ~ListaCont();

    int get(int k);
    void set(int k, int val);
    
    void insereFinal(int val);
    void insereK(int k, int val);
    void insereInicio(int val);

    void removeFinal();
    void removeK(int k);
    void removeInicio();
    
    void realoca(int newMax);
    
    //Quesões slide Lab de Prog ----------------
    void imprime();
    int numNos();
    int buscaMaior(int val);
    void limpar();

    //Questões TVC's Antigos -------------------
    ListaCont* copiar(int valor);                 //5.1
    void inserirVet(int tam, int v[]);            //5.3
    void intercala(ListaCont *la, ListaCont *lb); //5.6

  //Questões TVC 03/01/2022 --------------------

  ListaCont* removeVal(int val);

  
};


