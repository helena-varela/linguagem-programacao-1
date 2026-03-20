#include <iostream>
using namespace std;

int fibonacci(int n){
    if( n == 0 || n == 1){
        return n;
    }
    else{
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(){
    int numero;
    cout << "Digite um número inteiro:" << endl;
    cin >> numero;

    int resultado = fibonacci(numero);
    cout << "O número de Fibonacci correspondente é: " << resultado << endl;
    
    return 0;
}