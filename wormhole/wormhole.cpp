/*
ID: cheezba1
TASK: wormhole
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<long long> vec = {0,0,0,0,0,0,0,0,0,0,0,0,0};
long long toright[13];
long long coords[13][2];
long long size;
long long maxRight = 0;
long long count = 0;
long long loops = 0;

bool checkit() {
    long long a;
    for(long long i = 1; i <= size; i++) {
        a = i;
        for(int j = 0; j <= size; j++) {
            a = vec[toright[a]];
            //cout << "k." << endl;
        }
        if(a != 0) {
            return 1;
        }
    }
    return 0;
}

long long link() {
    //cout << "p" << endl;
    long long i, total = 0;
    // for(long long k = 0; k <= size; k++) {
    //     cout << vec[k] << " ";
    // }
    //cout << endl;
    for(i = 1; i <= size; i++) {
        if(vec[i] == 0) {
            break;
        }
    }
    //cout << "d" << endl;
    //cout << "i:" << i << endl;
    if(i > size) {
        if(checkit()) {
            return 1;
        } else {
            return 0;
        }
    }
    //cout << "e" << endl;
    for(long long j = i+1; j <= size; j++) {
        if(vec[j] == 0) {
            //cout << i << " " << j << endl;
            vec[i] = j;
            vec[j] = i;
            total += link();
            vec[i] = vec[j] = 0;
        }
    }
    //cout << "f" << total << endl;
    return total;
}

int main() {
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");
    fin >> size;
    //cout << "l" << endl;
    for(long long i = 1; i <= size; i++) {
        fin >> coords[i][0] >> coords[i][1];
        if(coords[i][1] > maxRight) {
            maxRight = coords[i][1];
        }
    }
    //cout << "a" << endl;
    for (int i=1; i<=size; i++) {
        for (int j=1; j<=size; j++) {
            if (coords[j][0] > coords[i][0] && coords[i][1] == coords[j][1]) {
                if (toright[i] == 0 || coords[j][0]-coords[i][0] < coords[toright[i]][0]-coords[i][0]) {
                    toright[i] = j;
                }
            }
        }
    }
    //cout << "b" << endl;
    // for(long long j = 0; j <= size; j++) {
    //     cout << toright[j] << " ";
    // }
    //cout << endl << maxRight << endl;

    fout << link() << endl;
    //cout << "c" << endl;
    //cout << loops / 2 << endl;

    return 0;
}