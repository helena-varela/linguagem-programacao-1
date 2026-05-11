#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Personagem {
protected:
    string nome;
    float hp, hpMax;
    float mp, mpMax;

public:
    Personagem(string n, float h, float m) {
        nome = n;   
        hp = h;
        hpMax = h;
        mp = m;
        mpMax = m;
    }

    virtual ~Personagem() {}

    void recuperarTurno() {
        hp += hpMax * 0.10;
        mp += mpMax * 0.10;
        if (hp > hpMax) hp = hpMax;
        if (mp > mpMax) mp = mpMax;
        cout << "\n[Regeneracao] " << nome << " recuperou HP e MP!" << endl;
    }

    virtual void ataqueSimples() = 0;
    virtual void ataqueEspecial() = 0;

    bool estaVivo() { return hp > 0; }

    void mostrarStatus() {
        cout << nome << " -> HP: " << hp << "/" << hpMax << " | MP: " << mp << "/" << mpMax << endl;
    }

    void receberDano(float dano) {
        hp -= dano;
        if (hp < 0) hp = 0;
    }

    bool gastarMP(float porcentagem) {
        float custo = mpMax * porcentagem;
        if (mp >= custo) {
            mp -= custo;
            return true;
        }
        cout << "MP insuficiente!" << endl;
        return false;
    }
};

class Guerreiro : public Personagem {
public:
    Guerreiro(string n) : Personagem(n, 150, 50) {}

    void ataqueSimples() override {
        cout << nome << " atacou com a espada - 20 de dano" << endl;
    }
    void ataqueEspecial() override {
        if (gastarMP(0.15)) {
            cout << nome << " usou corte dimensional - 50 de dano" << endl;
        }
    }
};

class Mago : public Personagem {
public:
    Mago(string n) : Personagem(n, 80, 150) {}

    void ataqueSimples() override {
        cout << nome << " lancou uma magia - 15 de dano" << endl;
    }
    void ataqueEspecial() override {
        if (gastarMP(0.15)) {
            cout << nome << " lancou magia suprema - 60 de dano" << endl;
        }
    }
};

class Arqueiro : public Personagem {
public:
    Arqueiro(string n) : Personagem(n, 100, 80) {}

    void ataqueSimples() override {
        cout << nome << " lancou uma flecha -18 de dano" << endl;
    }
    void ataqueEspecial() override {
        if (gastarMP(0.15)) {
            cout << nome << " usou flecha perfurante - 45 de dano" << endl;
        }
    }
};

int main() {
    Personagem* player;
    int classe, acao;

    cout << "Escolha sua classe:\n1. Guerreiro\n2. Mago\n3. Arqueiro\nEscolha: ";
    cin >> classe;

    if (classe == 1) player = new Guerreiro("Thorin");
    else if (classe == 2) player = new Mago("Gandalf");
    else player = new Arqueiro("Legolas");

    while (player->estaVivo()) {
        player->mostrarStatus();
        player->recuperarTurno();

        cout << "\nSua vez:\n1. Ataque Simples\n2. Ataque Especial\n3. Parar de jogar\nEscolha: ";
        cin >> acao;

        if (acao == 1) player->ataqueSimples();
        else if (acao == 2) player->ataqueEspecial();
        else break;

        cout << "Um monstro te golpeou! (-30 HP)" << endl;
        player->receberDano(30);

        if (!player->estaVivo()) {
            cout << "\n--- VOCE MORREU! FIM DE JOGO ---" << endl;
        }
    }

    delete player;
    return 0;
}