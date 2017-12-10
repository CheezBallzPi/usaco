/*
ID: cheezba1
TASK: pprime
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <bitset>

using namespace std;

ifstream fin("pprime.in");
ofstream fout("pprime.out");

vector<int> primes;
int a, b;

bool check(int n) {
    int hold = n, newNum = 0;
    while(hold) {
        newNum *= 10;
        newNum += hold % 10;
        hold /= 10;
    }
    if(newNum == n) {
        return true;
    } else {
        return false;
    }
}

int main() {
    fin >> a >> b;
    primes.push_back(2);
    bool divided = false;
    for(int i = 3; i < b; i+=2) {
        divided = false;
        for(int j = 0; j < primes.size(); j++) {
            if(i % primes[j] == 0) {
                divided = true;
                break;
            }
        }
        if(!divided) {
            primes.push_back(i);
            if(i >= a && check(i)) {
                cout << i << endl;
                fout << i << endl;
            }
        }
    }
}