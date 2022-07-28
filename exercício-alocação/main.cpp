#include <iostream>

using namespace std;

float* alocaVetor(int n)
{
  float *vet = new float [n];

  for(int i=0; i<n; i++)
  { 
    cout << "Digite o " << i+1 << " elemento do vetor: ";
    cin >> vet[i];
  }

  return vet;

}

float calcMedia(int n, float vet[])
{
  float soma=0;
  for(int i=0; i<n; i++)
  { 
    soma += vet[i];
  }

  float media = soma/n;
  return media;
}

int main() {

  int n;
  cout << "Digite o tamanho do vetor: ";
  cin >> n;
  float *vetAloc = alocaVetor(n);
  float x = calcMedia(n, vetAloc);
  cout << "A média dos valroes é: " <<x;

  delete [] vetAloc;

  return 0;
}