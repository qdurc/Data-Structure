/*
A. El juego tiene 3 torres, nombradas A, B y C y n anillos concéntricos ordenados de mayor
diámetro a menor diámetro. ✅

B. Al iniciar se tiene un conjunto de al menos 3 anillos colocados en forma descendente,
pues cada anillo está a su vez encima de otro más grande. ✅

C. Nunca un anillo más grande debe estar encima de uno más pequeño, es decir, de mayor
diámetro va encima de otro con diámetro menor. ✅

D. Debe realizar los movimientos de los anillos hasta que haya traslado los anillos de una
torre X a una torre Y. ✅
*/

#include <iostream>
using namespace std;

void getDisks();
void play(int n, char torre1, char torre2, char torre3);
int readInt();
int totalMoves = 0;

void getDisks() {
    int totalDiscos;
    cout << "Ingrese el número de discos: ";
    totalDiscos = readInt();
    cout << endl;
    cout << "Resolviendo Torres de Hanoi con " << totalDiscos << " discos" << endl;
    play(totalDiscos , 'A', 'B', 'C');
}

void play(int n, char torre1, char torre2, char torre3) {
    if (n == 1) {
        cout << "Se mueve anillo 1 de torre " << torre1 << " a torre " << torre3 << endl;
        totalMoves++;
        return;
    }
    play(n - 1, torre1, torre3, torre2);
    cout << "Se mueve anillo " << n << " de torre " << torre1 << " a torre " << torre3 << endl;
    totalMoves++;
    play(n - 1, torre2, torre1, torre3);
}

int readInt() {
    int value;
    while (!(cin >> value)) {
        cout << "Ingrese un valor válido: ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    return value;
}

int main(){
    char torre1 = 'A', torre2 = 'B', torre3 = 'C', n = 0;
    bool menu = true;

    while (menu) {
        cout << "----- Torres de Hanoi ----- \n" << "Seleccione una opción: " << endl;
        cout << "1. Resolver Torres de Hanoi" << endl;
        cout << "2. Salir" << endl;
        cout << "Opción: ";
        int option = readInt();
        cout << endl;

        switch (option){
            case 1:
                getDisks();
                cout << "Total de movimientos: " << totalMoves << endl;
                break;
            case 2:
                cout << "Saliendo del programa...\n";
                menu = false;
                break;
        }
        cout << endl;
        totalMoves = 0;
    }
}