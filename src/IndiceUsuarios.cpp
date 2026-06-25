#include "IndiceUsuarios.hpp"

void IndiceUsuarios::inserir_usuario(const Usuario& u){
    nome.inserir(u.get_nome(), u.get_id());
    idade.inserir(std::to_string(u.get_idade()), u.get_id());
    cidade.inserir(u.get_cidade(), u.get_id());
    estado.inserir(u.get_estado(), u.get_id());
    nacionalidade.inserir(u.get_nacionalidade(), u.get_id());
    
}

const int* IndiceUsuarios::buscar_nome(const std::string& nome, int& qtd){
    return this->nome.buscar(nome,qtd);
}

const int* IndiceUsuarios::buscar_cidade(const std::string& cidade, int& qtd){
    return this->cidade.buscar(cidade, qtd);
}

const int* IndiceUsuarios::buscar_estado(const std::string& estado, int& qtd){
    return this->estado.buscar(estado, qtd);
}

const int* IndiceUsuarios::buscar_idade(const std::string& idade, int& qtd){
    return this->
}

const int* IndiceUsuarios::buscar_nacionalidade(const std::string& nacionalidade, int& qtd){

}
