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
    Compra* buscar_compra_por_id(int id);
    Reposicao* buscar_reposicao_por_id(int id);
    
    const int* listar_usuarios_por_cidade(const std::string& cidade, int &qtd_encontrada);
    const int* listar_usuarios_por_nome(const std::string& nome, int &qtd_encontrada);
    const int* listar_usuarios_por_idade(const int idade, int &qtd_encontrada);
    const int* listar_usuarios_por_estado(const std::string& estado, int &qtd_encontrada);
    const int* listar_usuarios_por_nacionalidade(const std::string& cidade, int &qtd_encontrada);

    const int* listar_produtos_por_nome(const std::string& nome, int &qtd_encontrada);
    const int* listar_produtos_por_categoria(const std::string& nome, int &qtd_encontrada);
    const int* listar_produtos_por_marca(const std::string& nome, int &qtd_encontrada);
    const int* listar_produtos_por_condicao(const std::string& nome, int &qtd_encontrada);
    
    const int* listar_compras_por_timestamp(int timestamp, int &qtd_encontrada);
    const int* listar_compras_por_id_usuario(int id_usuario, int &qtd_encontrada);
    const int* listar_compras_por_id_produto(int id_produto, int &qtd_encontrada);

    const int* listar_reposicoes_por_timestamp(int timestamp, int &qtd_encontrada);
    const int* listar_reposicoes_por_id_produto(int id_produto, int &qtd_encontrada);

    static int* intersectar(const int* v1, int qtd1, const int* v2, int qtd2, int& qtd_res);

    void imprimir_produtos_usuario(int id_usuario);
    void imprimir_compradores_do_produto(int id_produto);
    bool validar_e_registrar_compra(const Compra& c);
    void merge_sort(int* ids, int* qnts, int esquerda, int direita);
    void merge(int* ids, int* qnts, int esquerda, int meio, int direita);
};

#endif