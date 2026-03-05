#include <iostream>
using namespace std;

int main(){
    int numero;
    int numero2;
    string operacao;

    cout << "Digite o primeiro numero: " << endl;
    cin >> numero;
    cout << "Digite o segundo numero: " << endl;
    cin >> numero2;
    cout << "Digite a operacao:\n1-Soma\n2-Subtracao\n3-Multiplicacao\n4-Divisao\n0-Sair" << endl;
    cin >> operacao;
    cout << "Resultado: " << endl;

    if(operacao == "1"){
        cout << numero + numero2 << endl;
    } else if(operacao == "2"){
        cout << numero - numero2 << endl;
    } else if(operacao == "3"){
        cout << numero * numero2 << endl;
    } else if(operacao == "4"){
        cout << numero / numero2 << endl;
    }
    else if(operacao == "0"){
        cout << "Encerrando o programa" << endl;
    }
    else if(numero2 == 0 && operacao == "4"){
        cout << "Nao e possivel dividir por zero" << endl;
    }

}