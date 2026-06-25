#include "IndiceInvertido.hpp"

void IndiceInvertido::inserir(const std::string& chave, int id){
    indice.inserir(chave, id);
}

const int* IndiceInvertido::buscar(const std::string& chave, int& qtd) const{
    return indice.buscar(chave, qtd);
}