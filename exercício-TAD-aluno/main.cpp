#include <iostream>
#include "Aluno.h"
using namespace std;

int main()
{
  Aluno a("Fulano", "20154565AB");
  cout << "Digite a nota de " << a.getNome() << endl ;
  float n;
  cin >> n;
  a.setNota(n);
  a.info();
  return 0;
}
 