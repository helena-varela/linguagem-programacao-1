#include <iostream>
#include <string>

// primeira questão:
// A violação do Princípio da Substituição de Liskov (LSP) na imagem ocorre porque a classe CarroEletrico`[] quebra o 
// comportamento esperado da classe base ao lançar uma exceção no método abastecer, impedindo que o objeto "filho" 
// substitua o "pai" de forma segura na função prepararViagem. Como o princípio exige que as subclasses possam ser utilizadas 
// no lugar das superclasses sem interromper o funcionamento do sistema ou gerar comportamentos inesperados, o fato de o carro elétrico 
// recusar uma ação obrigatória da classe Carro prova que a hierarquia está mal projetada e que o contrato da classe base foi 
// desrespeitado.

using namespace std;

class Carro {
protected:

    string modelo;

public:
    Carro(string m) {
        modelo = m;
    }

    virtual ~Carro() {}
    
    void viajar() {
        cout << "Viajando com o " << modelo << endl;
    }
};

class CarroCombustao : public Carro {
public:
    CarroCombustao(string m) : Carro(m) {}
    
    void abastecer() {
        cout << modelo << " abastecido com gasolina" << endl;
    }
};

class CarroEletrico : public Carro {
public:
    CarroEletrico(string m) : Carro(m) {}
    
    void carregarBateria() {
        cout << modelo << " carregado na tomada" << endl;
    }
};

void prepararViagem(CarroCombustao& carro) {
    carro.abastecer();
    carro.viajar();
}

int main() {
    CarroCombustao meuSedan("Civic");
    CarroEletrico meuTesla("Model 3");

    prepararViagem(meuSedan);

    meuTesla.carregarBateria();
    meuTesla.viajar();

    return 0;
}