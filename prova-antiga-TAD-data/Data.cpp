#include <iostream>
#include "Data.h"

using namespace std;

Data::Data(int d, int m, int a)
{
  dia = 1;
  mes = 1;
  ano = 1000;

  if(d<30 && d>1)
    dia = d;
  if(m<12 && m>1)
    mes = m;
  if(a>0)
    ano = a;
  
}

Data::~Data()
{

}

void Data::setDiaMesAno(int d, int m, int a)
{
  dia = 1;
  mes = 1;
  ano = 1000;
  
  if(d<30 && d>1)
    dia = d;
  if(m<12 && m>1)
    mes = m;
  if(a>0)
    ano = a;
}

void Data::imprime()
{
  cout << dia << '/' << mes << '/'<< ano;
}

Data* Data::somaAnos(int nAnos)
{
  Data *aux= new Data(dia, mes, ano+nAnos);
  return aux;
}