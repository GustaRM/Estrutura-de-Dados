#include <iostream>
#include "No.h"


class PilhaEncad
{
  public:
    PilhaEncad();
    ~PilhaEncad();

    int getTopo();
    void empilha(int val); //insere Nó no topo
    int desempilha();      //elimina Nó no topo
    bool vazia();

    //Exercícios
    void imprime();
    
    //TVC

  private:
    No* topo; //ponteiro para o nó do topo
    int n;
};