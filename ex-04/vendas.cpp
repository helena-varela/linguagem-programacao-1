#include <iostream>
#include <vector>
#include "funcoes.h"

using namespace std;

void cadastrarVendas(vector<Venda>& vendas){
    cout << "Cadastrar vendas" << endl;
    cout << "Quantas vendas deseja cadastrar? " << endl;
    int quantidadeVendas;
    cin >> quantidadeVendas;

    for (int i = 0; i < quantidadeVendas; i++)
    {
        Venda venda;
        cout << "Digite o nome do produto: " << endl;
        cin >> venda.nomeProduto;
        cout << "Digite a quantidade vendida: " << endl;
        cin >> venda.quantidadeVendida;
        cout << "Digite o valor unitário: " << endl;
        cin >> venda.valorUnitario;

        vendas.push_back(venda);
    }
}

void exibirRelatorioVenda(const std::vector<Venda>& vendas){
    if(vendas.empty()) {
        cout << "Nenhuma venda cadastrada." << endl;
        return;
    }

    for (int i = 0; i < int(vendas.size()); i++)
    {
        cout << "Produto: " << vendas[i].nomeProduto << ", Quantidade Vendida: " << vendas[i].quantidadeVendida << ", Valor Unitário: " << vendas[i].valorUnitario << endl;
    }
}