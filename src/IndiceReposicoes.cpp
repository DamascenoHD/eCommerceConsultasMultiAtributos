#include "IndiceReposicoes.hpp"

void IndiceReposicoes::inserir_reposicao(const Reposicao& r){
    timestamp.inserir(std::to_string(r.get_timestamp()), r.get_id());
    id_produto.inserir(std::to_string(r.get_id_produtos()), r.get_id());
}

const int* IndiceReposicoes::buscar_timestamp(int timestamp, int& qtd) const{
    return this->timestamp.buscar(timestamp, qtd);
}

const int* IndiceReposicoes::buscar_id_produto(int id_produto,int& qtd) const{
    return this->id_produto.buscar(id_produto, qtd);
}