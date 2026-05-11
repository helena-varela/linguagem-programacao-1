#include <iostream>

// Atividade - Sistema de Reservas de Hotel
// Criar um sistema para cadastrar funcionários de uma empresa, onde cada funcionário recebe um ID único gerado
// automaticamente usando um atributo estático. Além disso, gere um struct utilitária Validador que terá um método 
// estático para validar o salário do novo funcionário e retorna true se válido e false se < 0.

class Funcionario {
private:
    static int contador;
    const int id;
    double salario;

public:
    Funcionario(double s) : id(++contador), salario(s) {
    }

    void exibir() const {
        std::cout << "ID: " << id << " | Salario: R$ " << salario << std::endl;
    }
};

struct Validador {
    static bool validarSalario(double s) {
        return s >= 0; 
    }
};

int Funcionario::contador = 0;

int main() {
    double novoSalario = 2500.50;

    if (Validador::validarSalario(novoSalario)) {
        Funcionario f1(novoSalario);
        Funcionario f2(3000.00);
        
        f1.exibir();
        f2.exibir();
    } else {
        std::cout << "Salario invalido!" << std::endl;
    }

    return 0;
}