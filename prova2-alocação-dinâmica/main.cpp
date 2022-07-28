#include <iostream>

using namespace std;

int sucessor(int n, int vet[], int x)
{
  if(n==1)
    return -1;

  if(x==n)
    return vet[n+1];
  else
    return sucessor(n-1, vet, x);
}

int main()
{
  int n, x;
  cin >> n;
  cin >> x;

  int *vet = new int[n];

  for(int i=0;i<n;i++)
  {
    cin >> vet[i];
  }

  int result = sucessor(n, vet, x);
  cout << result;

  return 0;
} 