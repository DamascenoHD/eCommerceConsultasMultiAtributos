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
Compra* Sistema::buscar_compra_por_id(int id) {
    return &compras[id];
}
Reposicao* Sistema::buscar_reposicao_por_id(int id) {
    return &reposicoes[id];
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

const int* Sistema::listar_usuarios_por_cidade(const std::string& cidade, int &qtd_encontrada) {
    return idx_usuarios.buscar_cidade(cidade, qtd_encontrada);
}

const int* Sistema::listar_usuarios_por_nome(const std::string& nome, int &qtd_encontrada){
    return idx_usuarios.buscar_nome(nome, qtd_encontrada);
}

const int* Sistema::listar_usuarios_por_idade(const int idade, int &qtd_encontrada){
    return idx_usuarios.buscar_idade(std::to_string(idade), qtd_encontrada);
}

const int* Sistema::listar_usuarios_por_estado(const std::string& estado, int &qtd_encontrada){
    return idx_usuarios.buscar_estado(estado, qtd_encontrada);
}
const int* Sistema::listar_usuarios_por_nacionalidade(const std::string& nacionalidade, int &qtd_encontrada){
    return idx_usuarios.buscar_nacionalidade(nacionalidade, qtd_encontrada);
}

const int* Sistema::listar_produtos_por_nome(const std::string& nome, int &qtd_encontrada){
    return idx_produtos.buscar_nome(nome, qtd_encontrada);
}
const int* Sistema::listar_produtos_por_categoria(const std::string& categoria, int &qtd_encontrada){
    return idx_produtos.buscar_categoria(categoria, qtd_encontrada);
}
const int* Sistema::listar_produtos_por_marca(const std::string& marca, int &qtd_encontrada){
    return idx_produtos.buscar_marca(marca, qtd_encontrada);
}
const int* Sistema::listar_produtos_por_condicao(const std::string& condicao, int &qtd_encontrada){
    return idx_produtos.buscar_condicao(condicao, qtd_encontrada);
}

const int* Sistema::listar_compras_por_timestamp(int timestamp, int &qtd_encontrada){
    return idx_compras.buscar_timestamp(timestamp, qtd_encontrada);
}

const int* Sistema::listar_compras_por_id_usuario(int id_usuario, int &qtd_encontrada){
    return idx_compras.buscar_id_usuario(id_usuario, qtd_encontrada);
}

const int* Sistema::listar_compras_por_id_produto(int id_produto, int &qtd_encontrada){
    return idx_compras.buscar_id_produto(id_produto, qtd_encontrada);
}


const int* Sistema::listar_reposicoes_por_timestamp(int timestamp, int &qtd_encontrada){
    const int* ids = idx_reposicoes.buscar_timestamp(timestamp, qtd_encontrada);
    return ids;
}
const int* Sistema::listar_reposicoes_por_id_produto(int id_produto, int &qtd_encontrada){
    return idx_reposicoes.buscar_id_produto(id_produto, qtd_encontrada);
}

int* Sistema::intersectar(const int* v1, int qtd1, const int* v2, int qtd2, int& qtd_res) {
        // No pior caso, o tamanho da interseção é o tamanho do menor vetor
        int cap_max = (qtd1 < qtd2) ? qtd1 : qtd2;
        
        if (cap_max == 0 || v1 == nullptr || v2 == nullptr) {
            qtd_res = 0;
            return nullptr;
        }

        int* resultado_temporario = new int[cap_max];
        int i = 0, j = 0;
        qtd_res = 0;

        // Algoritmo de dois ponteiros (Aproveita a ordenação dos IDs)
        while (i < qtd1 && j < qtd2) {
            if (v1[i] == v2[j]) {
                resultado_temporario[qtd_res] = v1[i];
                qtd_res++;
                i++;
                j++;
            } else if (v1[i] < v2[j]) {
                i++;
            } else {
                j++;
            }
        }

        if (qtd_res == 0) {
            delete[] resultado_temporario;
            return nullptr;
        }

        // Ajusta o tamanho do vetor para o tamanho exato do resultado (opcional, mas boa prática)
        int* resultado_final = new int[qtd_res];
        for (int k = 0; k < qtd_res; k++) {
            resultado_final[k] = resultado_temporario[k];
        }

        delete[] resultado_temporario;
        return resultado_final;
}

void Sistema::imprimir_produtos_usuario(int id_usuario) {
    int qtd_compras = 0;
    //std::cout << "[DEBUG] To aqui. Buscando compras para usuario " << id_usuario << "\n";
    
    // 1. Busca todas as compras que esse usuário fez
    const int* ids_compras_usuario = idx_compras.buscar_id_usuario(id_usuario, qtd_compras);

    //std::cout << "[DEBUG] Quantidade de compras encontradas no indice: " << qtd_compras << "\n";

    // Se o usuário não tiver nenhuma compra, sai
    if (qtd_compras == 0 || ids_compras_usuario == nullptr) {
        //std::cout << "[DEBUG] Parou no passo 1: Indice de compras retornou 0 ou nulo.\n";
        return; 
    }

    // 2. Descobrir o tamanho máximo possível dos vetores
    int max_produtos_possiveis = 0;
    for (int i = 0; i < qtd_compras; i++) {
        int id_compra_atual = ids_compras_usuario[i];
        Compra* c = buscar_compra_por_id(id_compra_atual);
        
        if (c != nullptr) {
            //std::cout << "[DEBUG] Compra ID " << id_compra_atual << " encontrada. Tamanho de produtos nela: " << c->get_tamanho() << "\n";
            max_produtos_possiveis += c->get_tamanho();
        } else {
            //std::cout << "[DEBUG] ALERTA: Compra ID " << id_compra_atual << " retornou nullptr!\n";
        }
    }

    //std::cout << "[DEBUG] Maximo de produtos possiveis acumulados: " << max_produtos_possiveis << "\n";

    // Se o cálculo falhar ou o usuário tiver compras vazias
    if (max_produtos_possiveis == 0) {
        //std::cout << "[DEBUG] Parou no passo 2: O total de produtos em todas as compras resultou em 0.\n";
        return;
    }

    // ... (O RESTO DO SEU CÓDIGO CONTINUA IGUAL A PARTIR DAQUI) ...
    // 3. Alocar vetores para consolidar os dados
    int* produtos_unicos = new int[max_produtos_possiveis];
    int* quantidades_totais = new int[max_produtos_possiveis];
    int qtd_unicos = 0; 
    
    // ... [MANTENHA O SEU LAÇO FOR ORIGINAL AQUI] ...
    
    for (int i = 0; i < qtd_compras; i++) {
        Compra* c = buscar_compra_por_id(ids_compras_usuario[i]);
        if (c == nullptr) continue;

        int tam_compra = c->get_tamanho();
        int* prods = c->get_id_produtos();
        int* qnts = c->get_qnt_produtos();

        for (int j = 0; j < tam_compra; j++) {
            int id_p = prods[j];
            int qtd_p = qnts[j];

            bool ja_existe = false;
            for (int k = 0; k < qtd_unicos; k++) {
                if (produtos_unicos[k] == id_p) {
                    quantidades_totais[k] += qtd_p;
                    ja_existe = true;
                    break; 
                }
            }

            if (!ja_existe) {
                produtos_unicos[qtd_unicos] = id_p;
                quantidades_totais[qtd_unicos] = qtd_p;
                qtd_unicos++;
            }
        }
    }

    // 5. Imprime estritamente no formato exigido
    if (qtd_unicos > 0) {
        for (int i = 0; i < qtd_unicos; i++) {
            std::cout << "produto_" << (i + 1) << " " 
                      << produtos_unicos[i] << " " 
                      << quantidades_totais[i];
            
            if (i < qtd_unicos - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    delete[] produtos_unicos;
    delete[] quantidades_totais;
}

void Sistema::imprimir_compradores_do_produto(int id_produto) {
    int qtd_compras = 0;
    
    // 1. Busca todas as compras que contêm este produto específico usando o índice
    const int* ids_compras_produto = idx_compras.buscar_id_produto(id_produto, qtd_compras);

    // Se ninguém comprou o produto, não imprime a segunda linha
    if (qtd_compras == 0 || ids_compras_produto == nullptr) {
        return; 
    }

    // 2. Aloca vetores temporários para consolidar os compradores únicos
    // O pior caso (limite máximo) é se cada compra tiver sido feita por um usuário diferente
    int* usuarios_unicos = new int[qtd_compras];
    int* quantidades_totais = new int[qtd_compras];
    int qtd_unicos = 0;

    // 3. Varre as compras para consolidar quais usuários compraram e qual a quantidade acumulada
    for (int i = 0; i < qtd_compras; i++) {
        Compra* c = buscar_compra_por_id(ids_compras_produto[i]);
        if (c == nullptr) continue;

        int id_u = c->get_id_usuario();
        
        // Descobre a quantidade deste produto específico dentro desta compra
        int qtd_no_id = 0;
        int tam_compra = c->get_tamanho();
        int* prods = c->get_id_produtos();
        int* qnts = c->get_qnt_produtos();
        
        for (int j = 0; j < tam_compra; j++) {
            if (prods[j] == id_produto) {
                qtd_no_id = qnts[j];
                break;
            }
        }

        // Se por algum motivo o produto não estava na lista (segurança), pula
        if (qtd_no_id == 0) continue;

        // Verifica se este usuário já foi registrado no nosso vetor temporário
        bool ja_existe = false;
        for (int k = 0; k < qtd_unicos; k++) {
            if (usuarios_unicos[k] == id_u) {
                quantidades_totais[k] += qtd_no_id; // Usuário repetido: apenas acumula a quantidade
                ja_existe = true;
                break;
            }
        }

        // Se for um usuário novo para este produto, adiciona-o ao vetor
        if (!ja_existe) {
            usuarios_unicos[qtd_unicos] = id_u;
            quantidades_totais[qtd_unicos] = qtd_no_id;
            qtd_unicos++;
        }
    }

    // 4. Imprime estritamente no formato exigido:
    // usuario_1 <id_u1> <qtd_u1> ... usuario_M <id_uM> <qtd_uM>
    if (qtd_unicos > 0) {
        for (int i = 0; i < qtd_unicos; i++) {
            std::cout << "usuario_" << (i + 1) << " " 
                      << usuarios_unicos[i] << " " 
                      << quantidades_totais[i];
            
            // Adiciona espaço entre os blocos de usuários, mas não no final
            if (i < qtd_unicos - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl; // Quebra de linha obrigatória ao final da listagem
    }

    // 5. Liberação segura da memória alocada dinamicamente
    delete[] usuarios_unicos;
    delete[] quantidades_totais;
}

bool Sistema::validar_e_registrar_compra(const Compra& c) {
    int tamanho = c.get_tamanho();
    int* ids_produtos = c.get_id_produtos();
    int* qnts = c.get_qnt_produtos();

    // 1. Primeiro passo: Apenas verifica se TODOS têm estoque suficiente
    for (int i = 0; i < tamanho; i++) {
        Produto* p = buscar_produto_por_id(ids_produtos[i]);
        if (p == nullptr || p->get_qnt() < qnts[i]) {
            return false; // Estoque insuficiente ou produto não existe!
        }
    }

    // 2. Segundo passo: Se todos passaram na validação, realiza a compra
    if (qtd_compras == cap_compras) {
        redimensionar_compras();
    }
    compras[qtd_compras] = c;
    idx_compras.inserir_compra(c);

    // Decrementa o estoque de fato
    for (int i = 0; i < tamanho; i++) {
        Produto* p = buscar_produto_por_id(ids_produtos[i]);
        p->remover_estoque(qnts[i]);
    }

    qtd_compras++;
    return true; // Compra realizada com sucesso
}