#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Produto{
    private:
        string nome;
        double preco;

    public:

    Produto(string n, double p) {
        nome = n;
        preco = p;
    }

    void exibirInformacoes() {
        cout << "Produto: " << nome << "\nPreco: R$ " << preco << endl;
    }
};

class ProdutoLimpeza : public Produto {
private:
    string tipoUso;

public:
    ProdutoLimpeza(string n, double p, string tipo) : Produto(n, p) {
        tipoUso = tipo;
    }

    void exibirTudo() {
        exibirInformacoes();
        cout << "\nUso: " << tipoUso << endl;
    }
};

class ProdutoAlimenticio : public Produto {
private:
    string validade;

public:
    ProdutoAlimenticio(string n, double p, string val) : Produto(n, p), validade(val) {}

    void exibirTudo() {
        exibirInformacoes();
        cout << "\nValidade: " << validade << endl;
    }
};

class ProdutoEletronico : public Produto {
private:
    int voltagem;
    int garantiaMeses;

public:
    ProdutoEletronico(string n, double p, int v, int g) : Produto(n, p), voltagem(v), garantiaMeses(g) {}

    void exibirTudo() {
        exibirInformacoes();
        cout << "\nVoltagem: " << voltagem << "V\nGarantia: " << garantiaMeses << " meses" << endl;
    }
};

int main(){
    vector<Produto*> listaProdutos;
    
    int opcao = 0;

    while (opcao != 5) {
        cout << "\nEscolha uma opção" << endl;
        cout << "1. Cadastrar Limpeza\n2. Cadastrar Alimento\n3. Cadastrar Eletronico\n4. Exibir Todos (Dados Gerais)\n5. Sair\nEscolha: ";
        cin >> opcao;

        if (opcao >= 1 && opcao <= 3) {
            string nome;
            double preco;
            cout << "Nome: "; cin >> nome;
            cout << "Preco: "; cin >> preco;

            if (opcao == 1) {
                string tipo; cout << "Tipo de uso: "; cin >> tipo;
                listaProdutos.push_back(new ProdutoLimpeza(nome, preco, tipo));
            } 
            else if (opcao == 2) {
                string val; cout << "Validade: "; cin >> val;
                listaProdutos.push_back(new ProdutoAlimenticio(nome, preco, val));
            } 
            else if (opcao == 3) {
                int volt, gar; 
                cout << "Voltagem: "; cin >> volt;
                cout << "Meses de Garantia: "; cin >> gar; 
                listaProdutos.push_back(new ProdutoEletronico(nome, preco, volt, gar));
            }
            cout << "Produto cadastrado com sucesso!" << endl;
        } 
        else if (opcao == 4) {
            cout << "\nListagem geral:" << endl;
            for (size_t i = 0; i < listaProdutos.size(); i++) {
                listaProdutos[i]->exibirInformacoes();
            }
        }
    }

    return 0;
}