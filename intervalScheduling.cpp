/*
INTERVAL SCHEDULING
Find max (largest) subnet of mutually compatible jobs. 
Cual es la mayor cantidad de tareas que yo puedo hacer en este tiempo.
*/

#include <iostream>
//#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

bool sortByTime (const tuple<string, int, int>& a, const tuple<string, int, int>& b) {
    return (get<2>(a) < get<2>(b));
}

// tasks = {{"a" , 0 , 6}} 
vector<tuple<string, int, int>> earliestFinishTimeFirst(int num, vector<tuple<string, int, int>> tasks) {
    //Sort by FINISH time 
    sort(tasks.begin(), tasks.end(), sortByTime); //----->  b,c,a,e,d,f,g,h

//creas vectpr para la solución
    vector<tuple<string, int, int>> solution;

//recorre el vector de input de tuplas
    for (int i = 0; i < num; i++) {
        //si el tamaño del vector no cambia, la solucion es el vector inicial creo
        if (solution.size() == 0)
            solution.push_back(tasks[i]);

        //si el segundo 
        else if (get<2>(solution.back()) <= get<1>(tasks[i])) {
            solution.push_back(tasks[i]);
        }
    }

    return solution;
}

int main() {
    vector<tuple<string, int, int>> tasks;
    tasks.push_back(make_tuple("a" , 0 , 6));
    tasks.push_back(make_tuple("b" , 1 , 4));
    tasks.push_back(make_tuple("c" , 3 , 5));
    tasks.push_back(make_tuple("d" , 3 , 8));
    tasks.push_back(make_tuple("e" , 4 , 7));
    tasks.push_back(make_tuple("f" , 5 , 9));
    tasks.push_back(make_tuple("g" , 6 , 10));
    tasks.push_back(make_tuple("h" , 8 , 11));

    vector<tuple<string, int, int>> solution = earliestFinishTimeFirst(8, tasks);
    for (int i = 0; i < solution.size(); i++) {
        cout << get<0>(solution[i]) << " ";
    }

    return 0;
}