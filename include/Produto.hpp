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
        Produto(int id,
             int qnt_inicial,
             double preco, 
             const std::string& nome, 
             const std::string& categoria, 
             const std::string& marca, 
             const std::string& condicao);

        int get_id()const;
        int get_qnt()const;
        double get_preco()const;
        std::string get_nome()const;
        std::string get_categoria()const;
        std::string get_marca()const;
        std::string get_condicao()const;

        void set_qnt(int qnt);
        void set_preco(double preco);
        void set_nome(const std::string& nome);
        void set_categoria(const std::string& categoria);
        void set_marca(const std::string& marca);
        void set_condicao(const std::string& condicao);

        void adicionar_estoque(int qnt);
        void remover_estoque(int qnt);


};

#endif