/*
ID: cheezba1
TASK: milk3
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int sizes[3];
int currA = 0, currB = 0, currC;

struct buckets {
    int amounts[3];

    buckets(int x, int y, int z) {
        amounts[0] = x;
        amounts[1] = y;
        amounts[2] = z;
    }
    void dump(int first, int second) {
        if(amounts[first] > sizes[second] - amounts[second]) {
            amounts[first] -= sizes[second] - amounts[second];
            amounts[second] = sizes[second];
        } else {
            amounts[second] += amounts[first];
            amounts[first] = 0;
        }
    }
    bool operator<(const buckets& buck) const {
        if(amounts[0] < buck.amounts[0])
            return true;
        else if(amounts[0] == buck.amounts[0]) {
            if(amounts[1] < buck.amounts[1])
                return true;
            else if(amounts[1] == buck.amounts[1]) {
                if(amounts[2] < buck.amounts[2])
                    return true;
                else if(amounts[2] == buck.amounts[2]) {
                    return false;
                }
            }
        }
        return false;
    }
};

set<buckets> bset;
set<int> finals;

void solve(buckets buck) {
    if(bset.find(buck) != bset.end()) {
        if(buck.amounts[0] == 0)
            finals.insert(buck.amounts[2]);
        return;
    } else {
        bset.insert(buck);
        buckets b = buck;
        b.dump(0,1);
        solve(b);
        b = buck;
        b.dump(0,2);
        solve(b);
        b = buck;
        b.dump(1,0);
        solve(b);
        b = buck;
        b.dump(1,2);
        solve(b);
        b = buck;
        b.dump(2,0);
        solve(b);
        b = buck;
        b.dump(2,1);
        solve(b);
        return;
    }
}

int main() {
    cout << "start" << endl;
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");

    fin >> sizes[0] >> sizes[1] >> sizes[2];
    buckets bucket(0,0,sizes[2]);
    cout << "solving" << endl;
    solve(bucket);
    unsigned int i = 0;
    for(set<int>::iterator it = finals.begin(); it != finals.end(); ++it) {
        if(i != finals.size() - 1)
            fout << *it << " ";
        else
            fout << *it;
        i++;
    }
    fout << endl;

    return 0;
}