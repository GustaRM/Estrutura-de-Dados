#include <iostream>

using namespace std;

class MatrizEspecial1
{
  private:
    int n; // numero de is e js
    float *vet; // vetor de tamanho nl*nc
    int detInd(int i, int j);

  public:

    MatrizEspecial1(int n);
    ~MatrizEspecial1();
    float get(int i, int j);
    void set(int i, int j, float val);
};
