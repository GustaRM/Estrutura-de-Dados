class Poligono
{
  private:
    int numLados; // numero de lados do poligono
    float tamLado; // tamanho de cada lado
  public:
    float area(); // calcula area
    float perimetro(); // calcula perimetro
    float angInterno(); // calcula angulo interno
    Poligono (int n, float l);
    ~Poligono();
    void setNumLados(int n);
    void setTamLados(int l);
};