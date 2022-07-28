#include "NoDuplo.h"

class ListaDupla
{
public:
  ListaDupla();
  ~ListaDupla();

  bool busca(int val);
  int get(int k);
  void set(int k, int val);
  
  void insereInicio(int val);
  void removeInicio();
  void removeK(int k);

  //Exercicios --------------------------------

  void insereFinal(int val); 
  void removeFinal();

  void imprime();
  void imprimeReverso();
  
  ListaDupla* concatena (ListaDupla* l2);
  ListaDupla* partir (int x);
  void removeOcorrencias(int val);

  //TVC's Anteriores
  void removeDepoisMaior();
  ListaDupla *criaListaMenorMaior();
  void removeEntreInter(int v1, int v2);
  NoDuplo *insereNoAntes(NoDuplo *p, int val);

  //TVC
  int* append(int n);

  
private:
  NoDuplo *primeiro;
  NoDuplo *ultimo;
  int n;
};