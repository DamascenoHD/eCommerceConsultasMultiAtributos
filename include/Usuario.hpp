#ifndef USUARIO_HPP
#define USUARIO_HPP
#include <string>
class Usuario{
    private:
        int id;
        std::string nome;
        int idade;
        std::string estado;
        std::string nacionalidade;

    public:
        int get_id() const;
        int get_idade() const;
        std::string get_nacionalidade() const;
        std::string get_nome() const;
        std::string get_estado() const;

        void set_idade(int idade);
        void set_estado(const std::string& estado) ;
        void set_nome(const std::string& nome);
        void set_id(int id);
        void set_nacionalidade(const std::string& nacionalidade);
        
};


#endif