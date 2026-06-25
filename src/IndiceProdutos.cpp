#include "IndiceProdutos.hpp"

void IndiceProdutos::inserir_produto(const Produto& p){
    nome.inserir(p.get_nome(), p.get_id());
    categoria.inserir(p.get_categoria(), p.get_id());
    marca.inserir(p.get_marca(), p.get_id());
    condicao.inserir(p.get_condicao(), p.get_id());
}
const int* IndiceProdutos::buscar_nome(const std::string& nome, int& qnt){
    return this->nome.buscar(nome, qnt);
}
const int* IndiceProdutos::buscar_categoria(const std::string& categoria, int& qnt){
    return this->categoria.buscar(categoria, qnt);
}
const int* IndiceProdutos::buscar_marca(const std::string& marca, int& qnt){
    return this->marca.buscar(marca, qnt);
}
const int* IndiceProdutos::buscar_condicao(const std::string& condicao, int& qnt){
    return this->condicao.buscar(condicao, qnt);
}

