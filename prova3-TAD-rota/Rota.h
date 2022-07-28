#include <iostream>

using namespace std;

class Rota{
  private:        
    int n; 
    float *tempos;
  public:
    Rota(int a);        
    ~Rota();
    void leTempos();
    float tempoTotal();
};