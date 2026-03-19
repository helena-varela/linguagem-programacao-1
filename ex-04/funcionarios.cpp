#include <iostream>
#include <vector>
#include "funcoes.h"

using namespace std;

void cadastrarFuncionarios(vector<Funcionario>& funcionarios){
    cout << "Cadastrar funcionários" << endl;
    cout << "Quantos funcionários deseja cadastrar? " << endl;
    int quantidadeFuncionarios;
    cin >> quantidadeFuncionarios;

    for (int i = 0; i < quantidadeFuncionarios; i++)
    {
        Funcionario funcionario;
        cout << "Digite o nome do funcionário: " << endl;
        cin >> funcionario.nomeFuncionario;
        cout << "Digite o cargo do funcionário: " << endl;
        cin >> funcionario.cargo;

        funcionarios.push_back(funcionario);
    }
}

void exibirRelatorioFuncionario(const vector<Funcionario>& funcionarios){
    for (int i = 0; i < int(funcionarios.size()); i++)
    {
        cout << "Nome: " << funcionarios[i].nomeFuncionario << " Cargo: " << funcionarios[i].cargo << endl;
    }
}