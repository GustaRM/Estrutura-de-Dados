
class No
{
  private:
    int info; /// valor armazenado no No
    No *prox; /// ponteiro para o proximo No
  
  public:
    No()                  { };
    ~No()                 { };

    int getInfo()         { return info; };
    No* getProx()         { return prox; };
    
    void setInfo(int val) { info = val; };
    void setProx(No *p)   { prox = p; };
};