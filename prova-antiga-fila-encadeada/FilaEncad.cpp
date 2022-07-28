#include <iostream>
#include "FilaEncad.h"

using namespace std;

FilaEncad::FilaEncad()
{
  cout << "Criando FilaEncad" << endl;
  inicio = NULL;
  fim = NULL;
}

FilaEncad::~FilaEncad()
{
  cout << "Destruindo FilaEncad" << endl;
  No* p = inicio;
  while(inicio != NULL)
  {
    inicio = p->getProx();
    delete p;
    p = inicio;
  }
  fim = NULL;
}

int FilaEncad::getInicio()
{
  if(inicio != NULL)
    return inicio->getInfo();
  else
  {
    cout << "Fila vazia!" << endl;
    exit(1);
  }
}

void FilaEncad::enfileira(int val)
{
  No* p = new No();
  p->setInfo(val);
  p->setProx(NULL);
  if(fim == NULL)
    inicio = p;
  else
    fim->setProx(p);
  fim = p;
} 

int FilaEncad::desenfileira()
{
  No* p;
  if(inicio != NULL)
  {
    p = inicio;
    inicio = p->getProx();
    if(inicio == NULL)
      fim = NULL;
    int val = p->getInfo();
    delete p;
    return val;
  }
  else
  {
    cout << "ERRO: Fila Vazia!" << endl;
    exit(1);
  }
}  

bool FilaEncad::vazia()
{
  if(inicio == NULL)
    return true;
  else
    return false;
}

//Exercícios
void FilaEncad::imprime()
{
  No* p = inicio;
  cout << endl;
  //imprime o valor de cada um dos nós
  while(p!=NULL)
  {
    cout << p->getInfo()<<" ";
    p = p->getProx();
  }

  cout<<endl;
}

/*
void FilaEncad::inverteFila (FilaEncad *f)
{
  PilhaEncad *p;
  while(!f->vazia())
  {
    p.empilha(f->desenfileira());
  }
}
*/

FilaEncad* FilaEncad::concatena (FilaEncad *f1, FilaEncad *f2)
{
  FilaEncad *novaFila = new FilaEncad();

  while(!f1->vazia())
  {
    novaFila->enfileira(f1->desenfileira());
  }

  while(!f2->vazia())
  {
    int val = f2->desenfileira();
    if(!novaFila->pertence(val))
      novaFila->enfileira(val);
  }

  return novaFila;
}

bool FilaEncad::pertence(int val)
{
  No *p = inicio;

  while(p != NULL)
  {
    if(p->getInfo() == val)
      return true;
    p->getProx();
  }

  return false;
}


