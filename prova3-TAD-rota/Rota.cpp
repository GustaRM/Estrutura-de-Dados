#include <iostream>
#include "Rota.h"

using namespace std;

Rota::Rota(int a)
{
  if(a>=2){
    n = a;
    tempos = new float [n];
    leTempos();
    tempoTotal();
  }else{
    cout << "Quantidade inválida";
    exit(1);
  }
}

Rota::~Rota()
{
  delete [] tempos;
}

void Rota::leTempos()
{
  for(int i=0; i<n; i++)
  {
    cout << "Tempo: ";
    cin >> tempos[i];

    while(tempos[i]<0){
      cout << "Tempo inválido, tente novamente: ";
      cin >> tempos[i];
    }
  }
}

float Rota::tempoTotal()
{
  float soma=0;
  int horas;
  float minutos;
  for(int i=0; i<n; i++)
  {
    soma+=tempos[i];
  }

  horas = abs(soma);
  minutos = (soma - horas)*0.60*100;
  
  cout<<"Tempo total em hh:mm -> ";
  cout << horas <<":" << minutos;
  
  return soma;
}