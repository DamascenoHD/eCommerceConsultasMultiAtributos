#ifndef INDICECOMPRAS_HPP
#define INDICECOMPRAS_HPP
#include "IndiceInvertido.hpp"
#include "Compra.hpp"
class IndiceCompras{
    private:
        IndiceInvertido timestamp;
        IndiceInvertido id_produto;
        IndiceInvertido id_usuario;

    public:
        IndiceCompras();
        void inserir_compra(const Compra& c);
        
        const int* buscar_timestamp(int timestamp,
                               int& qtd) const;
        const int* buscar_id_produto(int id_produto,
                               int& qtd) const;
        const int* buscar_id_usuario(int id_usuario,
                               int& qtd) const;

};

#endif