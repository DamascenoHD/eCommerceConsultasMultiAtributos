#ifndef INDICEREPOSICOES_HPP
#define INDICEREPOSICOES_HPP

#include "IndiceInvertido.hpp"
#include "Reposicao.hpp"

class IndiceReposicoes {
private:
    // timestamp -> ids das reposições
    IndiceInvertido timestamp;

    // id do produto -> ids das reposições
    IndiceInvertido id_produto;

public:
    IndiceReposicoes();

    // Insere uma nova reposição em todos os índices
    void inserir_reposicao(const Reposicao& r);

    const int* buscar_timestamp(int timestamp,
                               int& qtd) const;

    const int* buscar_id_produto(int id_produto,
                               int& qtd) const;
};

#endif