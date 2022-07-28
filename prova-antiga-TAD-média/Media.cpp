#include <iostream>
#include "Media.h"

using namespace std;

Media::Media(int qtdValor)
{ 
  cout << "Criando objeto X" << endl;
  m=0;
  n = qtdValor;
  x = new int[n];
  setX();
}

Media::~Media()
{ 
  cout << "Destruindo objeto X";
  delete [] x;
}

void Media::setX()
{ 
  for(int i=0;i<n; i++)
  {
    cin >> x[i];
  }
}

void Media::setM()
{
  int soma=0;
  for(int i=0;i<n;i++)
  {
    soma+=x[i];
  }

  m = (float)soma/n;
}

float Media::getM()
{
  if(m==0)
     setM();

  return m;
}
