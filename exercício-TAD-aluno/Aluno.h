#include <iostream>
#include <string>
using namespace std;

class Aluno
{
  private:
    //Variáveis
    string nome;
    string matricula;
    float nota;

  public:
    Aluno(string n, string m); //construtor
    ~Aluno();                  //destrutor

    void info();
    float getNota();
    string getNome();
    void setNota(float valor);
    bool verificaAprovado();
};