#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include <iomanip>
#include "Sistema.hpp"

using namespace std;

int main() {
    Sistema sistema;
    int id_usuario = 0;
    int id_produto = 0;
    int id_compra = 0;
    int id_reposicao = 0;
    std::string linha;
    while (std::getline(std::cin, linha)) {
        std::stringstream ss(linha);
        char tipo;
        if (!(ss >> tipo)) continue;
        if(tipo == 'U'){
            string nome, cidade, estado, nacionalidade;
            int idade;
            ss >> nome >> idade >> cidade >> estado >> nacionalidade;
            Usuario usuario = Usuario(id_usuario, idade, nome, cidade, estado, nacionalidade);
            sistema.cadastrar_usuario(usuario);
            cout << "U" << id_usuario << endl;
            id_usuario++;
            
        }else if(tipo == 'P'){
            string nome, categoria, marca, condicao;
            double preco;
            int qtd_inicial;
            ss >> nome >> preco >> qtd_inicial >> categoria >> marca >> condicao;
            Produto produto = Produto(id_produto, qtd_inicial, preco, nome, categoria, marca, condicao);
            sistema.cadastrar_produto(produto);
            cout << "P" << id_produto << endl;
            id_produto++;
        }else if(tipo == 'R'){
            int timestamp;
            ss >> timestamp;
            int id_produto_reposto, quantidade;
            Reposicao reposicao = Reposicao(id_reposicao, timestamp);
            while(ss >>id_produto_reposto >> quantidade){
                reposicao.adicionar_produto(id_produto_reposto, quantidade);
            }
            sistema.registrar_reposicao(reposicao);
            id_reposicao++;
        }else if(tipo=='C'){
            int timestamp, id_usuario_compra;
            ss >> timestamp >> id_usuario_compra;
            int id_produto_comprado, quantidade;
            Compra compra = Compra(id_compra,timestamp, id_usuario_compra);
            while(ss >>id_produto_comprado >> quantidade){
                compra.adicionar_produto(id_produto_comprado, quantidade);
            }
            sistema.registrar_compra(compra);
            id_compra++;
        }else if(tipo == 'L'){
            char subtipo;
            ss >> subtipo;
            if(subtipo == 'U'){
                string atributo, valor;
                const int* resultado_acumulado = nullptr;
                int qtd_acumulada = 0;
                bool precisa_liberar = false;
                while(ss >> atributo >> valor){
                    const int* ids_atual = nullptr;
                    int qtd_atual = 0;

                    if(atributo == "nome"){
                        ids_atual = sistema.listar_usuarios_por_nome(valor, qtd_atual);
                    }else if(atributo=="idade"){
                        int idade;
                        stringstream ss2(valor);
                        ss >> idade;
                        ids_atual = sistema.listar_usuarios_por_idade(idade, qtd_atual);
                    }else if(atributo=="cidade"){
                        ids_atual = sistema.listar_usuarios_por_cidade(valor, qtd_atual);
                    }else if(atributo=="estado"){
                        ids_atual = sistema.listar_usuarios_por_estado(valor, qtd_atual);
                    }else if(atributo=="nacionalidade"){
                        ids_atual = sistema.listar_usuarios_por_nacionalidade(valor, qtd_atual);
                    }
                    if(resultado_acumulado == nullptr){
                        resultado_acumulado = ids_atual;
                        qtd_acumulada = qtd_atual;
                    }else{
                        int qtd_nova = 0;
                    // Capturamos o novo vetor alocado com 'new' pela função intersectar
                    int* nova_intersecao = sistema.intersectar(
                        resultado_acumulado, qtd_acumulada, 
                        ids_atual, qtd_atual, 
                        qtd_nova
                    );

                    // Se o 'resultado_acumulado' antigo foi fruto de uma interseção prévia,
                    // precisamos deletá-lo para não vazar memória.
                    if(precisa_liberar){
                        delete[] resultado_acumulado;
                    }

                    // Atualizamos nossas variáveis para o próximo loop
                    resultado_acumulado = nova_intersecao;
                    qtd_acumulada = qtd_nova;
                    precisa_liberar = true; // Ag  
                    }
                }

                for(int i = 0; i < qtd_acumulada; i++){
                    Usuario *usuario = sistema.buscar_usuario_por_id(resultado_acumulado[i]);
                    cout << "LU resultado_" << i+1 << "usuario" << resultado_acumulado[i] << " " << usuario->get_nome() << " " << usuario->get_idade() << " " << usuario->get_cidade() << " " << usuario->get_estado() << " " << usuario->get_nacionalidade() << endl;
                }
                cout << endl;

                if(precisa_liberar && resultado_acumulado != nullptr){
                    delete[] resultado_acumulado;
                }
            }else if (subtipo == 'P'){

            }else if(subtipo == 'C'){
              
            }else if(subtipo == 'R'){
              
            }
        }

    }
}