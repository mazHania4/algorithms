#include <cstring>
#include <string>
#include <iostream>
#include <any>
#include <vector>
#include <type_traits>

using namespace std;
using AnyArray = vector<any>;
using FlatArray = vector<any>;

/*
    Write your own function that transform an Array of objects, which could contain objects that are also array of objects, into a single Array.
    your function must transform any given array input.
    The input is an array and the output should be an array.

        Input                                   Output
        [1, 2, ["3", "4"]]                      : [1, 2, "3", "4"]
        [1, 2, [3, 4, [5, 6]]]                  : [1, 2, 3, 4, 5, 6]
        [1, 2, ["a", "b", [5, 6]]]              : [1, 2, "a", "b", 5, 6]
        [1, 2, [3, 4, [5, 6, [7, 8, [9, 10]]]]] : [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
*/

void lazy(); //solo maneja las entradas como strings ignorando caracteres
void elaborate(); // usa arreglos ya instanciados (no entrada por teminal) y los aplana

void aplanar(const AnyArray& input, FlatArray& output);

int main() {
    cout << "Problema #2\n";
    //lazy();
    elaborate();
    return 0;
}

void lazy() {
    cout << "Ingrese un arreglo: \n";
    string input;
    getline(cin >> ws, input);
    const size_t length = input.length();
    char input_arr[length];
    strcpy(input_arr, input.c_str());

    string output = "[";
    string accumulator;

    for (int i = 0; i < length; i++) {
        if (input_arr[i] == ' ' || input_arr[i] == '[' || input_arr[i] == ']') continue;
        if (input_arr[i] == ',') {
            output += accumulator + ", ";
            accumulator = "";
        } else accumulator += input_arr[i];
    }
    if (!accumulator.empty()) output += accumulator;
    output += "]";
    cout << "Salida:" << output << endl;
}

void elaborate() {
    // /*
    AnyArray input = { 1, 2,
            AnyArray{ 3, 4,
                AnyArray{ 5, 6,
                    AnyArray{7, 8, AnyArray{9, 10} }
                }
            }
    };
    // */

    //AnyArray input = {1, 2, AnyArray{"a", "b", AnyArray{5, 6}}};


    FlatArray output;
    aplanar(input, output);

    //imprimir arreglo
    cout << "[";
    for (size_t i = 0; i < output.size(); ++i) {
        //cout << output[i].type().name();
        if (output[i].type() == typeid(int))
            cout << any_cast<int>(output[i]);
        else if (output[i].type() == typeid(const char*))
            cout << "\"" << any_cast<const char*>(output[i]) << "\"";
        else cout << "(tipo desconocido)";
        if (i != output.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

void aplanar(const AnyArray& input, FlatArray& output) {
    for (any element : input) {
        if (element.type() == typeid(AnyArray)) {
            aplanar(any_cast<AnyArray>(element), output);
        } else {
            output.push_back(element);
        }
    }
}