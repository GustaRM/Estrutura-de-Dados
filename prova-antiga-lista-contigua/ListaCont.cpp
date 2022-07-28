#include <iostream>
#include <cstdlib>
//#include "Ponto.h"
#include "ListaCont.h"

using namespace std;

ListaCont::ListaCont(int tam)
{
  cout << "Criando objeto ListaCont" << endl;
  max = tam;
  n = 0;
  vet = new int[max];
}

ListaCont::~ListaCont()
{
  cout << "Destruindo objeto ListaCont" << endl;
  delete [] vet;
}

int ListaCont::get(int k)
{
  if(k >= 0 && k < n)
    return vet[k];
  else
  {
    cout << "ERRO: Indice invalido!" << endl;
    exit(1);
  }
}

void ListaCont::set(int k, int val)
{
  if(k >= 0 && k < n)
     vet[k] = val;
  else
  {
  cout << "ERRO: Indice invalido!" << endl;
  exit(1);
  }
}

void ListaCont::insereFinal(int val)
{
  if(n == max)
  {
    cout << "ERRO: Vetor Cheio!" << endl;
    exit(1);
  }
  vet[n] = val;
  n = n + 1;
}

void ListaCont::removeFinal()
{
  if(n == 0)
  {
    cout << "ERRO: Lista Vazia!" << endl;
     exit(1);
  }
  n = n - 1;
}

void ListaCont::insereK(int k, int val)
{
  if(n == max)
  {
    cout << "ERRO: Vetor Cheio!" << endl;
    exit(1);
  }
  if(k >= 0 && k < n)
  {
    for(int i = n-1; i >= k; i--)
      vet[i+1] = vet[i];

    vet[k] = val;
    n = n + 1;
  }
  else
  {
    cout << "ERRO: Indice invalido!" << endl;
    exit(1);
  }
}

void ListaCont::removeK(int k)
{
  if(k >= 0 && k < n)
  {
    for(int i = k; i < n-1; i++)
      vet[i] = vet[i+1];
      
    n = n - 1;
  }
  else
  {
    cout << "ERRO: Indice invalido!" << endl;
    exit(1);
   }
}

void ListaCont::insereInicio(int val)
{
  if(n == 0)
  {   //lista vazia. Sera o unico no da lista
    vet[n] = val;
    n = n + 1;
  }
  else
    insereK(0, val);
}

void ListaCont::removeInicio()
{
  removeK(0);
}

void ListaCont::realoca(int newMax) {
  if (newMax >= n) {
  // Aloca novo vetor com novo tamanho

  int *newVet = new int [newMax];
  // Copia todos os elementos do vetor atual para o novo
  
  for (int i = 0; i < n; i++)
    newVet[i] = vet[i];

  // Deleta o antigo vetor
  delete [] vet;

  // Atualiza o vetor e o máximo da classe com os novos valores
  vet = newVet;
  max = newMax;
  } else {
    cout << "ERRO: Novo tamanho invalido!" << endl;
    exit(1);
  }
}

//Questões Lab de Prog --------------------------------
//1
void ListaCont::imprime()
{
  if(n==0)
    cout << "ERRO! Lista vazia!";
  else{
    for(int i=0; i<n; i++)
    {
      cout << vet[i] << " ";
    }
    cout << endl;
  }
}

int ListaCont::numNos()
{
  return n;
}

int ListaCont::buscaMaior(int val)
{
  for(int i=0; i<n ; i++)
  {
    if(vet[i]>val)
    {
      return i;
    }
  }

  return -1;
}

void ListaCont::limpar()
{
  while(n>=0){
    removeInicio();
  }
  cout << "A lista foi esvaziada" << endl;
}


//Questões TVC's Antigos ----------------------------


//5.1
ListaCont* ListaCont::copiar(int valor)
{
  ListaCont *nvet= new ListaCont (max);

  if(n==0){
    cout << "ERRO! Lista vazia.";
  }else
    for(int i=0; i<n ; i++)
    {
      if(vet[i]==valor)
      {
        for(int j=0; j<n ; j++)
        {
          nvet->insereFinal(vet[i]);
          removeK(i);
        }
        break;
      }
    }
  return nvet;
}


//5.3
void ListaCont::inserirVet(int tam, int v[])
{
  if(n+tam >= max){
    realoca(tam+max);
  }else{
    for(int i=tam-1; i>=0; i--)
    {
      insereInicio(v[i]);
    }
  }
}


//5.6
void ListaCont::intercala(ListaCont *la, ListaCont *lb)
{
  // Limpando a lista interna.
  limpar ();

  // Ajusta tamanho da lista interna para caber todos os elementos (apenas se for preciso).
  int tamFinal = la->n + lb->n;
  
  if (max < tamFinal)
    realoca (tamFinal);

  // Faz a intercalação das duas listas.
  while (la->n > 0 && lb->n > 0) {
    insereFinal (la->vet[0]);
    insereFinal (lb->vet[0]);
    la->removeInicio ();
    lb->removeInicio ();
  }

  // Caso as listas tenham tamanhos diferentes, copia os elementos restantes da maior lista.
  while (la->n > 0) {
    insereFinal (la->get(0));
    la->removeInicio ();
  }
  while (lb->n > 0) {
    insereFinal (lb->get(0));
    lb->removeInicio ();
  }
  
}

//Questões TVC 03/01/2022  --------------------

ListaCont* ListaCont::removeVal(int val)
{
  int max2=max;
  int n2=0;
  ListaCont *novo= new ListaCont (max2);
  ListaCont *aux= new ListaCont (max2);
  
  for(int i=0; i<=n; i++)
  {
    aux[i]=vet[i];
  }

  for(int i=0; i<=n; i++)
  {
    if(vet[i]==val)
    {
      novo->insereFinal(vet[i]);
      n2++;
      removeK(i);
    }
  }

  if(n!=max && n2!=max)
  {
    max=n;
    max2=n2;
  }

  if(n2==0)
  {
    return NULL;
  }else
    return novo;
}