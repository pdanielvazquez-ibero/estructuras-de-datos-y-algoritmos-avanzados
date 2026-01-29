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
    int buscado = 60;
    Nodo* lista = nullptr;
    insertarFinal(lista, 3);
    insertarFinal(lista, 10);
    insertarFinal(lista, 19);
    insertarFinal(lista, 31);
    insertarFinal(lista, 56);
    insertarFinal(lista, 80);
    mostrarLista(lista);
    cout << "Buscando: " << buscado << endl;
    Nodo* resultado = busquedaBinaria(lista, buscado);
    if (resultado)
        cout << "¡Fue encontrado! =)\n";
    else
        cout << "No encontrado =(\n";

    return 0;
}

Nodo* mitad(Nodo* inicio, Nodo* final) {
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
        Nodo* enMedio = mitad(inicio, final);

        if (enMedio == nullptr)
            return nullptr;

        if (enMedio->dato == buscado) {
            return enMedio; // encontrado
        }
        else if (enMedio->dato < buscado) {
            // buscar en la mitad derecha
            inicio = enMedio->siguiente;
        }
        else {
            // buscar en la mitad izquierda
            final = enMedio;
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