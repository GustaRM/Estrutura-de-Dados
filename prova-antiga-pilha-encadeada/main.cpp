#include <iostream>
#include "PilhaEncad.h"

using namespace std;

int* inverte (int vet[], int n)
{
  int *novoVet =  new int[n];
  PilhaEncad p;

  for(int i=0; i<n; i++)
  {
    p.empilha(vet[i]);
  }


  //desempilha os elementos de P me os coloca em novoVet
  int i = 0;
  while(!p.vazia())
  {
    novoVet[i] = p.desempilha();
    i++;
  }

  return novoVet;
}

void removeDaPilha(PilhaEncad *p, int x)
{
  //remove a primeira ocorrencia do valor X da pilha p
  PilhaEncad *paux;

  while(!p->vazia())
  {
    int val = p->desempilha();

    if(val == x)
      break;
    else 
      paux->empilha(val);
  }

  while(!paux->vazia())
  {
    p->empilha(paux->desempilha());

  }
}

int main() {
  /// TESTE COM PILHA
  PilhaEncad p;

  for(int i = 0; i < 5; i++) p.empilha(i);
  cout << "Pilha apos inserir 5 valores" << endl;
  p.imprime();

  for(int i = 20; i < 25; i++) p.empilha(i);
  cout << "Pilha apos inserir mais 5 valores" << endl;
  p.imprime();

  p.desempilha();
  cout << "Pilha apos remover um valor" << endl;
  p.imprime();

  int v[]={2,3,4,5,6,7}; 
  int *iv=inverte(v, 6);

  cout<<endl;
  cout << "Inverte vetor" << endl;
  for(int i=0; i<6; i++)
  {
    cout <<iv[i]<<' ';
  }
  cout<<endl;
} 