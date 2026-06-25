#ifndef INDICEINVERTIDO_HPP
#define INDICEINVERTIDO_HPP
#include "TabelaHash.hpp"
class IndiceInvertido {
private:
    TabelaHash indice;

public:

    void inserir(const std::string& chave, int id);

    const int* buscar(const std::string& chave, int& qtd) const;
};

#endif