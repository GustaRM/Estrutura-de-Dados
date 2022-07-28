#include <iostream>
#include "MatrizEspecial.h"

using namespace std;

MatrizEspecial::MatrizEspecial(int ordem)
{
  if(ordem >= 3){
    vet = new int [ordem+(2*(ordem-1))];
  }else{
    cout << "Ordem inválida";
  }
}
MatrizEspecial::~MatrizEspecial()
{
  delete [] vet;
}


int MatrizEspecial::getInd(int i, int j)
{
  if(i>=0 && i<tam && j>=0 && j<tam){
    if(i+j==tam-1 || i+j==tam-2 || i+j==tam)
      return indice; //Quando estiver em uma das 3 diagonais
    else 
      return -2; //Quando for 0
  }else{
    return -1; //Inválido
  }
}


int MatrizEspecial::get(int i, int j)
{ 
  int k=getInd(i, j);

  if(k==-1){
    cout << "Erro!Indice inválido";
    exit(1);
  }else{
    if(k==-2){
      return 0.0;
    }else{
      return vet[k];
    }
  }
}


void MatrizEspecial::set (int i, int j, int val)
{
  int k=getInd(i, j);

  if(k==-1 && k==-2){
    cout << "Erro!Indice inválido para atribuição";
  }else{
    vet[k]=val;
  }
}