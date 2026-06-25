#ifndef COMPRA_HPP
#define COMPRA_HPP
class Compra {
    private:
        int id;
        int timestamp;
        int id_usuario;
        int tamanho;//quantos elementos tem o vetor
        int capacidade;//para alocação dinâmica
        int* id_produtos;
        int* qnt_produtos;
    public:
        Compra();
        Compra(int id, 
            int timestamp, 
            int id_usuario);
        ~Compra();

        Compra(const Compra& outra);
        Compra& operator=(const Compra& outra);

        int get_id()const;
        int get_timestamp()const;
        int get_id_usuario()const;
        int get_tamanho()const;
        int* get_id_produtos()const;
        int* get_qnt_produtos()const;
        

        void adicionar_produto(int id_produto, int quantidade);


};  

#endif