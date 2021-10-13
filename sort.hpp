#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>
#include <set>
#include <stdio.h>
#include <algorithm>
using namespace std;

class Job {
private:
    int index;
    int start;
    int finish;
    int weight;
public:
    Job(int i,int s,int f, int w):index(i),start(s),finish(f),weight(w){}

    friend ostream & operator<<(ostream & os, const Job & job)
    {
    os << job.start << " - " << job.finish ;
    return os;
    }

    bool operator <=(const Job& job) {
         if(finish <= job.finish) {
            return true;
         }
         else if(finish == job.finish)
         {
             return true;
         }
         return false;
    }
    bool operator >=(const Job& job) {
         if(finish > job.finish) {
            return true;
         }
         else if(finish == job.finish)
         {
             return true;
         }
         return false;
    }
    int getIndex() {return index;}
    int getStart() { return start; }
    int getFinish() { return finish; }
};

void merge(vector<Job>& v, int a, int b, int c) {
	vector<Job> aux;
	int i, j;
	i = a;
	j = b + 1;
	while (i <= b && j <= c) {
		if (v[i] <= v[j]) {
			aux.push_back(v[i]);
			++i;
		}
		else {
			aux.push_back(v[j]);
			++j;
		}
	}
	while (i <= b) {
		aux.push_back(v[i]);
		++i;
	}
	while (j <= c) {
		aux.push_back(v[j]);
		++j;
	}
	for (int i = a; i <= c; ++i)
		v[i] = aux[i - a];
}

void mergeSort(vector<Job>& v, int a, int c) {
	if (a < c) {
		int b = (a + c) / 2;
		mergeSort(v, a, b);
		mergeSort(v, b + 1, c);
		merge(v, a, b, c);
	}
}
