#include <iostream>
#include "Aluno.h"

using namespace std;

Aluno::Aluno(string n, string m) {
  nome = n;
  matricula = m;
}

Aluno::~Aluno()
{
  cout << "Destruindo aluno: " << nome << endl;
}

float Aluno::getNota() {
  return nota;
}

void Aluno::setNota(float valor) {
  cout << "Alterando nota do aluno" << endl;
  nota = valor;
}

bool Aluno::verificaAprovado() {
  if (nota >= 60.0)
    return true;
  else
    return false;
}

string Aluno::getNome() {
  return nome;
}

void Aluno::info()
{
  cout << "Nome: " << nome << endl;
  cout << "Matricula: " << matricula << endl;
  cout << "Nota: " << nota << endl;
  if ( verificaAprovado() )
    cout << "Situacao: aprovado" << endl;
  else
    cout << "Situacao: reprovado" << endl;
}