#include <iostream>
#include "MatrizEspecial1.h"

using namespace std;

int main()
{
  int nn;
  cin >> nn;
  MatrizEspecial1 mat(nn);

  for(int i = 0; i < nn; i++)
    for(int j = 0; j < nn; j++)
    {
      float val = i*nn + j;
      mat.set(i, j, val);
    }
  for(int i = 0; i < nn; i++)
  {
      for(int j = 0; j < nn; j++)
      {
        float val = mat.get(i, j);
        cout << val << "\t";
      }
    cout << endl;
  }
 return 0;
}