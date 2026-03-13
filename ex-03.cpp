#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Item{
    string nome;
    int quantidade;
    float valorUnitario;
};

struct Pedido{
    vector<Item> listaPedido;

    void adicionarItemAoPedido(Item item){
        listaPedido.push_back(item);
    }

    void calcularValorTotal(){
        float valorTotal = 0;
        for (int i = 0; i <= int(listaPedido.size()); i++){
            valorTotal += listaPedido[i].quantidade * listaPedido[i].valorUnitario;
        }
        cout << "Valor total do pedido:" << valorTotal << endl;
    }
    
};

struct Impressora{

    void imprimirTodosItens(Pedido pedido, string direcao = "retrato"){
        string resposta2;
        cout << "Deseja imprimir o pedido em modo paisagem? (s/n)" << endl;
        cin >> resposta2;

        if (resposta2 == "s")
        {
            direcao = "paisagem";
            cout << "Direção: " << direcao << endl;
        } else {
            cout << "Direção: " << direcao << endl;
        }

        cout << "Itens do pedido:" << endl;
        for (int i = 0; i < int(pedido.listaPedido.size()); ++i) {
            cout << "Nome: " << pedido.listaPedido[i].nome << ", Quantidade: " << pedido.listaPedido[i].quantidade << ", Valor Unitario: " << pedido.listaPedido[i].valorUnitario << endl; 
        }
    }

    void imprimirUmItem(Pedido pedido, string direcao = "retrato"){
        string nomeItem;
        cout << "Digite o nome do item que deseja imprimir: " << endl;
        cin >> nomeItem;

        string resposta2;
        cout << "Deseja imprimir o pedido em modo paisagem? (s/n)" << endl;
        cin >> resposta2;

        if (resposta2 == "s")
        {
            direcao = "paisagem";
            cout << "Direção: " << direcao << endl;
        } else {
            cout << "Direção: " << direcao << endl;
        }

        for (int i = 0; i < int(pedido.listaPedido.size()); ++i) {
            if (pedido.listaPedido[i].nome == nomeItem) {
                cout << "Nome: " << pedido.listaPedido[i].nome << ", Quantidade: " << pedido.listaPedido[i].quantidade << ", Valor Unitario: " << pedido.listaPedido[i].valorUnitario << endl;
                return;
            }
        }
        cout << "Item não encontrado." << endl;
    }
};

int main(){
    int qntdItens;
    cout << "Quantos itens você deseja pedir?" << endl;
    cin >> qntdItens;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Pedido pedido;

    for (int i = 0; i < qntdItens; i++){
        Item itens;
        
        cout << "Digite o nome do item: " << endl;
        getline(cin, itens.nome);
        
        cout << "Digite a quantidade do item: " << endl;
        cin >> itens.quantidade;

        cout << "Digite o valor unitario do item: " << endl;
        cin >> itens.valorUnitario;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        pedido.adicionarItemAoPedido(itens);
    }

    pedido.calcularValorTotal();

    Impressora impressora;

    string resposta;
    cout << "Você deseja imprimir todos os itens do pedido (1) ou deseja imprimir um item específico (2)? " << endl;
    cin >> resposta;    

    
    if (resposta == "1"){
        impressora.imprimirTodosItens(pedido);
    } else if (resposta == "2"){
        impressora.imprimirUmItem(pedido);
    }
}       