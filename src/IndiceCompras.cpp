#include "IndiceCompras.hpp"

void IndiceCompras::inserir_compra(const Compra& c){
    timestamp.inserir(std::to_string(c.get_timestamp()), c.get_id());

    int total_produtos = c.get_tamanho();
    const int* vetor_ids_produtos = c.get_id_produtos();

    for(int i=0; i<total_produtos; ++i){
        int id_do_produto_atual = vetor_ids_produtos[i];

        id_produto.inserir(std::to_string(id_do_produto_atual), c.get_id());
    }
}

const int* IndiceCompras::buscar_timestamp(int timestamp, int& qtd) const{
    return this->timestamp.buscar(std::to_string(timestamp), qtd);
}
const int* IndiceCompras::buscar_id_produto(int id_produto, int& qtd) const{
    return this->id_produto.buscar(std::to_string(id_produto), qtd);
}
const int* IndiceCompras::buscar_id_usuario(int id_usuario, int& qtd) const{
    return this->id_usuario.buscar(std::to_string(id_usuario), qtd);
}

IndiceCompras::IndiceCompras() {

}