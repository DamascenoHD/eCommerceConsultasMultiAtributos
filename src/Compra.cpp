#include "Compra.hpp"

Compra::Compra(){
    id = -1;
    timestamp = -1;
    id_usuario = -1;
    tamanho = 0;
    capacidade = 10;
    id_produtos = new int[capacidade];
    qnt_produtos = new int[capacidade];
}
Compra::Compra(int id, int timestamp, int id_usuario){
    this->id = id;
    this->timestamp = timestamp;
    this->id_usuario = id_usuario;
    tamanho = 0;
    capacidade = 10;
    id_produtos = new int[capacidade];
    qnt_produtos = new int[capacidade];
}

Compra::~Compra(){
    delete[] id_produtos;
    delete[] qnt_produtos;
}
int Compra::get_id()const{
    return id;
}
int Compra::get_timestamp()const{
    return timestamp;
}
int Compra::get_id_usuario()const{
    return id_usuario;
}
int Compra::get_tamanho()const{
    return tamanho;
}
int* Compra::get_id_produtos()const{
    return id_produtos;
}
int* Compra::get_qnt_produtos()const{
    return qnt_produtos;
}

void Compra::adicionar_produto(int id_produto, int quantidade){
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

// Construtor de cópia
Compra::Compra(const Compra& outra) {
    id = outra.id;
    timestamp = outra.timestamp;
    id_usuario = outra.id_usuario;
    tamanho = outra.tamanho;
    capacidade = outra.capacidade;

    id_produtos = new int[capacidade];
    qnt_produtos = new int[capacidade];

    for (int i = 0; i < tamanho; i++) {
        id_produtos[i] = outra.id_produtos[i];
        qnt_produtos[i] = outra.qnt_produtos[i];
    }
}


// Operador de atribuição
Compra& Compra::operator=(const Compra& outra) {

    // evita autoatribuição
    if (this == &outra)
        return *this;

    // libera memória antiga
    delete[] id_produtos;
    delete[] qnt_produtos;

    id = outra.id;
    timestamp = outra.timestamp;
    id_usuario = outra.id_usuario;
    tamanho = outra.tamanho;
    capacidade = outra.capacidade;

    id_produtos = new int[capacidade];
    qnt_produtos = new int[capacidade];

    for (int i = 0; i < tamanho; i++) {
        id_produtos[i] = outra.id_produtos[i];
        qnt_produtos[i] = outra.qnt_produtos[i];
    }

    return *this;
}


