#include "Produto.hpp"

Produto::Produto(){
    id = -1;
    qnt = 0;
    preco = 0;
    nome = "";
    categoria = "";
    marca = "";
    condicao = "";
}
Produto::Produto(int id,
    int qnt_inicial, 
    double preco, 
    const std::string& nome, 
    const std::string& categoria, 
    const std::string& marca, 
    const std::string& condicao){
    this->id = id;
    this->qnt = qnt_inicial;
    this->preco = preco;
    this->nome = nome;
    this->categoria = categoria;
    this->marca = marca;
    this->condicao = condicao;
}

int Produto::get_id()const{
    return id;
}
int Produto::get_qnt()const{
    return qnt;
}
double Produto::get_preco()const{
    return preco;
}
std::string Produto::get_nome()const{
    return nome;
}
std::string Produto::get_categoria()const{
    return categoria;
}
std::string Produto::get_marca()const{
    return marca;
}
std::string Produto::get_condicao()const{
    return condicao;
}
void Produto::set_qnt(int qnt){
    this->qnt = qnt;
}
void Produto::set_preco(double preco){
    this->preco = preco;
}
void Produto::set_nome(const std::string& nome){
    this->nome = nome;
}
void Produto::set_categoria(const std::string& categoria){
    this->categoria = categoria;
}
void Produto::set_marca(const std::string& marca){
    this->marca = marca;
}
void Produto::set_condicao(const std::string& condicao){
    this->condicao = condicao;
}

void Produto::adicionar_estoque(int qnt){
    this->qnt += qnt;
}
void Produto::remover_estoque(int qnt){
    if(this->qnt < qnt)
        this->qnt = 0;
    else
        this->qnt -= qnt;
}