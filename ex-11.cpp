#include <iostream>

using namespace std;

// Sistema de Sessões de Usuário
// Implemente um sistema de login simples. Cada usuário do sistema tem um nome, login e senha. Ofereça ao usuário a 
// opção de logar, quando informada as credenciais certas, inicializar um sessão com o id da sessão e o usuário (imutáveis).
// Criar opções de alterar o nome e senha para o usuário, mas apenas se o usuário tiver um sessão em aberto, 
// caso não tenha, exibir a opção de login.

class Usuario{
    private:
        const int id;
        const string login;
        string nome;
        string senha;
    public:
        Usuario(int _id, string _nome, string _login, string _senha) 
        : id(_id), nome(_nome), login(_login), senha(_senha) {}

        // Getters (para podermos ler os dados)
        string getLogin() const { return login; }
        string getSenha() const { return senha; }
        
        // Setters (para alterar nome e senha)
        void setNome(string n) { nome = n; }
        void setSenha(string s) { senha = s; }
};

class Sessao {
private:
    static int contadorSessoes;    // Para gerar IDs de sessão únicos
    static Usuario* usuarioLogado; // Ponteiro para o usuário que está no sistema agora
    const int idSessao;            // ID desta sessão específica

public:
    // Construtor da sessão
    Sessao() : idSessao(++contadorSessoes) {}

    // Método Estático: Login (não precisa de objeto para tentar logar)
    static void abrirSessao(Usuario* u) {
        usuarioLogado = u;
        cout << "Sessao iniciada! Usuario: " << u->getLogin() << endl;
    }

    static Usuario* getUsuario() { return usuarioLogado; }
    
    static bool estaAtiva() { return usuarioLogado != nullptr; }
};

// Inicializando os estáticos
int Sessao::contadorSessoes = 0;
Usuario* Sessao::usuarioLogado = nullptr; // Começa como "ninguém logado"

int main() {
    // Criando um usuário de teste
    Usuario user1(1, "Fulano", "admin", "123");
    int escolha;

    while (true) { // Loop para o menu não fechar
        cout << "\n--- SISTEMA ---" << endl;
        if (!Sessao::estaAtiva()) {
            cout << "1 - Logar" << endl;
        } else {
            cout << "2 - Alterar Nome e Senha" << endl;
            cout << "3 - Sair" << endl;
        }
        cin >> escolha;

        if (escolha == 1 && !Sessao::estaAtiva()) {
            string l, s;
            cout << "Login: "; cin >> l;
            cout << "Senha: "; cin >> s;

            if (l == user1.getLogin() && s == user1.getSenha()) {
                Sessao::abrirSessao(&user1);
            } else {
                cout << "Credenciais invalidas!" << endl;
            }
        } 
        else if (escolha == 2 && Sessao::estaAtiva()) {
            string novoNome, novaSenha;
            cout << "Novo nome: "; cin >> novoNome;
            cout << "Nova senha: "; cin >> novaSenha;
            
            // Alterando os dados através da sessão
            Sessao::getUsuario()->setNome(novoNome);
            Sessao::getUsuario()->setSenha(novaSenha);
            cout << "Dados alterados com sucesso!" << endl;
        }
        else if (escolha == 3) break;
    }

    return 0;
}