#ifndef TABELAHASH_HPP
#define TABELAHASH_HPP

#include <string>

class TabelaHash {
private:

    struct No {
        std::string chave;

        // vetor dinâmico de ids associados à chave
        int* ids;
        int tamanho;
        int capacidade;

        // próximo nó da lista encadeada
        No* prox;

        No(const std::string& chave);
        ~No();

        void adicionarId(int id);
    };

    // tabela hash propriamente dita
    No** tabela;

    // número de posições da tabela
    int capacidadeTabela;

    // quantidade de chaves armazenadas
    int quantidadeElementos;

    // fator de carga máximo permitido
    static constexpr double FATOR_CARGA_MAX = 0.75;

    // função hash
    int funcaoHash(const std::string& chave) const;

    // redimensiona o vetor interno de buckets
    void redimensionar();

    // retorna o próximo número primo >= n
    int proximoPrimo(int n) const;

    // verifica se um número é primo
    bool ehPrimo(int n) const;

public:

    // construtor
    TabelaHash(int capacidadeInicial = 101);

    // destrutor
    ~TabelaHash();

    // insere um id associado a uma chave
    void inserir(const std::string& chave,
                 int id);

    // busca os ids associados a uma chave
    // quantidade recebe o tamanho do vetor retornado
    const int* buscar(const std::string& chave,
                      int& quantidade) const;

    // verifica se uma chave existe
    bool contem(const std::string& chave) const;
};

#endif