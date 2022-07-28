#include <iostream>
#include "Media.h"

using namespace std;

int main() 
{
  int v;
  cout << "Digite a quantidade de notas: ";
  cin >> v;
  Media a(v);

  cout << "Média dos valores: " << a.getM() << endl;

  return 0;
} 