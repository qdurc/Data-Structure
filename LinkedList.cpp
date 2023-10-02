#include <iostream>
#include <limits>
using namespace std;

// Definición de una estructura para un nodo de la lista enlazada.
struct linkedList {
    int dato;           // Valor almacenado en el nodo.
    linkedList* next;   // Puntero al siguiente nodo.
};

// Función que verifica si la lista está vacía.
bool empty(linkedList* lista){
    return (lista == NULL);
}

// Función para validar la entrada de un número entero desde el usuario.
int validarEntradaEntero(){
    int numero;
    bool esNumero = false;

    while(!esNumero) {
        // Intenta leer un número entero.
        if (!(cin >> numero)) {
            cout << "<\nIntroduzca una entrada valida, por favor: ";
            cin.clear();  // Limpia el error del stream.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta la entrada incorrecta.
        } else {
            esNumero = true;
        }
    }
    return numero;
}

// Función para insertar un elemento en la lista en orden ascendente.
void insertarElemento(linkedList*& lista, int n){
    linkedList* nuevoNodo = new linkedList();
    nuevoNodo->dato = n;

    linkedList* aux1 = lista;
    linkedList* aux2;

    while((!empty(aux1)) && (aux1->dato < n)){
        aux2 = aux1;
        aux1 = aux1->next;
    }

    if(lista == aux1){
        lista = nuevoNodo;
    } else{
        aux2->next = nuevoNodo;
    }

    nuevoNodo->next = aux1;

    cout << "\nElemento " << n << " insertado exitosamente." << endl;
}

// Función para buscar un elemento en la lista y mostrar su posición.
void buscarElemento(linkedList* lista, int n){
    bool existe = false;

    linkedList * actual = lista;

    int contador = 0;
    while((!empty(actual))){
        contador++;
        if(actual->dato == n){
            existe = true;
            cout << "\nEl elemento " << n << " se encontro en la posicion " << contador << "." << endl;
        }
        actual = actual->next;
    }
    if(existe == false){
        cout << "\nEl elemento " << n << " no existe en la lista." << endl;
    }
}

// Función para eliminar un elemento de la lista.
void eliminarElemento(linkedList*& lista, int n){
    linkedList* auxBorrar = lista;
    linkedList* anterior = NULL;

    while((!empty(auxBorrar)) && (auxBorrar->dato != n)){
        anterior = auxBorrar;
        auxBorrar = auxBorrar->next;
    }
    if(empty(auxBorrar)){
        cout << "\nEl elemento no existe en la lista." << endl;
    } else if(anterior == NULL){
        lista = lista->next;
        cout << "\nSe elimino el elemento " << n << " exitosamente de la lista." << endl;
        delete auxBorrar;
    } else {
        anterior->next = auxBorrar->next;
        cout << "\nSe elimino el elemento " << n << " exitosamente de la lista." << endl;
        delete auxBorrar;
    }
}

// Función para mostrar todos los elementos de la lista.
void mostrarLinkedList(linkedList* lista){
    linkedList* actual = lista;

    while(!empty(actual)){
        cout << actual->dato << " -> ";
        actual = actual->next;
    }
    cout << "NULL\n";
}

// Función para insertar un elemento en la lista a través de la interacción con el usuario.
void insertarElementoLista(linkedList*& lista){
    int numero;
    cout << "\nInserte el elemento que desea ingresar a la lista:";
    numero = validarEntradaEntero();
    insertarElemento(lista, numero);
}

// Función para buscar un elemento en la lista a través de la interacción con el usuario.
void buscarElementoLista(linkedList*& lista){
    int numero;
    if(!empty(lista)){
        cout << "\nInserte el elemento que desea buscar en la lista:";
        numero = validarEntradaEntero();
        buscarElemento(lista, numero);
    } else {
        cout << "\nLa lista esta vacia." << endl;
    }
}

// Función para eliminar un elemento de la lista a través de la interacción con el usuario.
void eliminarElementoLista(linkedList*& lista){
    int numero;
    if(!empty(lista)){
        cout << "\nIngrese el elemento que desea eliminar de la lista: ";
        numero = validarEntradaEntero();
        eliminarElemento(lista, numero);
    } else{
        cout << "\nLa lista esta vacia." << endl;
    }
}

// Función para mostrar todos los elementos de la lista a través de la interacción con el usuario.
void mostrarElementosLista(linkedList*& lista){
    if(!empty(lista)){
        cout << "\nLos elementos de la lista son los siguientes: ";
        mostrarLinkedList(lista);
    } else{
        cout << "\nLa lista esta vacia." << endl;
    }
}

int main() {
    linkedList* lista = NULL;
    bool ejecucion = false; // Bandera para controlar el bucle del menú.
    int opcion;            // Opción seleccionada por el usuario en el menú.
    while(!ejecucion){
        cout << "\n///////////////////////////////////////////////////" << endl;
        cout << "Seleccione la opcion que desea realizar con la lista:" << endl;
        cout << "1. Insertar elemento dentro a la lista. \n2. Buscar elemento dentro de la lista. \n3. Eliminar elemento dentro de la lista. \n4. Ver elementos dentro de la lista. \n5. Salir." << endl;
        opcion = validarEntradaEntero();
        switch (opcion) {
            case 1:
                insertarElementoLista(lista);
                break;
            case 2:
                buscarElementoLista(lista);
                break;
            case 3:
                eliminarElementoLista(lista);
                break;
            case 4:
                mostrarElementosLista(lista);
                break;
            case 5:
                ejecucion = true;
                break;
            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
    }
    return 0;
}