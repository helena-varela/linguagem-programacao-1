#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Corredores{
    int id;
    string nome;
    float tempoCorridaSegundos;

    bool operator<(const Corredores& outro) const {
    if (tempoCorridaSegundos != outro.tempoCorridaSegundos) {
        return tempoCorridaSegundos < outro.tempoCorridaSegundos;
    }
    return id < outro.id;
}
};

void relatorio(const set<Corredores>& corredores) {
    double soma = 0;
    cout << "\n--- RELATORIO DE CORREDORES --" << endl;
    for (const auto& c : corredores) {
        cout << "Nome: " << c.nome << " | Tempo: " << c.tempoCorridaSegundos << "s" << endl;
        soma += c.tempoCorridaSegundos;
    }
}

void tempoMedioCorredores(set<Corredores>& corredores){
    int somaTempos = 0;
    for (const auto& corredor : corredores) {
        somaTempos += corredor.tempoCorridaSegundos;
    }
    int tempoMedio =somaTempos / 3;
    cout << "\nO tempo médio dos corredores, em segundos, foi " << tempoMedio << endl;
}

int main(){
    set<Corredores> corredores;

    for (int i = 0; i < 3; i++)
    {
        Corredores corredor;
        cout << "Digite o id do corredor: ";
        cin >> corredor.id;
        cout << "Digite o nome do corredor: ";
        cin >> corredor.nome;
        cout << "Digite o tempo de corrida em segundos: ";
        cin >> corredor.tempoCorridaSegundos;
        corredores.insert(corredor);
    }

    relatorio(corredores);

    cout << "\n--- Ranking Final ---" << endl;
    for (const auto& c : corredores) {
        cout << c.nome << " - " << c.tempoCorridaSegundos << "s" << endl;
    }

    tempoMedioCorredores(corredores);

    return 0;
}