//Matías Méndez - A01422885
//Eduardo Galindo - A01028846
//Dynamic programming topDown algorithm
//Este algoritmo busca encontrar las tareas compatibles más óptimas de acuerdo a sus pesos

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

vector<vector<int>> closestPairs( vector<vector<int>> pairs ){
    //1. SACAR L = sacar el valor absoluto del eje x  max y eleje x  min y dividirlo entre 2, si da 0, no dividir entre 2

    //encontrar el minimo y el maximo de las coordenadas x
    int size = pairs.size();

    vector<int> xSorted;
    for (int i = 0; i < size ; i++) {
        xSorted.push_back(pairs[i][0]);
    }

    //finding the minimum element
    sort(xSorted.begin(), xSorted.end());

    int min = xSorted[0];
    int max = xSorted[xSorted.size()];

    int L = min + max;

    if(L != 0){
        L = L/2;
    }

    vector<vector<int>> left;
    vector<vector<int>> right;

    for (int i = 0; i < size ; i++) {
        if(pairs[i][0] <= L){
            //empuja el par hacia la vector izquierdo -> no sé si con pairs[i] ya se jala todo el par?????????
            left.push_back(pairs[i]);
        }else{
            right.push_back(pairs[i]);
        }
        
    }


    //separar left the right
}