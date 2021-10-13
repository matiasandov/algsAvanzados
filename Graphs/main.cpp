//
//  main.cpp
//  Graphs
//
//  Created by Matías Méndez on 10/11/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "GraphManager.hpp"
#include <list>
#include <set>
#include <time.h>
using namespace std;

int main(int argc, char *argv[]) {

    //numeor de edges
    int edges = atoi(argv[2]);
    
    int vertexN = edges*2;

    Graph graph(vector<>);
    //set para obtener el maximo numero de vertice, para concoer el tamaño de la matriz
    //empiezas a partir de la 3ra posicion porque la primera ./a.out, la segunda es numero de aristas y la tercera ya son los nodos
    set<int> nodes;

    for (int i=3; i<=edges+2;i++)
    {
        int oNode =atoi(argv[i]);
        int dNode =atoi(argv[i+edges]);

        nodes.insert(oNode);
        nodes.insert(dNode);
    }

    
    
    //inicicalizas grafo -> leyendo nodoOrigen NodoDestino y Peso de la arista
    for (int i=3; i<=edges+2;i++)
    {
        int oNode =atoi(argv[i]);
        int dNode =atoi(argv[i+edges]);
        int weight =atoi(argv[i+edges*2]);
        
        g.addEdge(oNode,dNode,weight);
    }
    g.mst();
    return 0;
}