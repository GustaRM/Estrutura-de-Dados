#include <iostream>
//#include "Ponto.h"
#include "ListaCont.h"

using namespace std;

int main()
{
  ListaCont l(10);
  

  l.insereFinal(24);
  l.insereFinal(3);
  l.insereFinal(2);
  l.insereFinal(-1);
  l.insereFinal(99);
  //l.imprime();

  
  /*//Teste primeira implementação
  ListaCont* vet1 = l.copiar(2);
  l.imprime();
  vet1->imprime();

  
  //Teste segunda implementação
  int v[]={-5, 6, 7};
  l.inserirVet(3, v);
  l.imprime();

  //Teste terceira implementação
  ListaCont a(5), b(3), c(2);

  for (int i = 6; i < 11; i++)
    a.insereFinal(i);

  for (int i = 0; i < 3; i++)
    b.insereFinal(i);

  c.insereFinal(3);
  c.insereFinal(4);

  c.intercala(&a, &b);
  c.imprime();
  */
 
 cout<< endl <<"--------"<< endl;

 ListaCont* aux = l.removeVal(3);
 l.imprime();
 aux->imprime();
  
  return 0;
}