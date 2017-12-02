/*
ID: cheezba1
TASK: ariprog
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, M;
set<int> numbers;
struct bleh {
    int a;
    int b;
    bleh(int as, int bs) {
        a = as;
        b = bs;
    }
    bool operator < (const bleh& bs) const { 
        //cout << b << " " << bs.b << " " << (b < bs.b) << endl;
        return b < bs.b;
    }
};
vector<bleh> asdf;

ifstream fin("ariprog.in");
ofstream fout("ariprog.out");

int main() {
    cout << "Start" << endl;
    fin >> N >> M;
    int count, last, diff, i = 0;
    int* numarr;
    bool foundAny = false;
    set<int>::iterator iter;
    for(int a = 0; a <= M; a++)
        for(int b = 0; b <= M; b++)
            numbers.insert((a*a) + (b*b));
    numarr = new int[numbers.size()];
    for(set<int>::iterator first = numbers.begin(); first != numbers.end(); first++) {
        numarr[i] = *first;
        i++;
    }
    //cout << i << endl;
    for(int first = 0; first < i - 1; first++) {
        for(int second = first + 1; second < i; second++) {
            diff = numarr[second] - numarr[first];
            if(diff > ((M*M)*2)/(N-1))
                continue;
            last = numarr[second];
            if(last + (diff * (N-2)) > (M*M)*2)
                break;
            //cout << "Diff: " << diff << endl;
            count = 0;
            for(int j = 0; j < N-2; j++) {
                if(numbers.find(last + diff) != numbers.end()) {
                    count++;
                    last += diff;
                    //cout << last << " ";
                } else {
                    break;
                }
            }
            if(count == N-2) {
                //cout << "SUCCESS";
                foundAny = true;
                asdf.push_back(bleh(numarr[first], diff));
            }
            //cout << endl;
        }
    }
    std::sort(asdf.begin(), asdf.end());
    for(int a = 0; a < asdf.size(); a++) {
        fout << asdf[a].a << " " << asdf[a].b << endl;
    }
    if(!foundAny)
        fout << "NONE" << endl;
    return 0;
}
