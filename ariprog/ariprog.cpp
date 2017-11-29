/*
ID: cheezba1
TASK: ariprog
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N, M;
ifstream fin("ariprog.in");
ofstream fout("ariprog.out");

void check(int diff) {
    int pa = 0, qa = 0, pb = 0, qb = 0, start = 0, curr = 0, last = 0, count;
    bool a = true, b = true, sentOne = false;
    // Loop through Starting numbers
    while(pb <= M && qb <= M) {
        start = (pb * pb) + (qb * qb);
        // Loop through the right amount of times
        pa = pb;
        qa = qb;
        curr = 0;
        last = start;
        count = 0;
        cout << "Start: " << start << endl;
        for(int i = 0; i < N; i++) {
            // Check for next num
            cout << "i: " << i << endl; 
            while(curr - last < diff) {
                curr = (pa * pa) + (qa * qa);
                if(a)
                    pa++;
                else
                    qa++;
                a = !a;
            }
            cout << "- Found " << curr << endl;
            cout << last << " " << curr << " " << pa << " " << qa << endl;
            if(curr - last != diff || pa > M || pb > M) {
                cout << "FAILED" << endl;
                break;
            }
            cout << "               Continue" << endl;
            last = curr;
            count++;
        }
        if(count == N) {
            cout << "               SUCCESS" << endl;
            fout << start << " " << diff << endl;
            sentOne = true;
        }
        if(b)
            pb++;
        else
            qb++;
        b = !b;
    }
    //if(sentOne)
    //    return true;
    //else
    //    return false;
}

void iterate() {
    int p = 0, q = 0, a;
    bool start = true;
    for(int i = 1; i < 25; i++) {
        cout << "                  Diff: " << i << endl;
        check(i);
    }
}

int main() {
    fin >> N >> M;
    iterate();
    return 0;
}
