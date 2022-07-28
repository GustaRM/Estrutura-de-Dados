#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaDupla.h"

using namespace std;

int numAleatorio(int a, int b)
{
  return a + rand()%(b - a + 1); /// retorna um numero inteiro aleatório entre a e b
}

int main()
{
  ListaDupla l; /// cria lista vazia
  int NumNos = 10;

  srand(time(NULL));

  l.insereFinal(3);
  l.insereFinal(2);
  l.insereFinal(5);
  l.insereFinal(12);
  l.insereFinal(7);
  l.insereFinal(9);

  l.imprime();

  l.removeEntreInter(2, 8);
  l.imprime();

  //l.removeDepoisMaior();
  
  /*
  ListaDupla *lista;
  lista=l.criaListaMenorMaior();
  lista->imprime();
  l.imprime();
  */


  /* 
  //Insere valores aleatórios a cada exercução
  cout << "Inserindo valores: ";
  for(int i = 1; i <= NumNos; i++)
  {
    int val =  numAleatorio(0, 50); /// cria um valor aleat—rio entre 0 e 50
    cout << val << ", ";
    l.insereFinal(val);
  }
  */


  return 0;
}