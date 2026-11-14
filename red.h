#ifndef RED_H
#define RED_H
#include "enrutador.h"
#include <fstream>
class Red
{
public:

    //Gestion de Enrutadores
    bool agregarEnrutador(const string& nombre){
        if (enrutadores.find(nombre) != enrutadores.end()){
            return false;
        }
        enrutadores.emplace(nombre, Enrutador(nombre));
        //despues hay que llamar a la actualizacion de tablas
        return true;
    }
    bool BorrarEnlace(const string& a, const string& b){
        if (enrutadores.find(a) == enrutadores.end() || enrutadores.find(b) == enrutadores.end() || a == b) {
            return false;
        }
        //se tiene que eliminar el enlace
        auto enra = enrutadores.find(a);
        auto enrb = enrutadores.find(a);
        //comprobar que hay enlace
        if (!enra->second.tieneEnlace(b)) {
            return false;
        }
        enra->second.eliminarEnlace(b);
        enrb->second.eliminarEnlace(b);
        //llamar actualizar tablas
        return true;
    }

    bool agregarEnlace(const string& a, const string& b, int costo){
        //Validaciones: iguales que borrarenlace, y el costo tiene que ser mayor a 0
        if (enrutadores.find(a) == enrutadores.end() || enrutadores.find(b) == enrutadores.end() || a == b || costo < 0) {
            return false;}
        //se agrega el enlace
        enra->second.agregarEnlace(b, costo);
        enrb->second.agregarEnlace(a, costo);
        return true;
        }
    }
    eliminarEnrutador(const string& nombre){
        auto it = enrutadores.find(nombre);
        if (enrutadores.find(nombre) != enrutadores.end() || it == enrutadores.find(nombre)){
            return false;
        }
        for (const auto& vec : it->second.getVecinos()) {
            auto iv = enrutadores.find(vec.first);
            iv->second.eliminarEnlace(nombre);
        }
        enrutadores.erase(nombre);
        //llamar a la actualizar tabla
        return true;
    }
    bool modificarCosto(const string& a, const string& b, int nuevoCosto){
        if (enrutadores.find(a) == enrutadores.end() || enrutadores.find(b) == enrutadores.end() || a == b || costo <= 0) {
            return false;
        }
        //verificar que hay un enlace ya existente
        if(!enra->second.tieneEnlace(b)){
            return false;
        }
        //si existe, hay que modificar su costo
        auto enra = enrutadores.find(a);
        auto enrb = enrutadores.find(b);
        enra -> second.modificarCosto(b, nuevoCosto);
        enrb -> second.modificarCosto(a, nuevoCosto);
        //hay que llamar a actualizar tablas
        return true;
    }
    void actualizacionTabla(){
        for (auto& entrada : enrutadores){
            entrada.second.CalcularTablaDijkstra(enrutadores);
        }
    }
    int whatCosto(const string& origen, const string& destino) const{
        auto it = enrutadores.find(origen);
        if (it == enrutadores.end()) {
            return -1;
        }
    }
    vector<string> whatCamino(const string& origen, const string& destino) const{
        auto it = enrutadores.find(origen);
        if (it == enrutadores.end()) {
            return it->second.Wayto(destino);        }
    }
    bool cargarDesdeArchivo(const string& ruta){
        string a,b;
        int costo;
        ifstream archivo(ruta);
        if (!archivo) {
            return false;
        }
        while (archivo >> a >> b >> costo) {
            agregarEnrutador(a);
            agregarEnrutador(b);
                agregarEnlace(a,b,costo);
        }
        return true;

    }
    Usuariogenerar(){};

    Red();
};

#endif // RED_H
