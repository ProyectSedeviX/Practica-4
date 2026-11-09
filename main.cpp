#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

struct Ruta {
    int costo;
    vector<string> camino;
};

class Enrutador {
private:
    string nombre;
    map<string, int> vecinos;
    map<string, Ruta> tabla;

public:
//poner los metofdos eque necesita el enrutados
    bool agregarEnlace(const string& vecino, int costo);{
        //desde el enrutador definido en el main, se establece su costo desde el, hasta el vecino.
        if (costo <= 0 || vecino == nombre) {
            return false;
        }
        vecinos[vecino] = costo;
        return true;
    }
    bool eliminarEnlace(const string& vecino){
        //desde el enrutador definido en main, eliminar el costo en el mapa
        //validacion
        if(vecinos.find(vecino) == vecinos.end()){
            return false;
        }
        vecinos.erase(vecino);
        return true;
    }
    bool modificarCosto(const string& vecino, int nuevoCosto){
        //hay quie modificar el costo de un enlace la existente
        //comprobar primero si el enlace existe
        if(nuevoCosto <= 0 || vecino == nombre){
            return false;
        }
        if(vecinos.find(vecino) == vecinos.end()){
                return false;}
        //actualizar el costo ya existente
        vecinos[vecino] = nuevoCosto;
        return true;
    }
    bool tieneEnlace(const string& vecino) const{
        //demostrar que el vecino existe en el map
        if(vecinos.find(vecino) != vecinos.end()){
            return true;
        }
        else{return false;}
    }
    //Puede que lo mejor sea haacer todas los metodos en bool, para que la verificacion sea mas facil, de un F o un T, para la red.
    //metodos del enrutador completados.
    //hacer el constructor.
    Enrutador (const string&){
        nombre = n;
    }
    //hacer el getter del nombre
    const string& getNombre() const{
        return nombre;
    }
    //getter de los vecinos
    const map<string, int>& getVecinos() const{
        return vecinos;
    }
    //constructor y getters hechos.
    //Hay que hacer las funciones de averiguacion de costo de caminos
    int CousTo(const string& destino)const{
        auto valor = tabla.find(destino);
        if (tabla.find(destino) == tabla.end()){
            return -1;
        }
        return valor->second.costo;

    }
    //averiguar el camino hacia un enrutador
    vector<string> Wayto(const string& destino)const{
        auto valor = tabla.find(destino);
        if (tabla.find(destino) == tabla.end()){
            return {};
        }
        return valor->second.camino;
    }
    //Mostar la tabla
    void mostrarTabla() const{
        for(const auto& entrada : tabla){
            cout <<"destinu: "<< entrada.first<<", ";
            cout <<"costo: "<< entrada.second.costo;
            for (const auto& paso : entrada.second.camino) {
                cout << paso << " -- ";
            }
            cout << "\n";
        }
    }
    //Metodo de Dijkstra para hacer el calculo de la tabla
};
//Definicion de la clase Red
#include <string>
#include <map>
#include <vector>

using namespace std;

class Red {
private:
    map<string, Enrutador> enrutadores;

public:
    // Metodos pendientes de los enrutadores
};