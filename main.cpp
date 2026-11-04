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
};