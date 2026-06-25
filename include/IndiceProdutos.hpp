#ifndef INDICEPRODUTOS_HPP
#define INDICEPRODUTOS_HPP
#include "IndiceInvertido.hpp"
#include "Produto.hpp"
class IndiceProdutos{
    private:
        IndiceInvertido nome;
        IndiceInvertido categoria;
        IndiceInvertido marca;
        IndiceInvertido condicao;
    public:
        void inserir_produto(const Produto& p);

        const int* buscar_nome(const std::string& cidade, int& qnt);
        const int* buscar_categoria(const std::string& categoria, int& qnt);
        const int* buscar_marca(const std::string& marca, int& qnt);
        const int* buscar_condicao(const std::string& condicao, int& qnt);
    

};

#endif