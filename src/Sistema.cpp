#include "Sistema.hpp"
#include <iostream>

// --- CONSTRUTOR ---
Sistema::Sistema() {
    cap_usuarios = 10;
    qtd_usuarios = 0;
    usuarios = new Usuario[cap_usuarios];

    cap_produtos = 10;
    qtd_produtos = 0;
    produtos = new Produto[cap_produtos];

    cap_compras = 10;
    qtd_compras = 0;
    compras = new Compra[cap_compras];

    cap_reposicoes = 10;
    qtd_reposicoes = 0;
    reposicoes = new Reposicao[cap_reposicoes];
}

// --- DESTRUTOR ---
Sistema::~Sistema() {
    delete[] usuarios;
    delete[] produtos;
    delete[] compras;
    delete[] reposicoes;
}

// --- MÉTODOS DE REDIMENSIONAMENTO ---
void Sistema::redimensionar_usuarios() {
    cap_usuarios *= 2;
    Usuario* novo_vetor = new Usuario[cap_usuarios];
    for (int i = 0; i < qtd_usuarios; i++) {
        novo_vetor[i] = usuarios[i];
    }
    delete[] usuarios;
    usuarios = novo_vetor;
}

void Sistema::redimensionar_produtos() {
    cap_produtos *= 2;
    Produto* novo_vetor = new Produto[cap_produtos];
    for (int i = 0; i < qtd_produtos; i++) {
        novo_vetor[i] = produtos[i];
    }
    delete[] produtos;
    produtos = novo_vetor;
}

void Sistema::redimensionar_compras() {
    cap_compras *= 2;
    Compra* novo_vetor = new Compra[cap_compras];
    for (int i = 0; i < qtd_compras; i++) {
        novo_vetor[i] = compras[i];
    }
    delete[] compras;
    compras = novo_vetor;
}

void Sistema::redimensionar_reposicoes() {
    cap_reposicoes *= 2;
    Reposicao* novo_vetor = new Reposicao[cap_reposicoes];
    for (int i = 0; i < qtd_reposicoes; i++) {
        novo_vetor[i] = reposicoes[i];
    }
    delete[] reposicoes;
    reposicoes = novo_vetor;
}


Usuario* Sistema::buscar_usuario_por_id(int id) {
    
    return &usuarios[id];
}

Produto* Sistema::buscar_produto_por_id(int id) {
    return &produtos[id];
}



void Sistema::cadastrar_usuario(const Usuario& u) {
    if (qtd_usuarios == cap_usuarios) {
        redimensionar_usuarios();
    }
    usuarios[qtd_usuarios] = u;
    
    idx_usuarios.inserir_usuario(u);
    
    qtd_usuarios++;
}

void Sistema::cadastrar_produto(const Produto& p) {
    if (qtd_produtos == cap_produtos) {
        redimensionar_produtos();
    }
    produtos[qtd_produtos] = p;
    
    idx_produtos.inserir_produto(p);
    
    qtd_produtos++;
}

void Sistema::registrar_compra(const Compra& c) {
    if (qtd_compras == cap_compras) {
        redimensionar_compras();
    }
    compras[qtd_compras] = c;
    
    idx_compras.inserir_compra(c);
    
    int tamanho = c.get_tamanho();
    int* ids_produtos = c.get_id_produtos();
    int* qnts = c.get_qnt_produtos();
    
    for(int i = 0; i < tamanho; i++) {
        Produto* p = buscar_produto_por_id(ids_produtos[i]);
        if(p != nullptr) {
            p->remover_estoque(qnts[i]);
        }
    }
    
    qtd_compras++;
}

void Sistema::registrar_reposicao(const Reposicao& r) {
    if (qtd_reposicoes == cap_reposicoes) {
        redimensionar_reposicoes();
    }
    reposicoes[qtd_reposicoes] = r;
    
    // Atualiza os índices de reposições
    idx_reposicoes.inserir_reposicao(r);
    
    // REGRA DE NEGÓCIO: Aumentar estoque dos produtos repostos
    int tamanho = r.get_tamanho();
    const int* ids_produtos = r.get_id_produtos();
    const int* qnts = r.get_qnt_produtos();
    
    for(int i = 0; i < tamanho; i++) {
        Produto* p = buscar_produto_por_id(ids_produtos[i]);
        if(p != nullptr) {
            p->adicionar_estoque(qnts[i]);
        }
    }
    
    qtd_reposicoes++;
}

void Sistema::listar_usuarios_por_cidade(const std::string& cidade) {
    int qtd_encontrada = 0;
    
    // 1. O Índice Invertido busca na TabelaHash e devolve o vetor de IDs em O(1)
    const int* ids = idx_usuarios.buscar_cidade(cidade, qtd_encontrada);

    if (ids == nullptr || qtd_encontrada == 0) {
        std::cout << "Nenhum usuário encontrado em: " << cidade << "\n";
        return;
    }

    // 2. Usamos os IDs para acessar DIRETAMENTE os usuários na memória
    std::cout << "Usuários em " << cidade << ":\n";
    for (int i = 0; i < qtd_encontrada; i++) {
        int id_usuario = ids[i];
        Usuario* u = buscar_usuario_por_id(id_usuario); // O(1)
        
        if (u != nullptr) {
            std::cout << "- " << u->get_nome() << " (ID: " << u->get_id() << ")\n";
        }
    }
}