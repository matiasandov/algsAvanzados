//Matías Méndez - A01422885
//Eduardo Galindo - A01028846
//Dynamic programming topDown algorithm
//Este algoritmo busca encontrar las tareas compatibles más óptimas de acuerdo a sus pesos

#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <sstream>
#include <stdio.h>
#include <algorithm>

#include "sort.hpp"
using namespace std;


vector<int> topDown(int n, vector<int> startTimes, vector<int> finishTimes, vector<int> weights ){
    //1. sort by finishTimes
    

    //2. valor p de cada tarea por busqueda binario
    
}

int main(int argc, char *argv[]) {
	vector<int> s_time;
	vector<int> f_time;
    vector<int> w;

    vector<Job> jobs;
	
	int n = stoi(argv[1]);

	for( int i = 2; i < argc; i++ )
	{
		if (i<=n+1)
		{
			s_time.push_back(stol(argv[i]));
		}
		else if (n+2<=n+1*2)
		{
		f_time.push_back(stol(argv[i]));
		}
        else
        {
        w.push_back(stol(argv[i]));
        }
	}

    for (int i=0; i< n; ++i){jobs.push_back(Job(i,s_time[i],f_time[i],w[i]));}

    


	//earliest_finish_time(n,s_time,f_time);
	return 0;
}

