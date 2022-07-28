#include <iostream>
#include "FilaEncad.h"

using namespace std;

FilaEncad* reorganiza(FilaEncad* f)
{
  FilaEncad *nova = new FilaEncad();
  int a = f->getInicio();

  if(f->getInicio() >= 70)
  {
    int aux = f->desenfileira();

    if(aux >= f->getInicio())
      nova->enfileira(aux);
    else 
      f->enfileira(aux);
  }else
    f->enfileira(f->desenfileira());

  while(f->getInicio() != a)
  {
    if(f->getInicio() >= 70)
    {
      int aux = f->desenfileira();

      if(aux >= f->getInicio())
        nova->enfileira(aux);
      else
        f->enfileira(aux);
      
    }
    else
      f->enfileira(f->desenfileira());
  }

  return nova;
}

int main() {
  FilaEncad f;
  
  f.enfileira(15);
  f.enfileira(85);
  f.enfileira(71);
  f.enfileira(75);
  f.enfileira(62);
  f.enfileira(70);
  f.enfileira(30);
  f.enfileira(92);
  f.enfileira(99);
  f.enfileira(54);

  f.imprime();

  FilaEncad *nova = reorganiza(&f);

  f.imprime();
  nova->imprime();


} 

