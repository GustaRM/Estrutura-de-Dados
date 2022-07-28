#include <iostream>
#include "ArvBin.h"
using namespace std;

int main()
{
  //ArvBin arv, a1, a2, a3, a4, vazia;

  /*
  arv.montaArvore();
  arv.insere(15);
  arv.insere(25);
  arv.insere(10);
  */

  //arv.preOrdem();

  /*a1.cria(25, &vazia, &vazia);
  a2.cria(35, &vazia, &vazia);
  a3.cria(18, &a1, &a2);

  a1.cria(38, &vazia, &vazia);
  a2.cria(14, &vazia, &vazia);
  a4.cria(15, &a1, &a2);

  arv.cria(10, &a3, &a4);
  a1.anulaRaiz();
  a2.anulaRaiz();
  a3.anulaRaiz();
  a4.anulaRaiz();
 */ 

  ArvBin arv, vazia, a1, a2, a3;
  a1.cria(-35, &vazia, &vazia);
  a2.cria(-19, &vazia, &vazia);
  a3.cria(-20, &a1, &a2);
  a1.cria(-5, &vazia, &vazia);
  a2.cria(10, &a1, &vazia);
  a1.cria(-15, &a3, &a2);
  a2.cria(45, &vazia, &vazia);
  a3.cria(60, &vazia, &vazia);
  a2.cria(50, &a2, &a3);
  a3.cria(80, &vazia, &vazia);
  a2.cria(75, &a2, &a3);
  arv.cria(40, &a1, &a2);
  a1.anulaRaiz();
  a2.anulaRaiz();
  a3.anulaRaiz();

  int n[4];
  arv.criaVetDoisFilhos(2, n);

   for(int i = 0; i < 4; i++)
 {
   cout << n[i] << " ";
 }


  //TVC's anteriores (teste)
  /*
  arv.contaElegante();
  cout << endl;
  arv.contaElegante1();
  cout << endl;
  arv.contagens(5);
  */
  

  /*
  cout << "Total de Nós: " << arv.contaNos() << endl;
  cout << "Total de Folhas: " << arv.contaNosFolhas() << endl;
  cout << "Altura: " << arv.altura() << endl;
  cout << "Total de impares: " << arv.contaImpar() << endl;

  int k=2;
  cout << "Nivel " << k << ": ", arv.imprimeNivel(k);
  cout << endl;
  cout << "Média nível " << k << ": " << arv.mediaNivel(k) << endl;
  cout << "Menor valor da árvore: "<< arv.min() << endl;
  cout << "Maior valor da árvore: "<< arv.max() << endl;
  */

  arv.preOrdem();
  return 0;
}