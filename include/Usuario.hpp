#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>

class Usuario {
private:
    int id;
    int idade;

    std::string nome;
    std::string cidade;
    std::string estado;
    std::string nacionalidade;

public:
    Usuario();

    Usuario(int id,
             int idade,
             const std::string& nome,
             const std::string& cidade,
             const std::string& estado,
             const std::string& nacionalidade);

    int get_id() const;
    int get_idade() const;

    const std::string& get_nome() const;
    const std::string& get_cidade() const;
    const std::string& get_estado() const;
    const std::string& get_nacionalidade() const;

    void set_idade(int idade);

    void set_nome(const std::string& nome);
    void set_cidade(const std::string& cidade);
    void set_estado(const std::string& estado);
    void set_nacionalidade(const std::string& nacionalidade);
};

#endif