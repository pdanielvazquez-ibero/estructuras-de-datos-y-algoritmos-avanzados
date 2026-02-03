# include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

Nodo* mitad(Nodo* inicio, Nodo* final);
Nodo* busquedaBinaria(Nodo* cabeza, int buscado);
void insertarFinal(Nodo *&cabeza, int valor);
void mostrarLista(Nodo *cabeza);

int main(){
    int buscado = 56;
    Nodo* lista = nullptr;
    insertarFinal(lista, 2);
    insertarFinal(lista, 9);
    insertarFinal(lista, 15);
    insertarFinal(lista, 22);
    insertarFinal(lista, 30);
    insertarFinal(lista, 56);
    insertarFinal(lista, 84);
    mostrarLista(lista);
    cout << "Buscando: " << buscado << endl;
    Nodo* resultado = busquedaBinaria(lista, buscado);
    if (resultado)
        cout << "¡Fue encontrado! =)\n";
    else
        cout << "No encontrado =(\n";

    return 0;
}

Nodo* buscaMitad(Nodo* inicio, Nodo* final) {
    if (inicio == nullptr) return nullptr;

    Nodo* lento = inicio;
    Nodo* rapido = inicio;

    while (rapido != final && rapido->siguiente != final) {
        rapido = rapido->siguiente->siguiente;
        lento = lento->siguiente;
    }

    return lento; // lento queda en el medio
}

Nodo* busquedaBinaria(Nodo* cabeza, int buscado) {
    Nodo* inicio = cabeza;
    Nodo* final = nullptr;

    while (inicio != final) {
        Nodo* mitad = buscaMitad(inicio, final);

        if (mitad == nullptr)
            return nullptr;

        if (mitad->dato == buscado) {
            return mitad; // encontrado
        }
        else if (mitad->dato < buscado) {
            // buscar en la mitad derecha
            inicio = mitad->siguiente;
        }
        else {
            // buscar en la mitad izquierda
            final = mitad;
        }
    }

    return nullptr; // no encontrado
}

void insertarFinal(Nodo *&cabeza, int valor)
{
    Nodo *nuevo = new Nodo{valor, nullptr};
    if (cabeza == nullptr)
    {
        cabeza = nuevo;
    }
    else
    {
        Nodo *actual = cabeza;
        while (actual->siguiente != nullptr)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

// Función para mostrar la lista
void mostrarLista(Nodo *cabeza)
{
    Nodo *actual = cabeza;
    while (actual != nullptr)
    {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL" << endl;
}