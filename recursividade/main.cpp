#include <iostream>
using namespace std;


int fat(int n)
{ 
  if (n == 0 || n == 1)
    return 1;
  else
    return n * fat(n-1);
}
 // Função fatorial recursiva

void seq(int a, int b)
{
  if(a <= b)
  {

    seq(a+1, b);
    cout << a << " ";
  }
} // Imprime sequencia

int soma(int n)
{
  if(n==0)
    return n;
  else
    return n + soma(n-1);
} // Soma sequencia

float func(float vet[], int tam)
{
  if(tam == 1)
    return vet[0];

  float x = func(vet, tam-1);

  if(x < vet[tam-1])
    return x;
  else
    return vet[tam-1];
  
} // Encontra menor numero do vetor

float func(float vet[], int tam)
{ 
  float soma = 0;

  if(tam < 0)
    return soma;
  else
    return soma = vet[tam] + func(vet, tam-1);
  
} // Soma elementos dos vetores

int pares(int vet[], int n)
{
  if(n == 1) // caso base
    if (vet[0] % 2 == 0)
      return 1;

  int x = pares(vet, n-1); // passo recursivo

  if (vet[n-1] % 2 == 0)
    return x+1;
  else
    return x;
} // Conta o número de elementos pares no vetor

int main() {

  
  int n = 4;
  int *pt=&n;
  cout << pt << endl;
  int vet[4] = {2, 6, 5, 2};
  int x = pares(vet, n);
  cout << "Qtd pares: "<< x;*/


  /*int tam = 4;
  float vet[4] = {100, 4, 3, 2};
  int x=func(vet, tam);
  cout << x;
  
  
  /*int tam = 4;
  float vet[4] = {10, 4, 32, 20};
  int x=func(vet, tam);
  cout << x;*/

  /*int a=5;
  int x=soma(a);
  cout << x;*/
  
  
  /*int a=1, b=10;
  //cin >> a >> b;
  seq(a,b);*/

  /*int n;
  cout << "Digite um número para calcular seu fatorial: ";
  cin >> n;
  int x = fat(n);
  cout << "O fatorial de " << n << " é: " << x;*/


}