#include <iostream>
using namespace std;
#include "arreglo.hpp"
#include "personaje.hpp"

Personaje capturar() {
    Personaje p;
    string temp;
    float temp_f;

    cout << "Nombre: ";
    getline(cin, temp);
    p.setNombre(temp);

    cout << "Tipo: ";
    getline(cin, temp);
    p.setTipo(temp);

    cout << "Fuerza: ";
    cin >> temp_f;
    p.setFuerza(temp_f);

    cout << "Salud: ";
    cin >> temp_f;
    p.setSalud(temp_f);

    return p;
}
size_t capturarPosicion() {
    size_t pos;
    
    cout << "Posicion: ";
    cin >> pos;

    return pos;
}

int main() {
    size_t cant;
    cout << "Cantidad: ";
    cin >> cant; 

    Arreglo<Personaje> psjs(cant);

    string op;
    while (true)
    {
        cout << "1) Agregar al final" << endl;
        cout << "2) Agregar al inicio" << endl;
        cout << "3) Insertar" << endl;
        cout << "4) Mostrar" << endl;
        cout << "5) Eliminar al final" << endl;
        cout << "6) Eliminar al inicio" << endl;
        cout << "7) Eliminar" << endl;
        cout << "8) Cantidad" << endl;
        cout << "9) Maximo" << endl;
        cout << "10) Estado" << endl;
        cout << "11) Frente" << endl;
        cout << "12) Ultimo" << endl;
        cout << "13) Buscar" << endl;
        cout << "14) Ordenar" << endl;
        cout << "0) Salir" << endl;
        cin >> op; cin.ignore();

        if (op == "1") {
            Personaje p = capturar();
            psjs.push_back(p);
        }
        else if (op == "2") {
            Personaje p = capturar();
            psjs.push_front(p);
        }
        else if (op == "3") {
            Personaje p = capturar();
            size_t pos = capturarPosicion();
            psjs.insert(p, pos);
        }
        else if (op == "4") {
            for (size_t i = 0; i < psjs.size(); i++)
            {
                cout << psjs[i];
            }
        }
        else if (op == "5") 
        {
            psjs.pop_back();
        }
        else if (op == "6") 
        {
            psjs.pop_front();
        }
        else if (op == "7") 
        {
            size_t pos = capturarPosicion();
            psjs.erase(pos);
        }
        else if (op == "8")
        {
            cout << "Cantidad: " << psjs.size() << endl;
        }
        else if (op == "9")
        {
            cout << "Maximo: " << psjs.max_size() << endl;
        }
        else if (op == "10")
        {
            cout << "Vacio: " << psjs.empty() << endl;
            cout << "Lleno: " << psjs.full() << endl;
        }
        else if (op == "11")
        {
            cout << "Frente: " << psjs.front() << endl;
        }
        else if (op == "12")
        {
            cout << "Ultimo: " << psjs.back() << endl;
        }
        else if (op == "13")
        {
            Personaje p = capturar();
            Personaje* encontrado = psjs.find(p);

            if (encontrado) {
                cout << *encontrado << endl;
                encontrado->setFuerza(0);
            } else {
                cout << "No existe el personaje" << endl;
            }
        }
        else if (op == "14")
        {
            size_t ascendete;
            cout << "Ascendente 1, Descendente 0: ";
            cin >> ascendete;

            psjs.sort(ascendete);
        }
        
        else if (op == "0") {
            break;
        }
    }
    


}