#include "IndiceReposicoes.hpp"
#include <string>

// Construtor padrão
IndiceReposicoes::IndiceReposicoes() {
    // As tabelas hash internas já se inicializam sozinhas através de seus próprios construtores
}

// Insere uma nova reposição em todos os índices
void IndiceReposicoes::inserir_reposicao(const Reposicao& r) {
    // 1. Indexa o timestamp da reposição
    // Mapeia: "string_do_timestamp" -> id_da_reposicao
    timestamp.inserir(std::to_string(r.get_timestamp()), r.get_id());

    // 2. Indexa CADA produto contido nessa reposição
    int total_produtos = r.get_tamanho();
    const int* vetor_ids_produtos = r.get_id_produtos();

    for (int i = 0; i < total_produtos; ++i) {
        int id_do_produto_atual = vetor_ids_produtos[i];
        
        // Mapeia: "string_do_id_do_produto" -> id_da_reposicao
        id_produto.inserir(std::to_string(id_do_produto_atual), r.get_id());
    }
}

// Busca as reposições que aconteceram em um determinado timestamp
const int* IndiceReposicoes::buscar_timestamp(int timestamp, int& qtd) const {
    // Converte o int recebido para string antes de buscar na tabela hash
    return this->timestamp.buscar(std::to_string(timestamp), qtd);
}

// Busca as reposições que continham um determinado produto
const int* IndiceReposicoes::buscar_id_produto(int id_produto, int& qtd) const {
    // Converte o int recebido para string antes de buscar na tabela hash
    return this->id_produto.buscar(std::to_string(id_produto), qtd);
}