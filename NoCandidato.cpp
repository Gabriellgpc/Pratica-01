#include "NoCandidato.h"

NoCandidato::NoCandidato(Candidato *C,NoCandidato *NoNext)
{
  conteudo = C;
  next = NoNext;
};
string NoCandidato::toString()
{
  NoCandidato *NoAtual = next;
  string StringOut = conteudo->toString();

  while(NoAtual != NULL)
  {
    StringOut += " -> ";
    StringOut += NoAtual->conteudo->toString();
    NoAtual = NoAtual->next;
  }
  StringOut += " -> 0";
  return StringOut;
};

