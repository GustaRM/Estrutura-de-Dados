#include <iostream>
#include "PilhaEncad.h"

using namespace std;

PilhaEncad::PilhaEncad()
{
  cout << "Criando PilhaEncad" << endl;
  topo = NULL;
  n=0;
}
PilhaEncad::~PilhaEncad()
{
  cout << "Destruindo PilhaEncad" << endl;
  No* p = topo;
  while(topo != NULL)
  {
    topo = p->getProx();
    delete p;
    p = topo;
  }
}

int PilhaEncad::getTopo()
{
  if(topo != NULL)
    return topo->getInfo();
  else
  {
    cout << "Pilha vazia!" << endl;
    exit(1);
  }
}
void PilhaEncad::empilha(int val)
{
  No* p = new No();
  p->setInfo(val);
  p->setProx(topo);
  topo = p;
  n++;
} 
int PilhaEncad::desempilha()
{
  No* p;
  if(topo != NULL)
  {
    p = topo;
    topo = p->getProx();
    int val = p->getInfo();
    n--;
    delete p;
    return val;
  }
  else
  {
    cout << "ERRO: Pilha vazia!" << endl;
    exit(1);
  }
}     
bool PilhaEncad::vazia()
{
  if(topo == NULL)
    return(true);
  else
    return(false);
}

//Exercícios
void PilhaEncad::imprime()
{ 
  No* p = topo;
  cout << endl;
  //imprime o valor de cada um dos nós
  while(p!=NULL)
  {
    cout << p->getInfo()<<" ";
    p = p->getProx();
  }

  cout<<endl;
}

