#include "TabelaHash.hpp"
#include <cmath>
#include <stdexcept>

// ==========================================
// Implementação da struct No (Interna)
// ==========================================

TabelaHash::No::No(const std::string& chave) 
    : chave(chave), tamanho(0), capacidade(2), prox(nullptr) {
    // Inicia com uma capacidade pequena para os IDs
    ids = new int[capacidade];
}

TabelaHash::No::~No() {
    delete[] ids;
}

void TabelaHash::No::adicionarId(int id) {
    // Se atingiu a capacidade do vetor, precisamos redimensioná-lo
    if (tamanho == capacidade) {
        capacidade *= 2;
        int* novosIds = new int[capacidade];
        
        for (int i = 0; i < tamanho; ++i) {
            novosIds[i] = ids[i];
        }
        
        delete[] ids;
        ids = novosIds;
    }
    ids[tamanho++] = id;
}

// ==========================================
// Métodos Privados da Tabela Hash
// ==========================================

bool TabelaHash::ehPrimo(int n) const {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int TabelaHash::proximoPrimo(int n) const {
    // Garante que não testaremos números pares
    if (n <= 2) return 2;
    if (n % 2 == 0) n++;
    
    while (!ehPrimo(n)) {
        n += 2;
    }
    return n;
}

int TabelaHash::funcaoHash(const std::string& chave) const {
    unsigned long hash = 5381; // Hash DJB2 
    for (char c : chave) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % capacidadeTabela;
}

void TabelaHash::redimensionar() {
    int novaCapacidade = proximoPrimo(capacidadeTabela * 2);
    No** novaTabela = new No*[novaCapacidade];
    
    // Inicializa a nova tabela com ponteiros nulos
    for (int i = 0; i < novaCapacidade; ++i) {
        novaTabela[i] = nullptr;
    }
    
    // Realoca todos os nós existentes na nova tabela
    for (int i = 0; i < capacidadeTabela; ++i) {
        No* atual = tabela[i];
        while (atual != nullptr) {
            No* proxNo = atual->prox; // Guarda o próximo nó
            
            // Recalcula o índice na nova tabela
            unsigned long hash = 5381;
            for (char c : atual->chave) {
                hash = ((hash << 5) + hash) + c;
            }
            int novoIndice = hash % novaCapacidade;
            
            // Insere no início da lista encadeada do novo bucket
            atual->prox = novaTabela[novoIndice];
            novaTabela[novoIndice] = atual;
            
            atual = proxNo; // Avança para o próximo da antiga tabela
        }
    }
    
    // Limpa o array destdexcept ponteiros antigo
    delete[] tabela;
    tabela = novaTabela;
    capacidadeTabela = novaCapacidade;
}

// ==========================================
// Métodos Públicos da Tabela Hash
// ==========================================

TabelaHash::TabelaHash(int capacidadeInicial) {
    capacidadeTabela = proximoPrimo(capacidadeInicial);
    quantidadeElementos = 0;
    
    tabela = new No*[capacidadeTabela];
    for (int i = 0; i < capacidadeTabela; ++i) {
        tabela[i] = nullptr;
    }
}

TabelaHash::~TabelaHash() {
    for (int i = 0; i < capacidadeTabela; ++i) {
        No* atual = tabela[i];
        while (atual != nullptr) {
            No* temp = atual;
            atual = atual->prox;
            delete temp; 
        }
    }
    delete[] tabela;
}

void TabelaHash::inserir(const std::string& chave, int id) {
    int indice = funcaoHash(chave);
    
    // Busca na lista encadeada daquela posição
    No* atual = tabela[indice];
    while (atual != nullptr) {
        if (atual->chave == chave) {
            // Chave já existe, adicionamos o novo ID ao vetor
            atual->adicionarId(id);
            return;
        }
        atual = atual->prox;
    }
    
    // Se a chave não existe, criamos um novo nó
    No* novoNo = new No(chave);
    novoNo->adicionarId(id);
    
    // Insere no início da lista encadeada
    novoNo->prox = tabela[indice];
    tabela[indice] = novoNo;
    
    quantidadeElementos++;
    
    // Verifica se precisa redimensionar a tabela
    double fatorCargaAtual = static_cast<double>(quantidadeElementos) / capacidadeTabela;
    if (fatorCargaAtual > FATOR_CARGA_MAX) {
        redimensionar();
    }
}

const int* TabelaHash::buscar(const std::string& chave, int& quantidade) const {
    int indice = funcaoHash(chave);
    
    No* atual = tabela[indice];
    while (atual != nullptr) {
        if (atual->chave == chave) {
            quantidade = atual->tamanho;
            return atual->ids;
        }
        atual = atual->prox;
    }
    
    // Chave não encontrada
    quantidade = 0;
    return nullptr;
}

bool TabelaHash::contem(const std::string& chave) const {
    int indice = funcaoHash(chave);
    
    No* atual = tabela[indice];
    while (atual != nullptr) {
        if (atual->chave == chave) {
            return true;
        }
        atual = atual->prox;
    }
    return false;
}