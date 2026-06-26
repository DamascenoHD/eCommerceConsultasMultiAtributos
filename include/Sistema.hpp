#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "Usuario.hpp"
#include "Produto.hpp"
#include "Compra.hpp"
#include "Reposicao.hpp"
#include "IndiceUsuarios.hpp"
#include "IndiceProdutos.hpp"
#include "IndiceCompras.hpp"
#include "IndiceReposicoes.hpp"

class Sistema {
private:
    // Armazenamento principal dos dados (Alocação Dinâmica)
    Usuario* usuarios;
    int qtd_usuarios;
    int cap_usuarios;

    Produto* produtos;
    int qtd_produtos;
    int cap_produtos;

    Compra* compras;
    int qtd_compras;
    int cap_compras;

    Reposicao* reposicoes;
    int qtd_reposicoes;
    int cap_reposicoes;

    // Estruturas de busca (Índices)
    IndiceUsuarios idx_usuarios;
    IndiceProdutos idx_produtos;
    IndiceCompras idx_compras;
    IndiceReposicoes idx_reposicoes;

    // Métodos utilitários para gerenciar memória
    void redimensionar_usuarios();
    void redimensionar_produtos();
    void redimensionar_compras();
    void redimensionar_reposicoes();

public:
    Sistema();
    ~Sistema();

    // Regras de negócio principais
    void cadastrar_usuario(const Usuario& u);
    void cadastrar_produto(const Produto& p);
    
    // As operações de compra e reposição devem alterar o estoque dos produtos
    void registrar_compra(const Compra& c);
    void registrar_reposicao(const Reposicao& r);

    // Métodos de recuperação (Exemplos de como acessar usando IDs ou Índices)
    Usuario* buscar_usuario_por_id(int id);
    Produto* buscar_produto_por_id(int id);

    void listar_usuarios_por_nome(const std::string& nome);
    void listar_usuarios_por_idade(const int idade);
    void listar_usuarios_por_cidade(const std::string& cidade);
    void listar_usuarios_por_estado(const std::string& estado);
    void listar_usuarios_por_nacionalidade(const std::string& cidade);

    void listar_produtos_por_nome(const std::string& nome);
    void listar_produtos_por_categoria(const std::string& nome);
    void listar_produtos_por_marca(const std::string& nome);
    void listar_produtos_por_condicao(const std::string& nome);
    
    void listar_compras_por_timestamp(int timestamp);
    void listar_compras_por_id_usuario(int id_usuario);
    void listar_compras_por_id_produto(int id_produto);

    void listar_reposicoes_por_timestamp(int timestamp);
    void listar_reposicoes_por_id_produto(int id_produto);

    int intersectar_vetores(const int* v1, int qtd1, const int* v2, int qtd2, int* v_resultado);
};

#endif