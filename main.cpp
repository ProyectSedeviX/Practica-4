#include <string>
#include <map>
#include <vector>

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