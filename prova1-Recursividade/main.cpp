#include <iostream>
using namespace std;

//TVC 1
 bool* maiorQueProximo(int vet[], int n, int *t)
{
  t = &n;
  bool *vetBool = new bool [*t];

  for(int i=0;i<n;i++)
  {
    if(i==n-1)
    {
      vet[i]=0;
    }
    if (vet[i] > vet[i+1])
    {
      vetBool[i]=1;
    }else{
      vetBool[i]=0;
    }
  }

  return vetBool;
}

int main() {
  int n;
  cin >> n;
  int *vet1 = new int[n];
  int *t;

  for(int i=0;i<n;i++)
  {
    cin >> vet1[i];
  }

  bool *vetNovo = maiorQueProximo(vet1, n, t);

  for(int i=0;i<n;i++)
  {
    cout << vetNovo[i] << ' ';
  }


  delete [] vet1;
  delete [] vetNovo;

  return 0;
}  

