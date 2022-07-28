#include <iostream>
#include "MatrizEspecial1.h"

using namespace std;

MatrizEspecial1::MatrizEspecial1(int nn)
{
  cout << "Criando um objeto MatrizLin" << endl;
  if(nn <= 3)
  {
     cout << "Dimensões inválidas" << endl;
     exit(1);
 }
  n = nn;
  vet = new float[(n * 3)-4];
}

MatrizEspecial1::~MatrizEspecial1()
{
  cout << "Destruindo um objeto " << endl;
  delete [] vet;
}

int MatrizEspecial1::detInd(int i, int j)
{
  if(i >= 0 && i < n && j >= 0 && j < n)
  {
    int k;
    if ( (i==j ) ||  ( i+j == (n-1))) 
      k=i;
    else
      if(j==0)
        k=n+(i-1);
      else
        if(  j == (n-1))
          k = (n-1) + (n-2) + i;
        else
          return -2;
    return k;
  }
  else
    return -1;
}

float MatrizEspecial1::get(int i, int j)
{
  int k = detInd(i, j);
  if(k != -1)
  {
    if(i == j)
      return vet[k];
    if(j+i == (n-1))
      return -vet[k] ;
    if( k == -2)
      return 0;
    return vet[k];

  }else
    {
      cout << "ERRO: Indice invalido!" << endl;
      exit(1);
  }
}

void MatrizEspecial1::set(int i, int j, float val)
{
  int k = detInd(i, j);
    if(k != -1)
      vet[k] = val;
    else
      cout << "ERRO: Indice invalido!" << endl;
}