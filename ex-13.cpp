#include <iostream>
#include <string>

using namespace std;

class Autenticacao {
public:
    virtual ~Autenticacao() {}

    void autenticar() {

        coletarDados();

        if (validarDados()) {
            iniciarSessao();

        } else {
            cout << "erro: dados inválidos, sua autenticação falhou :(" << endl;
        }
    }

    virtual void coletarDados() = 0;
    virtual bool validarDados() = 0;

    void iniciarSessao() {
        cout << "sessao iniciada no discord :)" << endl;
    }
};

class LoginSenha : public Autenticacao {
private:
    string login, senha;

public:
    void coletarDados() override {
        cout << "Digite o login: "; cin >> login;
        cout << "Digite a senha: "; cin >> senha;
    }

    bool validarDados() override {
        return (login.length() > 4 && senha.length() > 8);
    }
};

class GoogleAuth : public Autenticacao {
private:
    string email;

public:
    void coletarDados() override {
        cout << "Digite seu e-mail do Google: "; cin >> email;
    }

    bool validarDados() override {

        string final = "@gmail.com";

        if (email.length() >= final.length()) {
            return (email.compare(email.length() - final.length(), final.length(), final) == 0);
        }
        return false;
    }
};

class QRCodeAuth : public Autenticacao {
private:
    string codigo;

public:
    void coletarDados() override {
        cout << "Escaneie (digite) o QR Code: "; cin >> codigo;
    }

    bool validarDados() override {
        return (codigo == "QR12345");
    }
};

int main() {
    int opcao;
    cout << "Como deseja logar?\n1. Login/Senha\n2. Google\n3. QR Code\nEscolha: ";
    cin >> opcao;

    Autenticacao* auth = nullptr;

    if (opcao == 1) auth = new LoginSenha();
    else if (opcao == 2) auth = new GoogleAuth();
    else if (opcao == 3) auth = new QRCodeAuth();

    if (auth != nullptr) {
        auth->autenticar();
        delete auth;
    }

    return 0;
}