#include "Reposicao.hpp"
#include <iostream>
Reposicao::Reposicao(){
    id = -1;
    timestamp = -1;
    tamanho = 0;
    capacidade = 10;
    id_produtos = new int[capacidade];
    qnt_produtos = new int[capacidade];
}
Reposicao::Reposicao(int id, int timestamp){
    this->id = id;
    this->timestamp = timestamp;
    this->tamanho = 0;
    this->capacidade = 10;
    this->id_produtos = new int[capacidade];
    this->qnt_produtos = new int[capacidade];
}
Reposicao::~Reposicao(){
    delete[] id_produtos;
    delete[] qnt_produtos;
}
int Reposicao::get_id()const{
    return id;
}
int Reposicao::get_timestamp()const{
    return timestamp;
}
int Reposicao::get_tamanho()const{
    return tamanho;
}
const int* Reposicao::get_id_produtos()const{
    return id_produtos;
}
const int* Reposicao::get_qnt_produtos()const{
    return qnt_produtos;
}
void Reposicao::adicionar_produto(int id_produto, int quantidade){
   if(tamanho==capacidade){
        int *novo_id_produtos = new int[capacidade+10];
        int *novo_qnt_produtos = new int[capacidade+10];
        for(int i=0; i<tamanho; i++){
            novo_id_produtos[i] = id_produtos[i];
            novo_qnt_produtos[i] = qnt_produtos[i];
        }
        novo_id_produtos[tamanho] = id_produto;
        novo_qnt_produtos[tamanho] = quantidade;
        delete[] id_produtos;
        delete[] qnt_produtos;
        id_produtos = novo_id_produtos;
        qnt_produtos = novo_qnt_produtos;
        capacidade += 10;
    }else{
        id_produtos[tamanho] = id_produto;
        qnt_produtos[tamanho] = quantidade;
    }
    tamanho++;
}

Reposicao::Reposicao(const Reposicao& outra){
    id = outra.id;
    timestamp = outra.timestamp;
    tamanho = outra.tamanho;
    capacidade = outra.capacidade;

    id_produtos = new int[capacidade];
    qnt_produtos = new int[capacidade];

    for(int i = 0; i < tamanho; i++){
        id_produtos[i] = outra.id_produtos[i];
        qnt_produtos[i] = outra.qnt_produtos[i];
    }
}

Reposicao& Reposicao::operator=(const Reposicao& outra){

    if(this == &outra)
        return *this;

    delete[] id_produtos;
    delete[] qnt_produtos;

    id = outra.id;
    timestamp = outra.timestamp;
    tamanho = outra.tamanho;
    capacidade = outra.capacidade;

    id_produtos = new int[capacidade];
    qnt_produtos = new int[capacidade];

    for(int i = 0; i < tamanho; i++){
        id_produtos[i] = outra.id_produtos[i];
        qnt_produtos[i] = outra.qnt_produtos[i];
    }

    return *this;
}

void Reposicao::imprime_produtos(){
    for(int i = 0; i < tamanho; i++){
        std::cout << "produto_" << i + 1 << " " << id_produtos[i] << " " << qnt_produtos[i];
        
        // Só imprime o espaço separador se não for o último produto
        if (i < tamanho - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}