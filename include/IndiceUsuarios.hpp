#ifndef INDICEUSUARIOS_HPP
#define INDICEUSUARIOS_HPP
#include "IndiceInvertido.hpp"
#include "Usuario.hpp"
class IndiceUsuarios {
        private:
                IndiceInvertido nome;
                IndiceInvertido idade;
                IndiceInvertido cidade;
                IndiceInvertido estado;
                IndiceInvertido nacionalidade;

        public:
                void inserir_usuario(const Usuario& u);

                const int* buscar_nome(
                        const std::string& nome,
                        int& qtd);

                const int* buscar_cidade(
                        const std::string& cidade,
                        int& qtd);

                const int* buscar_estado(
                        const std::string& estado,
                        int& qtd);

                const int* buscar_idade(
                        const std::string& idade,
                        int& qtd);

                const int* buscar_nacionalidade(
                        const std::string& nacionalidade,
                        int& qtd);
};

#endif