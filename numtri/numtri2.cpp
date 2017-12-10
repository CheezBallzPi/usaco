/*
ID: cheezba1
TASK: numtri
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

ifstream fin("numtri.in");
ofstream fout("numtri.out");

int main() {
    int rows, hold;
    fin >> rows;
    int** inputs = new int*[rows];
    for(int i = 1; i <= rows; i++) {
        inputs[i-1] = new int[rows];
        for(int j = 0; j < i; j++) {
            fin >> hold;
            inputs[i-1][j] = hold;
        }
    }
    int* totals = new int[rows];
    for(int i = 0; i < rows; i++) {
        totals[i] = inputs[rows-1][i];
    }
    // for(int j = 0; j < rows; j++) {
    //     cout << totals[j] << " ";
    // }
    //cout << endl;
    for(int i = rows-1; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            //cout << totals[j] << " " << totals[j+1] << endl;
            if(totals[j] >= totals[j+1]) {
                totals[j] += inputs[i-1][j];
            } else {
                totals[j] = totals[j+1];
                totals[j] += inputs[i-1][j];
            }
        }
        // for(int j = 0; j < i; j++) {
        //     cout << totals[j] << " ";
        // }
        // cout << endl;
    }
    cout << totals[0] << endl;
    fout << totals[0] << endl;
    return 0;
}