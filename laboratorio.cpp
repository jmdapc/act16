#include "laboratorio.h"
#include<fstream>
#include<algorithm>
Laboratorio::Laboratorio()
{
    

}

void Laboratorio::agregarComputadora(const Computadora &c)
{
    compu.push_back(c);
}
void Laboratorio::mostrar()
{
    cout << left;
    cout << setw(15) << "Nombre";
    cout << setw(18) << "Sistema Operativo";
    cout << setw(15) << "Memoria Ram";
    cout << setw(15) << "Memoria SSD";
    cout << endl;
    for(size_t i=0; i<compu.size(); i++){
        Computadora &c = compu[i];
        cout << c;
        /*cout << "Nombre del equipo: " << c.getNombreEquipo() << endl;
        cout << "Sistema operativo: " << c.getSistemaOp() << endl;
        cout << "Memoria Ram: " << c.getMemoriaRam() << "GB" << endl;
        cout << "Memoria SSD: " << c.getMemoriaSSD() << "GB" << endl;
        cout << endl;*/
    }
}
void Laboratorio::respaldar_tabla()
{
    ofstream archivo("computadora_tabla.txt");
    if(archivo.is_open()){
        archivo << left;
        archivo << setw(15) << "Nombre";
        archivo << setw(18) << "Sistema Operativo";
        archivo << setw(15) << "Memoria Ram";
        archivo << setw(15) << "Memoria SSD";
        archivo << endl;
        for(size_t i=0; i<compu.size(); i++){
        Computadora &c = compu[i];
        archivo << c;
        }
    }
    archivo.close();
}
void Laboratorio::respaldar()
{
    ofstream archivo("computadora.txt");
    if(archivo.is_open()){
        for(size_t i=0; i<compu.size(); i++){
        Computadora &c = compu[i];
        archivo << c.getNombreEquipo() << endl;
        archivo << c.getSistemaOp() << endl;
        archivo << c.getMemoriaRam() << endl;
        archivo << c.getMemoriaSSD() << endl;
        //archivo << c;
        }
    }
    archivo.close();
}
void Laboratorio::recuperar()
{
    ifstream archivo("computadora.txt");
    if(archivo.is_open()){
        string temp;
        int memoriaRam;
        int memoriaSSD;
        Computadora c;

        while (true)
        {
            getline(archivo, temp);
            if(archivo.eof()){
                break;
            }
            c.setNombreEquipo(temp);
            getline(archivo, temp);
            c.setSistemaOp(temp);
            getline(archivo, temp);
            memoriaRam = stoi(temp);
            c.setMemoriaRam(memoriaRam);
            getline(archivo, temp);
            memoriaSSD = stoi(temp);
            c.setMemoriaSSD(memoriaSSD);

            agregarComputadora(c);
        }
    }
    archivo.close();
}
void  Laboratorio::insertar(const Computadora &c, size_t pos)
{
    compu.insert(compu.begin()+pos, c);
}
size_t Laboratorio::size()
{
    return compu.size();
}
void Laboratorio::inicializar(const Computadora &c, size_t n)
{
    compu = vector<Computadora>(n, c);
}
void Laboratorio::eliminar(size_t pos)
{
    compu.erase(compu.begin()+pos);
}
void Laboratorio::ordenar()
{
    sort(compu.begin(), compu.end());
}
Computadora* Laboratorio::buscar(const Computadora &c)
{
    auto it = find(compu.begin(), compu.end(),c);

    if (it == compu.end())
    {
        return nullptr;
    }
    else
    {
        return &(*it);
    }
}