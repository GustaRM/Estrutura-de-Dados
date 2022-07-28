#include <iostream>

using namespace std;

class Media
{
  private:
    int n;
    int *x;
    float m;
  
  public:
    Media(int n);
    ~Media();
    void setX();
    void setM();
    float getM();
};