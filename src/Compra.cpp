#include "Compra.hpp"
#include <iostream>
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

void Compra::imprime_produtos(){
     if (tamanho > 1) {
        merge_sort(id_produtos, qnt_produtos, 0, tamanho - 1);
    }
    for(int i = 0; i < tamanho; i++){
        std::cout << "produto_" << i + 1 << " " << id_produtos[i] << " " << qnt_produtos[i];
        
        // Só imprime o espaço separador se não for o último produto
        if (i < tamanho - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void Compra::merge(int* ids, int* qnts, int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;
    
    // Cria arrays temporários
    int* temp_ids_esq = new int[n1];
    int* temp_qnt_esq = new int[n1];
    int* temp_ids_dir = new int[n2];
    int* temp_qnt_dir = new int[n2];
    
    // Copia dados para os arrays temporários
    for (int i = 0; i < n1; i++) {
        temp_ids_esq[i] = ids[esquerda + i];
        temp_qnt_esq[i] = qnts[esquerda + i];
    }
    for (int j = 0; j < n2; j++) {
        temp_ids_dir[j] = ids[meio + 1 + j];
        temp_qnt_dir[j] = qnts[meio + 1 + j];
    }
    
    // Intercala os arrays temporários de volta para o array original
    int i = 0, j = 0, k = esquerda;
    while (i < n1 && j < n2) {
        if (temp_ids_esq[i] <= temp_ids_dir[j]) {
            ids[k] = temp_ids_esq[i];
            qnts[k] = temp_qnt_esq[i];
            i++;
        } else {
            ids[k] = temp_ids_dir[j];
            qnts[k] = temp_qnt_dir[j];
            j++;
        }
        k++;
    }
    
    // Copia os elementos restantes de temp_ids_esq (se houver)
    while (i < n1) {
        ids[k] = temp_ids_esq[i];
        qnts[k] = temp_qnt_esq[i];
        i++;
        k++;
    }
    
    // Copia os elementos restantes de temp_ids_dir (se houver)
    while (j < n2) {
        ids[k] = temp_ids_dir[j];
        qnts[k] = temp_qnt_dir[j];
        j++;
        k++;
    }
    
    // Libera memória temporária
    delete[] temp_ids_esq;
    delete[] temp_qnt_esq;
    delete[] temp_ids_dir;
    delete[] temp_qnt_dir;
}

// Função recursiva do Merge Sort
void Compra::merge_sort(int* ids, int* qnts, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        // Ordena a primeira e segunda metade
        merge_sort(ids, qnts, esquerda, meio);
        merge_sort(ids, qnts, meio + 1, direita);
        
        // Mescla as metades ordenadas
        merge(ids, qnts, esquerda, meio, direita);
    }
}
