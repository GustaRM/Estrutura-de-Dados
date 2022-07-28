#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

ArvBinBusca::ArvBinBusca()
{
  raiz = NULL;
}

bool ArvBinBusca::vazia()
{
  return raiz == NULL;
}

void ArvBinBusca::insere(int val)
{
  raiz = auxInsere(raiz, val);
}

NoArv* ArvBinBusca::auxInsere(NoArv *p, int val)
{
  if(p == NULL)
  {
    p = new NoArv();
    p->setInfo(val);
    p->setEsq(NULL);
    p->setDir(NULL);
  }
  else if(val < p->getInfo())
    p->setEsq(auxInsere(p->getEsq(), val));
  else
    p->setDir(auxInsere(p->getDir(), val));
  return p;
}

bool ArvBinBusca::busca(int val)
{
  return auxBusca(raiz, val);
}

bool ArvBinBusca::auxBusca(NoArv *p, int val)
{
  if(p == NULL)
    return false;
  else if(p->getInfo() == val)
    return true;
  else if(val < p->getInfo())
    return auxBusca(p->getEsq(), val);
  else
    return auxBusca(p->getDir(), val);
}

void ArvBinBusca::remove(int val)
{
  raiz = auxRemove(raiz, val);
}

NoArv* ArvBinBusca::auxRemove(NoArv *p, int val)
{
  if(p == NULL)
    return NULL;
  else if(val < p->getInfo())
    p->setEsq(auxRemove(p->getEsq(), val));
  else if(val > p->getInfo())
    p->setDir(auxRemove(p->getDir(), val));
  else
  {
    if(p->getEsq() == NULL && p->getDir() == NULL)
      p = removeFolha(p);
      else if((p->getEsq() == NULL) || (p->getDir() == NULL))
        p = remove1Filho(p);
      else
      {
        NoArv *aux = menorSubArvDireita(p);
        int tmp = aux->getInfo();
        p->setInfo(tmp);
        aux->setInfo(val);
        p->setDir(auxRemove(p->getDir(), val));
      }
  }
  return p;
}

NoArv* ArvBinBusca::removeFolha(NoArv *p)
{
  delete p;
  return NULL;
}

NoArv* ArvBinBusca::remove1Filho(NoArv *p)
{
  NoArv *aux;
  if(p->getEsq() == NULL)
    aux = p->getDir();
  else
     aux = p->getEsq();
  delete p;
  return aux;
}

NoArv* ArvBinBusca::menorSubArvDireita(NoArv *p)
{
  NoArv *aux = p->getDir();
  while(aux->getEsq() != NULL)
    aux = aux->getEsq();
  return aux;
}

void ArvBinBusca::imprime()
{
  imprimePorNivel(raiz, 0);
}

void ArvBinBusca::imprimePorNivel(NoArv *p, int nivel)
{
  if(p != NULL)
  {
    cout << "(" << nivel << ")";
    for(int i = 1; i <= nivel; i++)
      cout << "--";
    cout << p->getInfo() << endl;
    imprimePorNivel(p->getEsq(), nivel+1);
    imprimePorNivel(p->getDir(), nivel+1);
    }
}

ArvBinBusca::~ArvBinBusca()
{
  raiz = libera(raiz);
}

NoArv* ArvBinBusca::libera(NoArv *p)
{
  if(p != NULL)
  {
    p->setEsq(libera(p->getEsq()));
    p->setDir(libera(p->getDir()));
    delete p;
    p = NULL;
  }
  return p;
}

float ArvBinBusca::mediaCaminho(int ch)
{
  int soma = 0, cont = 0;
  NoArv *p = raiz;
  while(p != NULL)
  {
    cont++;
    soma += p->getInfo();
    if(ch == p->getInfo())
      break;
    else if(ch > p->getInfo())
      p = p->getDir();
    else
      p = p->getEsq();
  }
  return (float)soma/cont;
}

//Exercícios -------------------------------------------
int ArvBinBusca::maior() 
{
  //Basta pegar o ultimo da direita 
  return auxMaior(raiz);
}

int ArvBinBusca::auxMaior(NoArv *p)
{
  if(p->getDir() != NULL)
    return auxMaior(p->getDir());
  else
    return p->getInfo();
}

int ArvBinBusca::menor() 
{
  //Basta pegar o ultimo da esquerda
  return auxMenor(raiz);
}

int ArvBinBusca::auxMenor(NoArv *p)
{
  if(p->getEsq() != NULL)
    return auxMenor(p->getEsq());
  else
    return p->getInfo();
}

void ArvBinBusca::removeMaior()
{
  remove(maior());
}

void ArvBinBusca::removeMenor()
{
  remove(menor());
}

int ArvBinBusca::contaParesCaminho(int x)
{
  return auxContaParesCaminho(raiz, x);
}

int ArvBinBusca::auxContaParesCaminho(NoArv *p, int x)
{
  if(p->getInfo() < x) //Andar para a direita
  {
    if(p->getInfo()%2 == 0)
      return auxContaParesCaminho(p->getDir(), x) + 1;
    else
      return auxContaParesCaminho(p->getDir(), x);
  }else if(p->getInfo() > x) //Andar para a esquerda
  {
    if(p->getInfo()%2 == 0)
      return auxContaParesCaminho(p->getEsq(), x) + 1;
    else
      return auxContaParesCaminho(p->getEsq(), x);
  }else{ 
    //Caso X == p->getInfo();
    if(p->getInfo()%2 == 0)
      return 1;
    else
      return 0;
  }

}

int ArvBinBusca::noMaisEsquerdaVal(NoArv* p, int val)
{
	p->setInfo(val);
	while (p->getEsq() != NULL)
		p = p->getEsq();
	return p->getInfo();
}

int ArvBinBusca::noMaisEsquerda()
{
	NoArv* p = raiz;
	while (p->getEsq() != NULL)
		p = p->getEsq();
	return p->getInfo();
}

int ArvBinBusca::noMaisDireita()
{
	NoArv* p = raiz;
	while (p->getDir() != NULL)
		p = p->getDir();
	return p->getInfo();
}

int ArvBinBusca::noMaisDireitaVal(NoArv* p, int val)
{
	p->setInfo(val);
	while (p->getDir() != NULL)
		p = p->getDir();
	return p->getInfo();
}


//TVC's Anteriores --------------------------------------

int ArvBinBusca::impressaoParcial(int a, int b)
{
  return auxImpressaoParcial(raiz, a, b);
}

int ArvBinBusca::auxImpressaoParcial(NoArv* p, int a, int b)
{
  if (p == NULL)
		return 0;
	if (p->getInfo() <= a) // Fora do intervalo
		return auxImpressaoParcial(p->getDir(), a, b);
	else if (p->getInfo() >= b) // Fora do intervalo
		return auxImpressaoParcial(p->getEsq(), a, b);
	else
	{ // Percurso em ordem
		int soma = 0;
		soma += auxImpressaoParcial(p->getEsq(), a, b);

		int filhoEsq = (p->getEsq() == NULL) ? 0 : p->getEsq()->getInfo();

		int filhoDir = (p->getDir() == NULL) ? 0 : p->getDir()->getInfo();

		if ((filhoEsq + filhoDir) % 2 == 0)
		{
			cout << p->getInfo() << " ";
			soma += p->getInfo();
		}
		soma += auxImpressaoParcial(p->getDir(), a, b);

		return soma;
	}
}

void ArvBinBusca::removeMenor(int val)
{
  NoArv* p = raiz;
	int aux;

	while (p != NULL)
	{
		if (p->getInfo() == val)
		{
			if (p->getEsq() != NULL)
			{
				aux = noMaisEsquerdaVal(p, val);
				remove(aux);
				p = NULL;
			}
			else
			{
				cout << "Nao foi possivel remover, pois val nao tem filho a esquerda!" << endl;
				break;
			}
		}
		else if (val < p->getInfo())
			p = p->getEsq();
		else if (val > p->getInfo())
		{
			p = p->getDir();
			if (val < noMaisEsquerda() || val > noMaisDireita())
			{
				cout << "Nao foi possivel remover, pois val nao foi encontrado!" << endl;
				break;
			}
		}
	}
}

void ArvBinBusca::removeFilhoEsquerdaK(int k, int val)
{
  NoArv *p = raiz;
	int nivel = 0;
	while (p!=NULL && p->getInfo() != val && nivel<k)
	{
		if ( val < p->getInfo() )
		{
			p = p->getEsq();
		}
		else
		{
			p = p->getDir();
		}
		nivel++;
	}

	if (p == NULL)
	{
		cout << "Nao alcancou nenhum no caminho para o valor val na arvore." << endl;
	}
	else if (nivel==k)
	{
		if (p->getEsq() == NULL)
		{
			cout << "No com valor val nao possui subarvore a esquerda." << endl;
		}
		else
		{
			p->setEsq( auxRemove(p->getEsq(), p->getEsq()->getInfo()) );
		}
	}
	else
	{
		cout << "Nao foi possivel alcancar o valor val ate o nivel k ou o valor esta num nivel inferior." << endl;
	}
}


//TVC ---------------------------------------------

int ArvBinBusca::sucessor(int x, int y, int val)
{
  int suc = val+1;

  if(suc >= x && suc <= y){
    return auxSucessor(raiz, suc);
  } else{
    return -1;
  }
}

int ArvBinBusca::auxSucessor(NoArv *p, int suc)
{
  if(p == NULL)
    return -1;
  else if(p->getInfo() == suc)
    return p->getInfo();
  else if(suc > p->getInfo())
    return auxSucessor(p->getDir(), suc);
  else
    return auxSucessor(p->getEsq(), suc);
}

