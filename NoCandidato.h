#include "Candidato.h"

class NoCandidato
{
public:
  Candidato* conteudo;
  NoCandidato* next;

  NoCandidato(Candidato *C):conteudo(C),next(NULL){ };
  NoCandidato(Candidato *C,NoCandidato *NoNext);

  inline operator<(int nota){ return conteudo->getNota()<nota; }
  string toString();
};
