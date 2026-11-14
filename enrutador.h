#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int Infinite = 1e9;

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
    bool agregarEnlace(const string& vecino, int costo){
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
    //el valor del enlace debe ser positivo
    const int Infinite = 1e9;

    void CalcularTablaDijkstra(const map<string, Enrutador>& topologia) {
        map<string, int> dist;
        map<string, string> previo;
        set<pair<int, string>> pq;

        // Parte 1: inicialización
        for (const auto& entrada : topologia) {
            dist[entrada.first] = Infinite;
        }
        dist[nombre] = 0;
        pq.insert({0, nombre});

        // Parte 2: Dijkstra con set
        while (!pq.empty()) {
            auto primero = *pq.begin();      // el de menor distancia
            pq.erase(pq.begin());
            int d = primero.first;
            string u = primero.second;

            for (const auto& vec : topologia.at(u).getVecinos()) {
                const string& v = vec.first;
                int peso = vec.second;

                if (d + peso < dist[v]) {
                    pq.erase({dist[v], v});  // quitar entrada vieja (valor viejo)
                    dist[v] = d + peso;
                    previo[v] = u;
                    pq.insert({dist[v], v});
                }
            }
        }
// Llenar la tabla
tabla.clear();
for (const auto& entrada : dist) {
    if (entrada.second == Infinite) continue;   // inalcanzable
    Ruta r;
    r.costo = entrada.second;
    for (string x = entrada.first; ; x = previo[x]) {
        r.camino.push_back(x);
        if (x == nombre) break;
    }
    reverse(r.camino.begin(), r.camino.end());
    tabla[entrada.first] = r;
}
}
}
#if;
#endif
