
#include <iostream>
#include <vector>
#include <algorithm>
//---------------------------------------------------------
using namespace std;


class Graph {

private:
//numero de vertices
int vSize; 
vector<vector<int>> grafo;

public:
    Graph(vector<vector<int>>, int);
    int minKey (vector<int> , vector<bool>  );
    void primMinimum();
    void printMST(vector<int>, vector<vector<int>>);
};

// A utility function to print the
// constructed MST stored in parent[]
void Graph::printMST(vector<int> mst, vector<vector<int>> graph)
{
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < vSize; i++)
        //0 - 1    2
        cout<<mst[i]<<" - "<<i<<" \t"<<graph[i][mst[i]]<<" \n";
}
 
Graph::Graph(vector<vector<int>> graph2, int n){
    grafo = graph2;
    vSize = n;
}



int Graph::minKey (vector<int> mins, vector<bool> visitadosMin ){
    int min = INT_MAX;
    int minIndex;

    for(int i = 0; i < visitadosMin.size(); i++){
        if(visitadosMin[i] == false && mins[i] < min){
            min = mins[i];
            minIndex = i;
        }
    }
    return minIndex;
}
//-------------------------------------------------------------------------------------------------------
void Graph::primMinimum(){
    //array para guardar el Minimun Spanning Tree contruido
    vector<int> mst;
    //vector para guardar los pesos minimo de cada mins(cada vertice)
    vector<int> mins;
    //vector de booleanos para marcar que vertice no estan en MST
    vector<bool> visitadosMin;

    //rellenas mins con infinitos(para ir encontrando minimos) y visitadosMin en false
    for (int i = 0; i < vSize; i++){
        mins[i] = INT_MAX;
        visitadosMin[i] = false;
    }

    //inicias la primera posicion en 0 para que acceda al source vertex, que sera el minimo ya que los demas estan en infinito
    mins[0] = 0;
    //inicias en -1 para indicar que el primer nodo sera el inicio del MST
    mst[0] = -1;

    for (int i = 0; i < vSize-1; i++){
        //va la posicion del nodo con minimo de weights
        int u = minKey(mins, visitadosMin);
        //declara el vertice visitado
        visitadosMin[u] = true;

        for (int j = 0; j < vSize; j++){
            if (( grafo[u][j] && visitadosMin[j] == false) && (grafo[u][j] < mins[j]) ){
                //guardas la posicion en el MST
                mst[j] = u;
                //valor del vertice
                mins[j] = grafo[u][j];
            }
        
    }

    }
    printMST(mst, grafo);

}