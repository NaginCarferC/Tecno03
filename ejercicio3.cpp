#include <iostream>

using namespace std;

class Nodo {
public:
    char operador;
    int valor;
    bool esOperador;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int val) {
        valor = val;
        operador = '\0';
        esOperador = false;
        izquierdo = nullptr;
        derecho = nullptr;
    }

    Nodo(char op, Nodo* izq, Nodo* der) {
        operador = op;
        valor = 0;
        esOperador = true;
        izquierdo = izq;
        derecho = der;
    }
};

class ArbolExpresion {
private:
    Nodo* raiz;

    int resolverNodo(Nodo* actual) {
        if (actual == nullptr) {
            return 0;
        }

        if (!actual->esOperador) {
            return actual->valor;
        }

        int valorIzq = resolverNodo(actual->izquierdo);
        int valorDer = resolverNodo(actual->derecho);

        if (actual->operador == '+') {
            return valorIzq + valorDer;
        }
        if (actual->operador == '*') {
            return valorIzq * valorDer;
        }

        return 0;
    }

    void liberarMemoria(Nodo* actual) {
        if (actual != nullptr) {
            liberarMemoria(actual->izquierdo);
            liberarMemoria(actual->derecho);
            delete actual;
        }
    }

public:
    ArbolExpresion(Nodo* r) {
        raiz = r;
    }

    ~ArbolExpresion() {
        liberarMemoria(raiz);
    }

    int calcularResultado() {
        return resolverNodo(raiz);
    }
};

int main() {
 
    Nodo* nodo54 = new Nodo(54);
    Nodo* nodo5 = new Nodo(5);
    Nodo* nodo34 = new Nodo(34);
    Nodo* nodo1 = new Nodo(1);
    Nodo* nodo2 = new Nodo(2);

    Nodo* mult1 = new Nodo('*', nodo5, nodo34);
    Nodo* mult2 = new Nodo('*', nodo1, nodo2);

    Nodo* sumaDerecha = new Nodo('+', mult1, mult2);
    Nodo* raiz = new Nodo('+', nodo54, sumaDerecha);

    ArbolExpresion arbol(raiz);

    cout << "Operacion: 54 + 5 * 34 + 1 * 2" << endl;
    cout << "Resultado: " << arbol.calcularResultado() << endl;

    return 0;
}
