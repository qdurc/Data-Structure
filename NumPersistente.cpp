#include <iostream>
using namespace std;

// Función para calcular la persistencia de un número
int calcularPersistencia(int numero) {
    int persistencia = 0;
    while (numero >= 10) {
        int producto = 1;
        while (numero > 0) {
            producto *= numero % 10;
            numero /= 10;
        }
        numero = producto;
        persistencia++;
    }
    return persistencia;
}

int main() {    
    int numero;
    int persistenciaObjetivo = 3; // Persistencia mayor que 3

    do {
        numero = rand() % 100; // Generar números aleatorios de 3 dígitos
    } while (calcularPersistencia(numero) <= persistenciaObjetivo);

    cout << "Único número con persistencia mayor que 3: " << numero << endl;
    //cout << "Persistencia: " << calcularPersistencia(numero) << endl;

    return 0;
}