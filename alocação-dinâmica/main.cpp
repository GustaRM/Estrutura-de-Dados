#include <iostream>

using namespace std;

float *somaVetores(float u[], float v[])
{
  float *r = new float[3]; // alocacao dinamica

  r[0] = u[0] + v[0];
  r[1] = u[1] + v[1];
  r[2] = u[2] + v[2];
  return r;

}

int main() {

  int i, dim=3;
  float vecU[3] = {1.0,1.0,1.0};
  float vecV[3] = {2.0,1.0,-1.0};

  float *vecRes = somaVetores(vecU, vecV);

  for(i=0; i<dim; i++)
  {
    cout << "resultado " << i << " = ";
    cout << vecRes[i] << endl;
  }
  delete [] vecRes; 



  int *dados;
  dados = new int [10];

  for(int i=0; i<10; i++)
  {
    cout << "Digite os valores: ";
    cin >> dados[i];
  }

  for(int i=0; i<10; i++)
  {
    cout << "Valor da posição "<< i << " = "<<dados[i] << endl;
  }

  delete [] dados;
  return 0;

}