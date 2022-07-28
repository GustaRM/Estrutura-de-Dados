#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "ArvBin.h"

using namespace std;

ArvBin::ArvBin()
{
  raiz = NULL;
}

int ArvBin::getRaiz()
{
  if (raiz != NULL)
    return raiz->getInfo();
  else
  {
    cout << "Árvore vazia!" << endl;
    exit(1);
  }
}

void ArvBin::cria(int x, ArvBin *sae, ArvBin *sad)
{
  NoArv *p = new NoArv();
  p->setInfo(x);
  p->setEsq(sae->raiz);
  p->setDir(sad->raiz);
  raiz = p;
}

void ArvBin::anulaRaiz()
{
  raiz = NULL;
}

void ArvBin::montaArvore()
{
  if(!vazia())
    cout << "Arvore jah montada. So eh possivel a insercao de nos." << endl;
  else
  {
    cout << "Montagem da arvore em pre-ordem:" << endl;
    raiz = auxMontaArvore();
  }
}

NoArv* ArvBin::auxMontaArvore()
{
  string linha;
  cout << "Valor: ";
  cin >> linha;
  if(linha != "NULL" && linha != "null")
  {
    istringstream ent(linha);
    int valor;
    ent >> valor; //converte string em int 
    NoArv *p = new NoArv();
    p->setInfo(valor);

    cout << "Esquerda" << endl;
    p->setEsq(auxMontaArvore());
    cout << "Volta no noh " << p->getInfo() << endl;
    
    cout << "Direita" << endl;
    p->setDir(auxMontaArvore());
    cout << "Volta no noh " << p->getInfo() << endl;
    return p;
  }else
    return NULL;
}

void ArvBin::insere(int x)
{
  raiz = auxInsere(raiz, x);
}

NoArv* ArvBin::auxInsere(NoArv *p, int x)
{
  if(p == NULL)
  {
    p = new NoArv();
    p->setInfo(x);
    p->setEsq(NULL);
    p->setDir(NULL);
  }else
  {
    char direcao;
    cout << x << " a esquerda (e) ou direita (d) de " << p->getInfo() << ": ";
    cin >> direcao;
    if(direcao == 'e' || direcao == 'E')
      p->setEsq(auxInsere(p->getEsq(), x));
    else
      p->setDir(auxInsere(p->getDir(), x));
  }
  return p;
}

bool ArvBin::vazia()
{
  return (raiz == NULL);
}

bool ArvBin::busca(int x)
{
  return auxBusca(raiz, x);
}

bool ArvBin::auxBusca(NoArv *p, int x)
{
  if (p == NULL)
    return false;
  else if (p->getInfo() == x)
    return true;
  else if (auxBusca(p->getEsq(), x))
    return true;
  else
    return auxBusca(p->getDir(), x);
}

ArvBin::~ArvBin()
{
  raiz = libera(raiz);
}

NoArv* ArvBin::libera(NoArv *p)
{
  if (p != NULL)
  {
    p->setEsq(libera(p->getEsq()));
    p->setDir(libera(p->getDir()));
    delete p;
    p = NULL;
  }
  return NULL;
}

void ArvBin::preOrdem()
{
  cout << "Arvore Binaria em Pre-Ordem: ";
  auxPreOrdem(raiz);
}

void ArvBin::auxPreOrdem(NoArv *p)
{
  if (p != NULL)
  {
    cout << p->getInfo() << " ";
    auxPreOrdem(p->getEsq());
    auxPreOrdem(p->getDir());
  }
}

//Exercícios ---------------------------------------------

int ArvBin::contaNos()
{
  return auxContaNos(raiz);
}

int ArvBin::auxContaNos(NoArv *p)
{
  if(p != NULL)
  {
    int totalEsq, totalDir;
    totalEsq = auxContaNos(p->getEsq());
    totalDir = auxContaNos(p->getDir());

    return totalEsq+totalDir+1;
  }

  return 0;
}

int ArvBin::contaNosFolhas()
{
  return auxContaNosFolhas(raiz);
}

int ArvBin::auxContaNosFolhas(NoArv *p)
{
  if(p == NULL)
    return 0;
  
  if(p->getEsq() == NULL && p->getDir() == NULL)
  //Verifica se não possui filhos
  {
    int totalEsq, totalDir;
    totalEsq = auxContaNosFolhas(p->getEsq());
    totalDir = auxContaNosFolhas(p->getDir());
    return totalEsq+totalDir+1;

  }else 
  {
    //Se tiver pelo menos um filho ja não é folha
    int totalEsq, totalDir;
    totalEsq = auxContaNosFolhas(p->getEsq());
    totalDir = auxContaNosFolhas(p->getDir());
    return totalEsq+totalDir; //retira o +1
    
  }

}

int ArvBin::altura()
{
  return auxAltura(raiz);
}

int ArvBin::auxAltura(NoArv *p)
{
  if(p == NULL)
    return -1;

  int he = auxAltura(p->getEsq());
  int hd = auxAltura(p->getDir());

  if(he > hd)
    return he+1;
  else
    return hd+1;
}

int ArvBin::contaImpar()
{
  return auxContaImpar(raiz);
}

int ArvBin::auxContaImpar(NoArv *p)
{
  if(p == NULL)
    return 0;
  
  int total=auxContaImpar(p->getEsq()) + auxContaImpar(p->getDir());

  if(p->getInfo() % 2 == 1) //Verifica se é impar
    total++;
  return total;

}

void ArvBin::imprimeNivel(int k)
{
  auxImpNivel(raiz, k, 0);
}

void ArvBin::auxImpNivel(NoArv *p, int k, int atual)
{
  if(p != NULL && atual <= k)
  {
    if(atual == k)
      cout << p->getInfo() << " ";
  
    auxImpNivel(p->getEsq(), k, atual+1);
    auxImpNivel(p->getDir(), k, atual+1);
    
  }
}

float ArvBin::mediaNivel(int k)
{
  int soma=0, cont=0;
  auxMediaNivel(raiz, k, &soma, &cont);

  if(cont > 0)
  {
    return soma / (float) cont;
  }else
    return 0;
}

void ArvBin::auxMediaNivel(NoArv *p, int k, int *soma, int *cont)
{
  if(p != NULL && k >= 0)
  {
    if(k == 0)
    {
      *soma = *soma + p->getInfo();
      (*cont)++;
    }
  
    auxMediaNivel(p->getEsq(), k-1, soma, cont);
    auxMediaNivel(p->getDir(), k-1, soma, cont);
    
  }
}

int ArvBin::min()
{
  if(raiz == NULL)
  {
    cout << "Árvore vazia!";
    exit(1);
  }
  
  int menor = raiz->getInfo();
  auxMin(raiz, &menor);
  return menor;
}

void ArvBin::auxMin(NoArv *p, int *menor)
{
  if(p != NULL)
  {
    if(p->getInfo() < *menor)
      *menor = p->getInfo();
    auxMin(p->getEsq(), menor);
    auxMin(p->getDir(), menor);
  }
}

int ArvBin::max()
{
  if(raiz == NULL)
  {
    cout << "Árvore vazia!";
    exit(1);
  }
  
  int maior = raiz->getInfo();
  auxMax(raiz, &maior);
  return maior;
}

void ArvBin::auxMax(NoArv *p, int *maior)
{
  if(p != NULL)
  {
    if(p->getInfo() > *maior)
      *maior = p->getInfo();
    auxMax(p->getEsq(), maior);
    auxMax(p->getDir(), maior);
  }
}


//TVC's Anteriores --------------------------------------
void ArvBin::contaElegante()
{
  int contPares = 0;
  int contFpos = 0;
  auxContaElegante(raiz, &contPares, &contFpos);

  cout << "Nós pares: " << contPares << endl;
  cout << "Folhas Positivas: " << contFpos << endl;
}

void ArvBin::auxContaElegante(NoArv *p, int *contPares, int *contFpos)
{ 
  //Pré-Ordem (raiz, sae, sad)
  if (p != NULL)
	{
		if (p->getInfo()%2 == 0)
			(*contPares)++;
		if (p->getEsq() == NULL && p->getDir() == NULL && p->getInfo() >= 0)
      (*contFpos)++;
		
    auxContaElegante(p->getEsq(), contPares,contFpos); // sae
		auxContaElegante(p->getDir(), contPares,contFpos); // sad
	}
}


void ArvBin::contaElegante1()
{
  int cont2Filhos = 0;
  int contMult5 = 0;
  auxContaElegante1(raiz, &cont2Filhos, &contMult5);

  cout << "Nós com 2 filhos: " << cont2Filhos << endl;
  cout << "Nós folhas multiplos de 5: " << contMult5 << endl;
}

void ArvBin::auxContaElegante1(NoArv *p, int *cont2Filhos, int *contMult5)
{ 
  //Pré-Ordem (raiz, sae, sad)
  if (p != NULL)
	{

		if (p->getInfo()%5 == 0 && p->getEsq() == NULL && p->getDir() == NULL)
			(*contMult5)++;
		if (p->getEsq() != NULL && p->getDir() != NULL)
      (*cont2Filhos)++;
		
    auxContaElegante1(p->getEsq(), cont2Filhos,contMult5); // sae
		auxContaElegante1(p->getDir(), cont2Filhos,contMult5); // sad
	}
} 

void ArvBin::contagens(int val)
{
  int contFolha1Filho = 0;
  int contMultVal = 0;

  auxContagens(raiz, val, &contFolha1Filho, &contMultVal);

  cout << "Nós folhas ou com 1 filho: " << contFolha1Filho << endl;
  cout << "Nós multiplos de " << val <<": "<<contMultVal << endl;
}

void ArvBin::auxContagens(NoArv *p, int val, int *contFolha1Filho, int *contMultVal)
{
  //Ordem (sae, raiz, sad)
  if (p != NULL)
	{
		auxContagens(p->getEsq(), val, contFolha1Filho,contMultVal); // sae
		
    //É folha ou possui um filho
		if ((p->getEsq() == NULL && p->getDir() == NULL) || (p->getEsq() == NULL || p->getDir() == NULL))
			(*contFolha1Filho)++;

    //Nós multiplos de Val
		if (p->getInfo()%val == 0)
      (*contMultVal)++;
		
    auxContagens(p->getDir(), val,contFolha1Filho,contMultVal); // sad
	}
}


//TVC ----------------------------------------------------------
int* ArvBin::criaVetDoisFilhos(int k, int *n)
{
  int tam = k*2;
  n = new int[tam];
  return auxCriaVetDoisFilhos(raiz, k, 0, 0, n);
}

int* ArvBin::auxCriaVetDoisFilhos(NoArv *p, int k, int atual, int pos, int n[])
{
  //Caso árvore vazia
  if(p == NULL)
  {
    return NULL;
  }
  else{
    //Verifica se esta em K ou K-1 && se tem dois filhos
    if((atual == k || atual == k-1) && (p->getEsq() != NULL && p->getDir() != NULL))
    {
      n[pos] = p->getInfo();
      pos++;
    }
    auxCriaVetDoisFilhos(p->getEsq(), k, atual, pos, n); //sae
    auxCriaVetDoisFilhos(p->getDir(), k, atual, pos, n); //sad

    if(pos < k*2)
    {
      //Completa as posições não utilizadas do vetor com -1;
      for(int i = pos; i<k*2; i++)
      {
        n[pos] = -1;
      }
    }

  }

  return n;
}
