#include <iostream>
#include "computadora.h"
#include "laboratorio.h"
using namespace std;

int main(){
    Laboratorio l;
    string op;

    while (true)
    {
        cout << "1.- Agregar personaje" << endl;
        cout << "2.- Mostrar" << endl;
        cout << "3.- Respaldar" << endl;
        cout << "4.- Recuperar" << endl;
        cout << "5.- Insertar" << endl;
        cout << "6.- Inicializar" << endl;
        cout << "7.- Eliminar" << endl;
        cout << "8.- Ordenar" << endl;
        cout << "9.- Buscar" << endl;
        cout << "0.- Salir" << endl;
        getline(cin, op);
        if (op == "1"){
            Computadora c;
            cin >> c; cin.ignore();

            l.agregarComputadora(c);
            cin.ignore();
        }
        else if (op == "2")
        {
            l.mostrar();
        }
        else if (op == "3")
        {
            l.respaldar();
        }
        else if (op == "4")
        {
            l.recuperar();
        }
        else if (op == "5")
        {
            Computadora c;
            cin >> c;

            size_t pos;
            cout << "Pos: ";
            cin >> pos; cin.ignore();
            if (pos >= l.size())
            {
                cout << "Pos no válida" << endl;
            }
            else
            {
                l.insertar(c,pos);
            }
        }
        else if (op == "6")
        {
            Computadora c;
            cin >> c;

            size_t n;
            cout << "N: ";
            cin >> n; cin.ignore();

            l.inicializar(c,n);
        }
        else if (op == "7")
        {
            size_t pos;
            cout << "Pos: ";
            cin >> pos; cin.ignore();
            if (pos >= l.size())
            {
                cout << "Pos no válida" << endl;
            }
            else
            {
                l.eliminar(pos);
            } 
        }
        else if (op == "8")
        {
            l.ordenar();
        }
        else if (op == "9")
        {
            Computadora c;
            cin >> c; cin.ignore();

            Computadora *ptr = l.buscar(c);

            if(ptr == nullptr){
                cout << "No encontrado" << endl;
            }
            else
            {
                cout << *ptr << endl;
            }
        }
        else if (op == "0")
        {
            break;
        } 
    }
}