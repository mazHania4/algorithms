/*
Escriba una funcion que determine si dos palabras son anagramas, dos palabras son anagramas si tienen las exactas mismas letras aunque no en el mismo orden.
Las entradas son dos palabras
La salida es un boolean indicando si son anagramas o no.

ejemplos:

entradas: espada pesada
salida: true

entradas: hola cola
salida: false

entradas: amor roma
salida: true

entradas: piedras pietras
salida: false

 */

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Problem_1 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("introduce la primera palabra: ");
        char[] palabra1 = scanner.nextLine().toLowerCase().toCharArray();

        System.out.print("introduce la segunda palabra: ");
        char[] palabra2 = scanner.nextLine().toLowerCase().toCharArray();

        boolean res =  evaluarAnagrama(palabra1, palabra2);
        System.out.println("es anagrama? " + res);

        scanner.close();
    }

    private static boolean evaluarAnagrama(char[] palabra1, char[] palabra2) {
        if (palabra1.length != palabra2.length) return false;

        Map<Character, Integer> conteos = new HashMap<>();
        for (char c : palabra1) {
            conteos.put(c, conteos.getOrDefault(c, 0) + 1);
        }

        for (char c : palabra2) {
            if (!conteos.containsKey(c) || conteos.get(c) == 0) {
                return false;
            }
            conteos.put(c, conteos.get(c) - 1);
        }

        for (int count : conteos.values()) {
            if (count != 0) {
                return false;
            }
        }
        
        return true;
    }
}

//al usar lenguaje -> saber que hacen las librerías, que exactamente hacen los metodos
//repaso notacion big O, no implica tiempo, solo repeticiones
//ciclos -> O(N)
//anidados -> ON2
//este caso O(N) o O(1) depende de la librería
//validación del mapa con equals, era ideal usar un mapa, complejidad mínima era O(N)
//repasar mapas en cualquier lenguaje dict en python
// aprender el funcionamiento general de los algoritmos
// mas la logica que implementar edd pero si el manejo de edd. Algoritmos van de la mano con estructura de datos
//qué lenguaje? -a cuál le sabes mejor las mañas?
//dict en python complica usar objetos como llaves
//B1 Yenni C1

