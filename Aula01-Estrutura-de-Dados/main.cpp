#include <iostream>


using namespace std;

float leVetorCalculaMedia(int n, float vet[])
{
  float soma = 0;
  for(int i = 0; i < n; i++)
  {
    float val;
    cout << "Digite um valor real: ";
    cin >> val;
    vet[i] = val;
  }

  for(int i = 0; i < n; i++)
  {
    soma+=vet[i];
  }

  return soma/n;
}

float leCalculaMedia(int n)
{
  float soma = 0;

  for(int i = 0; i < n; i++)
  {
    float val;
    cout << "Digite um valor real: ";
    cin >> val;
    soma+=val;
  }
  

  return soma/n;
}

int procuraCharNaString(string str, char ch[2])
{
  int pos = -1;
  for(int i = 0; i< str.size(); i++)
  {
    if (ch[0] == str[i])
    {
      pos = i;
      break;
    }
  }
  return pos;
}

bool ehPrimo(int n)
{
  int s = 0;
  for(int i = n;i > 0; i--)
  {
    if(n % i == 0)
    {
      s+=1;
    }
   // cout << s;    
  }

  if (s != 2)
  {
    return false;
  }else{
    return true;
  }
}

int main() {
  int n;

  do{
    cout << "Digite um número maior que zero: ";
    cin >> n;
  }while (n < 0);
  
  cout << "Resultado: " << ehPrimo(n);
  return 0;
}