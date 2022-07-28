#include <iostream>
#include <cstdlib>
#include "ListaEncad.h"

using namespace std;

ListaEncad::ListaEncad()
{
  cout << "Criando objeto ListaEncad" << endl;
  primeiro = NULL;
  ultimo = NULL;
  n = 0;
}

ListaEncad::~ListaEncad()
{
  cout << "Destruindo objeto ListaEncad" << endl;
  No *p = primeiro;

  while(p != NULL)
  {
    No *t = p->getProx();
    delete p;
    p = t;
  }
}

bool ListaEncad::busca(int val)
{
  No *p;

  for(p = primeiro; p != NULL; p = p->getProx())
    if(p->getInfo() == val)
      return true;

  return false;
}

int ListaEncad::get(int k)
{
  No *p = primeiro;
  int i = 0;
  while(i < k && p != NULL)
  {
    i++;
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

void ListaEncad::set(int k, int val)
{
  No *p = primeiro;
  int i = 0;

  while(i < k && p != NULL)
  {
    i++;
    p = p->getProx();
  }

  if(p == NULL)
    cout << "ERRO: Indice invalido!" << endl;
  else
    p->setInfo(val);
}


void ListaEncad::insereInicio(int val)
{
  No* p = new No();
  p->setInfo(val);
  p->setProx(primeiro);

  primeiro = p;

  n++;
  if(n == 1) 
    ultimo = p;
}

void ListaEncad::insereFinal(int val)
{
  No* p = new No();
  p->setInfo(val);
  p->setProx(NULL);

  if(ultimo != NULL) 
    ultimo->setProx(p);
  ultimo = p;

  n++;
  if(n == 1) 
    primeiro = p;
}

void ListaEncad::removeInicio()
{
  No* p;
  if(primeiro != NULL)
  {
    p = primeiro;
    primeiro = p->getProx();
    delete p;

    n--;
    if(n == 0) 
      ultimo = NULL;
  }
  else
    cout << "ERRO: lista vazia!" << endl;
}

void ListaEncad::removeFinal()
{
  No* p;
  if(ultimo != NULL)
  {
    if(primeiro == ultimo)
    {
      primeiro = NULL;
      p = NULL;
    }
    else
    {
      p = primeiro;

      while(p->getProx() != ultimo)
        p = p->getProx();

      p->setProx(NULL);
    }
    delete ultimo;
    ultimo = p;
    n--;
  }
  else
    cout << "ERRO: lista vazia!" << endl;
}

void ListaEncad::imprimir()
//exercicio 1, slide 41
{
  No* p = primeiro;
  while (p != NULL)
  {
    cout << p->getInfo() << "  ";
    p = p->getProx();
  }
  cout << endl << endl;
}


//Questões TVC's Antigos -------------------------------------------------

//6.1
void ListaEncad::imprimeElemsEmOrdem()
{
  No* p = primeiro;
  No* ant = NULL;

  cout << "Valores:[ ";
  while (p != NULL)
  {
    if((ant == NULL && p->getProx() == NULL) || // 1° elemento e único
    (ant == NULL && p->getInfo() <= p->getProx()->getInfo()) || //1° elemento
    (ant != NULL && p->getProx() == NULL && p->getInfo() >= ant->getInfo()) || //ultimo elemento
    (ant != NULL && p->getProx() != NULL && p->getInfo() >= ant->getInfo() && p->getInfo() <= p->getProx()->getInfo())) //caso geral para os elementos do 'meio'
      cout << p->getInfo() << "  ";
        
    ant = p;
    p = p->getProx();
  }

  cout <<']'<< endl << endl;
}


//6.5
int* ListaEncad::menorProximo()
{
  if (primeiro != NULL)
  {
    int* vet = new int[n];
    No* p = primeiro;

    for (int i = 0; i < n - 1; i++)
    {
      if (p->getInfo() < p->getProx()->getInfo())
        vet[i] = 1;
      else
        vet[i] = 0;
      p = p->getProx();

    }
    vet[n - 1] = 1;
    return vet;
  }
  else
    return NULL;
}


//6.6
bool ListaEncad::inserePosicaoVal(int k, int val)
{
  int valK = get(k);

	if (valK >= n || valK < 0)
		return false;

	if (valK == 0)
		insereInicio(val);
	else
	{
		No* ant = NULL, * p = primeiro;
		for (int i = 0; i < valK; i++)
		{
			ant = p;
			p = p->getProx();
		}

		No* novo = new No();
		novo->setInfo(val);
		novo->setProx(p);
		ant->setProx(novo);
		n++;
	}
	return true;
}

//Questões TVC 03/01/2022  --------------------

void ListaEncad::setn(int novo_n)
{
  if(novo_n >= 0 && novo_n <=n)  //Verifica se é válido
  {
    while(novo_n < n)            //Deleta os elementos inciais até n=novo_n
    {
      removeInicio();            
    }
  
  cout << "Imprimindo os " << novo_n << " ultimos elementos: ";
  imprimir();
  }else 
    cout<< "Valor inválido" << endl;
}