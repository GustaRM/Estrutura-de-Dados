#include "Poligono.h"
#include <math.h>

//Método construtor
Poligono::Poligono(int n, float l)
{
  setNumLados(n);
  setTamLados(l);
}
Poligono::~Poligono() { }

void Poligono::setNumLados(int n)
{
  if(n>=3)
    numLados = n;
}

void Poligono::setTamLados(int l)
{
  if(l > 0) 
    tamLado = l;
}

float Poligono::area()
{
  return numLados*pow(tamLado,2) / (4*tan
  (3.1416/numLados));
}

float Poligono::perimetro()
{
  return numLados*tamLado;
}

float Poligono::angInterno()
{
  return 180*(numLados - 2)/numLados;
}