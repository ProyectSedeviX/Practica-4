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
    bool agregarEnlace(const string& vecino, int costo);
    bool eliminarEnlace(const string& vecino);
    bool modificarCosto(const string& vecino, int nuevoCosto);
    bool tieneEnlace(const string& vecino) const;
    //Puede que lo mejor sea haacer todas los metodos en bool, para que la verificacion sea mas facil, de un F o un T, para la red.
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