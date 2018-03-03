#include "ListaCandidatos.h"
#include <iostream>

void ListaCandidatos::adicioneComoHead(Candidato* c)
{
  head = new NoCandidato(c,head);
  NumCandidatos++;
}

string ListaCandidatos::toString()
{
  if(head == NULL)return "0";
  return head->toString();
}

ListaCandidatos::ListaCandidatos(char* NomeArquivo):
  NumCandidatos(0),
  head(NULL)
{
  ifstream arquivo(NomeArquivo);
  string linhaDados;

  if(!arquivo.is_open())std::cerr <<"Erro na leitura do arquivo\n";
  getline(arquivo,linhaDados,'\n');//Pegou o nome da cidade, mas nao faz nada
  while(getline(arquivo,linhaDados,'\n'))
    this->adicioneComoHead(new Candidato(linhaDados));
  arquivo.close();
}

bool ListaCandidatos::remove(const string &nome,const string &sobreNome)
{
  if(head == NULL)return false;
  NoCandidato* anterior = head;
  NoCandidato* atual = head->next;

  if(head->conteudo->igual(nome,sobreNome))
  {
    delete head;
    head = atual;
    this->NumCandidatos--;
    return true;
  }

  while(atual != NULL )
  {
    if(atual->conteudo->igual(nome,sobreNome))
    {
      this->NumCandidatos--;
      anterior->next = atual->next;
      delete atual;
      return true;
    }
    anterior = atual;
    atual = atual->next;
  }
  return false;
}

void ListaCandidatos::filtrarCandidatos(unsigned nota)
{
  NoCandidato *atual = head;
  while(atual != NULL)
  {
    if(*atual < nota)remove(atual->conteudo->getNome(),atual->conteudo->getSobreNome());
    atual = atual->next;
  }
}
void ListaCandidatos::concatena(ListaCandidatos *lista1)
{
  NoCandidato *end = head;
  if(this->head == NULL)
  {
    this->head = lista1->head;
    return;
  }
  while(end->next != NULL)end = end->next;

  end->next = lista1->head;
  this->NumCandidatos += lista1->NumCandidatos;
}
