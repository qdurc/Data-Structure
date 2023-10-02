#include <iostream>
using namespace std;

bool esPerfecto(int n){
    int perfecto = 0;

    for (int x = 1; x <= n / 2; x++){
        if (n % x == 0)
        {
            perfecto += x;
        }
    }
    return perfecto == n;
}

int main(){

    cout << "Números perfectos de menos de 4 cifras: " << endl;
    for (int i = 1; i < 1000; i++){
        if (esPerfecto(i))
        {
            cout << i << " ";
        }
    } 
    cout << endl;
    return 0;
}