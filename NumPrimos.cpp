#include <iostream>
using namespace std;

// Función para verificar si un número es primo
bool esPrimo(int numero) {
    if (numero <= 1) {
        return false;
    }
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int limite;

    // Solicitar al usuario el número límite
    cout << "Introduce un número límite: ";
    cin >> limite;
    
    cout << "Números primos hasta " << limite << ":" << endl;

    for (int i = 2; i <= limite; i++) {
        if (esPrimo(i)) {
            cout << i << " ";
        }
    }

    cout << endl;

    return 0;
}