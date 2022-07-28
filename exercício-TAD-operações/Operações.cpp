#include <iostream>
#include "Operações.h"

using namespace std;

Operações::Operações()
{
  setA();
  setB();
  cout << "O valor de A é: " << getA() << endl;
  cout << "O valor de B é: " << getB() << endl;
  cout << "O valor da soma é: " << somar() << endl;
}

Operações::~Operações()
{
  cout << "Destrutor";
}

int Operações::somar()
{
  return a+b;
}

int Operações::subtrair()
{
  return a-b;
}

int Operações::multiplicar()
{
  return a*b;
}

int Operações::dividir()
{
  return a/b;
}

int Operações::getA()
{
  return a;
}

int Operações::getB()
{
  return b;
}

void Operações::setA()
{
  cout << "Digite o valor de A: ";
  cin >> a;
}

void Operações::setB()
{
  cout << "Digite o valor de B: ";
  cin >> b;;
}