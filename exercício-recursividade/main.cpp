#include <iostream>
#include <string.h>
using namespace std;

bool buscaBinaria(int vet[], int n, int chave)
{ 
  if(n==0 && vet[0]!=chave)
    return 0;
  else{
    if(vet[n-1]==chave)
      return 1;
    else
      return buscaBinaria(vet, n-1, chave);
  }
}


bool ehPalindromo(char a[], int n)
{
  if (n <= 1)
    return 1;
  else{
    char b, c;
    b = a[0];
    c = a[strlen(a)-1];
    if(b==c){
      b++;
      c--;
      return ehPalindromo(a, n-2);
    }else
      return 0;
  }
}


int numDigitos(int n)
{
  if(n < 10)
  {
    return 1;
  }else
  {
    return 1 + numDigitos(n/10);
  }
}


int soma(int a, int b)
{ 
  if(a==b)
    return a;
  else
    return a + soma(a+1, b);
}*/ // Soma de A até B


int main() {

    //Busca binaria 
  int n;
  cout <<"Tamanho do Vetor: ";
  cin >> n;
  int* vet= new int[n];
  int chave;

  for(int i=0; i<n ; i++)
  { 
    cout << i+1 << "° Valor do vetor: ";
    cin >> vet[i];
  }

  cout <<"Valor da chave: ";
  cin >> chave;

  int x = buscaBinaria(vet, n, chave);
  if(x==0)
    cout <<"Não encontrei a chave";
  else
    cout <<"Encontrei a chave";



    //Verifica se é Palindromo
  /*int n;
  cout << "Tamanho da string: ";
  cin >> n;
  char* a = new char[n];
  cout << "String: ";
  cin >> a;
  
  int x = ehPalindromo(a, n);
  if (x==1)
    cout << "Sim!!";
  else
    cout << "Não!!";
  */


    //Número de digitos
  /*int n;
  cin >> n;
  int x = numDigitos(n);
  cout << x;*/


    //Soma de A a B
  /*
  int a = 2;
  int b = 5;
  int x = soma(a, b);
  cout << x;*/
  return 0;

}