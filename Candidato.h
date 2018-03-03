#ifndef _CANDIDATO_H
#define _CANDIDATO_H
#include <cstring>
#include <sstream>

using namespace std;

class Candidato{

private:
  string sobrenome;
  string nome;
  int nota;
public:
  Candidato(string linha);

  inline int getNota()const{return nota;}
  string getNome()const { return nome; }
  string getSobreNome()const{return sobrenome;}

  string toString();
  bool igual(string n, string s);
};
#endif
