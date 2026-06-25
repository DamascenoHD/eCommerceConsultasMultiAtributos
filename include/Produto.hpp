#ifndef PRODUTO_HPP
#define PRODUTO_HPP
#include <string>
class Produto{
    private:
        int id;
        int qnt;
        double preco;
        std::string nome;
        std::string categoria;
        std::string marca;
        std::string condicao;
    public:
        Produto();
        Produto(int id, int qnt_inicial, double preco, std::string nome, std::string categoria, std::string marca, std::string condicao);
        int get_id()const;
        int get_qnt()const;
        double get_preco()const;
        std::string get_nome()const;
        std::string get_categoria()const;
        std::string get_marca()const;
        std::string get_condicao()const;


        void set_id();
        void set_qnt();
        void set_preco();
        void set_nome();
        void set_categoria();
        void set_marca();
        void set_condicao();


};

#endif