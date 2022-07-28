#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla()
{
  cout << "Criando uma ListaDupla Vazia" << endl;
  primeiro = NULL;
  ultimo = NULL;
  n = 0;
}

ListaDupla::~ListaDupla()
{
  cout << "Destruindo ListaDupla" << endl;
  NoDuplo *p = primeiro;
  while(p != NULL)
  {
    NoDuplo *t = p->getProx();
    delete p;
    p = t;
  }
}

bool ListaDupla::busca(int val)
{
  NoDuplo *p;
  for(p = primeiro; p != NULL; p = p->getProx())
    if(p->getInfo() == val)
      return true;
  return false;
}

int ListaDupla::get(int k)
{
  NoDuplo *p = primeiro;
  for(int i = 0; i < k; i++)
  {
    if(p == NULL)
      break;
    p = p->getProx();
  }
  if(p == NULL)
  {
    cout << "ERRO: Indice invalido!" << endl;
    exit(1);
  }
  else
    return p->getInfo();
}

void ListaDupla::set(int k, int val)
{
  NoDuplo *p = primeiro;
  for(int i = 0; i < k; i++)
  {
    if(p == NULL)
      break;
    p = p->getProx();
  }
  
  if(p == NULL)
    cout << "ERRO: Indice invalido!" << endl;
  else
  p->setInfo(val);
}

void ListaDupla::insereInicio(int val)
{
	NoDuplo *p = new NoDuplo();
  
	p->setInfo(val);
	p->setProx(primeiro);
	p->setAnt(NULL);

	if(n == 0) 
    ultimo = p;
	else 
    primeiro->setAnt(p);

	primeiro = p;
	n = n + 1;
}

void ListaDupla::removeInicio()
{
	NoDuplo *p;
	if(primeiro != NULL)
	{
		p = primeiro;
		primeiro = p->getProx();
		delete p;
		n = n - 1;

		if(n == 0) 	
      ultimo = NULL;
		else 
      primeiro->setAnt(NULL);
	}
	else
    cout << "ERRO: lista vazia" << endl;
}

void ListaDupla::removeK(int k)
{
  if (k < 0 || k >= n)
    cout << "Indice invalido" << endl;
  else if (k == 0)
    removeInicio();
  else if (k == n - 1)
    removeFinal();
  else
  {
    NoDuplo* p = primeiro;
    for (int i = 0; i < k; i++)
       p = p->getProx();
    NoDuplo* ant = p->getAnt();
    NoDuplo* prox = p->getProx();
    ant->setProx(prox);
    prox->setAnt(ant);
    delete p;
    n--;
  }
}

//Exercicios -----------------------------------

void ListaDupla::insereFinal(int val)
{
  NoDuplo* p = new NoDuplo();

  p->setInfo(val);
  p->setProx(NULL);
  p->setAnt(ultimo);

  if(n==0) 
    primeiro = p;
  else 
    ultimo->setProx(p);

  ultimo = p;
  n++;
} 
void ListaDupla::removeFinal()
{
  NoDuplo* p;

  if(ultimo!=NULL)
  {
    p=ultimo;
    ultimo= p->getAnt();
    delete p;
    n--;

    if(n == 0) 	primeiro = NULL;
		else ultimo->setProx(NULL);

  }else
    cout << "ERRO: lista vazia" << endl;

}

void ListaDupla::imprime()
{ 
  cout << "Imprimindo a lista do início: " << endl;
  NoDuplo* p = primeiro;

  if(ultimo!=NULL)
  {
    while(p != NULL)
    {
      cout << p->getInfo() << " ";
      p = p->getProx();
    }

    cout << endl;

  }else
    cout << "ERRO: lista vazia" << endl;
}

void ListaDupla::imprimeReverso()
{
  cout << "Imprimindo a lista do final: " << endl;
  NoDuplo* p = ultimo;

  if(ultimo!=NULL)
  {
    while(p != NULL)
    {
      cout << p->getInfo() << " ";
      p = p->getAnt();
    }

    cout << endl;

  }else
    cout << "ERRO: lista vazia" << endl;
}

ListaDupla* ListaDupla::concatena (ListaDupla* l2)
{ 
  ListaDupla* listaNova =  new ListaDupla();
  NoDuplo* p = primeiro;

  //insere elementos da primeira lista
  while (p!=NULL)
  {
    listaNova->insereFinal(p->getInfo());
    p = p->getProx();
  }

  //insere elementos da segunda lista

  p = l2->primeiro;
  while(p!=NULL)
  {
    listaNova->insereFinal(p->getInfo());
    p->getProx();
  }
  
  return listaNova;
}


ListaDupla* ListaDupla::partir (int x)
{
  ListaDupla* listaNova = new ListaDupla();
  NoDuplo* p = ultimo;

  while((p!=NULL) && (p->getInfo()!=x))
  {
      listaNova->insereInicio(p->getInfo());
      p = p->getAnt();
      this->removeFinal();
  }
  return listaNova;
}

void ListaDupla::removeOcorrencias(int val)
{
  NoDuplo *p = primeiro;
  while(p!=NULL)
  {
    if(p->getInfo() == val){
      //se for o primeiro nó
      if(p->getAnt() == NULL)
        this->removeInicio();

      //se for o ultimo nó
      else if(p->getProx() == NULL)
        this->removeFinal();

      //se for intermediario
      else{
        NoDuplo *aux = p->getAnt();
        aux->setProx(p->getProx());

        aux = p->getProx();
        aux->setAnt(p->getAnt());

        n = n-1;
        delete p;
      }
    }
    p = p->getProx();
  }
}

//TVC's Anteriores

void ListaDupla::removeDepoisMaior()
{
  NoDuplo *p = primeiro;

  //Caso o maior for o ultimo
  if(p->getProx() == NULL)
  {
    cout << "Não foi possível remover o nó";
  }else{
    NoDuplo *maior = p;
    p = p->getProx();

    //encontra o maior
    while(p != NULL)
    {
      if(maior->getInfo() < p->getInfo())
      {
        maior = p;
      }

      p = p->getProx();
    }
    maior = maior->getProx();
    
    //remove o número depois do maior

    //faz o anterior do numero removido apontar para o proximo do removido
    NoDuplo *aux = maior->getAnt();
    aux->setProx(maior->getProx());

    //faz o proximo do removido apontar para o anterior do removido
    aux = maior->getProx();
    aux->setAnt(maior->getAnt());

    n = n-1;
  }
}

ListaDupla* ListaDupla::criaListaMenorMaior()
{
  ListaDupla* listaNova = new ListaDupla();
  NoDuplo *p = primeiro;

  if(p != NULL)
  {
    int maior = p->getInfo();
    int menor = p->getInfo();
    p = p->getProx();

    //encontra o maior e o menor
    while(p != NULL)
    {
      if(maior < p->getInfo())
      {
        maior = p->getInfo();
      }

      if(menor > p->getInfo())
      {
        menor = p->getInfo();
      }

      p = p->getProx();
    }
    listaNova->insereFinal(menor);
    listaNova->insereFinal(maior);

    removeOcorrencias(menor);
    removeOcorrencias(maior);

  }else{
    cout << "Erro! Lista vazia!";
  }
  return listaNova;
}

void ListaDupla::removeEntreInter(int v1, int v2)
{
  NoDuplo *p = primeiro;

  if(p != NULL)
  {
    while(p != NULL)
    {
      NoDuplo *prox = p->getProx();
      if(p->getInfo() >= v1 && p->getInfo() <= v2)
      {
        if(p == primeiro)
        {
          removeInicio();
        }else if(p == ultimo)
        {
          removeFinal();
        }else
        {
          removeOcorrencias(p->getInfo());
        }
        
      }

      p = prox;
    }
  }else{
    cout << "Lista vazia!";
  }
}

/*
NoDuplo* ListaDupla::insereNoAntes(NoDuplo *p, int val)
{
  NoDuplo *aux = primeiro;
  if(aux != NULL)
  {
    while(aux != p)
    {

    }
    
  }
}
*/

//TVC

int* ListaDupla::append(int n)
{
  
  NoDuplo *p = primeiro;

  if(p != NULL && n >= 0) //se n for maior ou igual a 0
  {
    for(int i=0; i<n; i++)
    {
      insereFinal(p->getInfo());
      p = p->getProx();
    }

    return NULL;
  }else if (p != NULL && n < 0) //se n for negativo
  {
    n = n * (-1);
    int *vet = new int [n];

    for(int i = 0; i < n; i++){
      vet[i] = p->getInfo();
      p = p->getProx();
      removeInicio();
    }

    return vet;

  }else{
    cout << "Lista vazia!";
    exit(1);
  }

}