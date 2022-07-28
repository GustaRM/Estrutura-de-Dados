#include <iostream>

using namespace std;

class MatrizEspecial
{
  private:
    int *vet;
  public:
    MatrizEspecial(int ordem);
    ~MatrizEspecial();
    int getInd(int i, int j);
    int get(int i, int j);
    void set (int i, int j, int val);
};