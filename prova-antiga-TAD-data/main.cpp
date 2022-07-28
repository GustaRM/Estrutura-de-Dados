#include <iostream>
#include "Data.h"

using namespace std;

int main() 
{
  int a, b, c;
  cin >> a >> b >> c;
  Data x(a, b, c);
  Data *y = x.somaAnos(12);

  cout << "Primeira data: ";
  x.imprime();
  cout << endl;
  cout << "Segunda data: ";
  y->imprime();
} 