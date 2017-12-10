/*
ID: cheezba1
TASK: numtri
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <bitset>
#include <math.h>

using namespace std;

ifstream fin("numtri.in");
ofstream fout("numtri.out");

int max = 0, rows;

struct node {
    int val;
    node* left;
    node* right;
};

int sumup(node n, bitset<1001> bs, int pos) {
    int total;
}

int main() {
    fin >> rows;
    cout << rows << endl;
    bitset<1000> bs;
    for(int i = 0; i < rows; i++) {
        bs.set(i);
    }
    cout << bs.to_string() << endl;

    node start;
    node* currNode = &start;
    int value;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j <= i; j++) {
            fin >> value;
            currNode->val = value;
        }
    }

    while(bs != 0) {
        bs-=1;
    }

    return 0;
}