#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class depositoNegativo : public exception {
public:
    depositoNegativo(const string& mensagem) : msg(mensagem) {}
    const char* what() const noexcept override {
        return msg.c_str();
    };
private:
    string msg;
};

class saqueMaior : public exception {
public:
    saqueMaior(const string& mensagem) : msg(mensagem) {}
    const char* what() const noexcept override {
        return msg.c_str();
    };
private:
    string msg;
};

int main(){
    int saldo = 0, deposito, saque;
    bool flag = true;
    int escolha;

    do
    {
        cout << "--- Conta Bancária ---" << endl;
        cout << "1 - Realizar depósito" << endl;
        cout << "2 - Realizar saque" << endl;
        cout << "3 - Verificar saldo" << endl;
        cout << "4 - Sair do aplicativo" << endl;
        cout << "-----------------------" << endl;
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            cout << "Qual valor que você deseja depositar na sua conta?" << endl;
            try
            {
                cin >> deposito;
                if (deposito < 0)
                {
                    throw depositoNegativo("Seu depósito não pode ser negativo");
                }
                saldo = saldo + deposito;
            }
            catch(const depositoNegativo& e)
            {
                cout << "Erro: " << e.what() << '\n';
            }
            
            break;
        case 2:
            cout << "Quanto você quer sacar da sua conta?" << endl;
            try{
                cin >> saque;
                if (saque > saldo)
                {
                    throw saqueMaior("Você está tentando sacar um valor maior que o seu saldo");
                }
            } catch(const saqueMaior& e){
                cout << "Erro: " << e.what() << '\n';
            }
            
            break;
        case 3:
            cout << "Seu saldo atual é: " << saldo << endl;
            break;
        case 4:
            flag = false;
        }

    } while (flag);
    
    return 0;
}