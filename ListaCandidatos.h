#include "NoCandidato.h"
#include <fstream>

class ListaCandidatos
{
public:
  NoCandidato *head;
  unsigned NumCandidatos;

  ListaCandidatos():head(NULL),NumCandidatos(0){};
  ListaCandidatos(char* NomeArquivo);

  void adicioneComoHead(Candidato* c);

  bool remove(const string &nome,const string &sobreNome);
  bool estaVazia() { return (head == NULL); }

  string toString();
  unsigned tamanho()const{ return NumCandidatos; }

  void filtrarCandidatos(unsigned nota);
  void concatena(ListaCandidatos *lista1);

};
