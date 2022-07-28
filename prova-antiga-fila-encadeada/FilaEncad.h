#include <iostream>
#include "No.h"

class FilaEncad
{
  public:
    FilaEncad();
    ~FilaEncad();

    int getInicio();
    void enfileira(int val); //insere Nó no fim
    int desenfileira();  //remove Nó do inicio
    bool vazia();

    //Exercícios
    void imprime();
    void inverteFila(FilaEncad *f);
    FilaEncad* concatena(FilaEncad *f1, FilaEncad *f2);
    bool pertence(int val);

    //TVC

  private:
    No* inicio;
    No* fim;
};