#ifndef REPOSICAO_HPP
#define REPOSICAO_HPP
class Reposicao {
private:
    int id;
    int timestamp;
    int tamanho;//quantos elementos tem o vetor
    int capacidade;//para alocação dinâmica
    int* id_produtos;
    int* qnt_produtos;
    public:
        Reposicao();
        Reposicao(int id, int timestamp);
        ~Reposicao();
        int get_id()const;
        int get_timestamp()const;
        int get_tamanho()const;
        const int* get_id_produtos()const;
        const int* get_qnt_produtos()const;
        

        void adicionar_produto(int id_produto, int quantidade);

        Reposicao(const Reposicao& outra);
        Reposicao& operator=(const Reposicao& outra);

        void imprime_produtos();
};

#endif