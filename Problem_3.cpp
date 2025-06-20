#include <iostream>
#include <vector>;
using namespace std;

/*
La operación RotarIzquiera sobre un array de tamaño N cambia cada elemento del array una posición a la izquierda.
Dado un entero D, rotar el arreglo tantas veces a la izquierda como lo indica D y regrese el resultado.
Ejemplo
entradas:
D = 2
Arr = [1,2,3,4,5]
Salida
después de 2 rotaciones, el resultado es
ArrR = [3,4,5,1,2]

*/

int main() {
    vector array = {1, 2, 3, 4, 5};
    int s = array.size();
    int D;
    cout << "Ingrese número de rotaciones: " << endl;
    cin >> D;
    int d = D % s;
    vector<int> res;
    for(int i = d; i < s; i++) {
        res.push_back(array[i]);
    }
    for(int i = 0; i < d; i++) {
        res.push_back(array[i]);
    }
    for (int i = 0; i < s; i++) {
        cout << res[i] << " ";
    }
    cout << endl;


    return 0;
}