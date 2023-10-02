#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Numero de terminos de Fibonacci: ";
    cin >> n;

    int a = 1, b = 0, aux;
    for (int i = 0; i < n; i++){
        // 1 + 0
        aux = a + b;
        // a = 0 
        a = b;
        // b = 1
        b = aux;
        cout << aux << endl;
    }
    return 0;
}
