#include <iostream>

using namespace std;

class Data
{
  private: 
    int dia;
    int mes;
    int ano;

  public:
    Data(int d, int a, int m);
    ~Data();

    void setDiaMesAno(int d, int m, int a);
    void imprime();
    Data* somaAnos(int nAnos);
};
