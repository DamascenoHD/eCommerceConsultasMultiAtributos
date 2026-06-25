#include "Usuario.hpp"

Usuario::Usuario()
    : id(0), idade(0)
{
}

Usuario::Usuario(int id,
                 int idade,
                 const std::string& nome,
                 const std::string& cidade,
                 const std::string& estado,
                 const std::string& nacionalidade)
    : id(id),
      idade(idade),
      nome(nome),
      cidade(cidade),
      estado(estado),
      nacionalidade(nacionalidade)
{
}

int Usuario::get_id() const{
    return id;
}
int Usuario::get_idade() const{
    return idade;
}
const std::string& Usuario::get_nome() const{
    return nome;
}
const std::string& Usuario::get_cidade() const{
    return cidade;
}
const std::string& Usuario::get_estado() const{
    return estado;
}
const std::string& Usuario::get_nacionalidade() const{
    return nacionalidade;
}
void Usuario::set_idade(int idade){
    this->idade = idade;
}
void Usuario::set_nome(const std::string& nome){
    this->nome = nome;
}
void Usuario::set_cidade(const std::string& cidade){
    this->cidade = cidade;
}
void Usuario::set_estado(const std::string& estado){
    this->estado = estado;
}
void Usuario::set_nacionalidade(const std::string& nacionalidade){
    this->nacionalidade = nacionalidade;
}
