#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> intervals( vector<int> startTimes, vector<int> finishTimes ){
    int tam = finishTimes.size();

    for(int i = 0; i <= tam; i++){
        int startAct = startTimes[i];
        int finAct = finishTimes[i];
        //???
        int tamBloque = finAct - startAct;
        //para guardar tamaños de las posibles combinaciones
        vector<vector<int>> blockSizes;
        blockSizes[i][0] = tamBloque;
        for(int j  = 1; j <= tam; j++){
            //comaptibles
            if( startTimes[j] == finAct ){
                int tamBloque2 = finishTimes[j] - startTimes[j];
                //1. agregar posicion de compatibles a un vector tam sets, donde en cada set vendra la compatibilidad de i 

                //2. agregar un vector BlockSizes de vectores el tamaño de los bloues compatibles
                blockSizes[i][j] = tamBloque2;

            }
            //tener una flag para que si no hubo compatibilidad del bloque i con ningun otro en BlockSizes en la posicion i se ponga un cero
            //aunque creo que también se podrúia quedar vacío

            //3. evaluar que combinacion de compatibilidades es la más ótima de acuerdo a su tamaño total
        }  
     
    }
}