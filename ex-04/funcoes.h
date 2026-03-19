#ifndef FUNCOES_H
#define FUNCOES_H

#include <vector>
#include "structs.h"

void exibirRelatorioVenda(const std::vector<Venda>& vendas);
void exibirRelatorioFuncionario(const std::vector<Funcionario>& funcionarios);

void cadastrarVendas(std::vector<Venda>& vendas);
void cadastrarFuncionarios(std::vector<Funcionario>& funcionarios);

#endif