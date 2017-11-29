/*
ID: cheezba1
TASK: ariprog
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int N, M;
vector<int> numbers;

ifstream fin("ariprog.in");
ofstream fout("ariprog.out");

void check(int diff) {
    int pa = 0, qa = 0, pb = 0, qb = 0, start = 0, curr = 0, last = 0, count;
    bool sentOne = false, weGood = false;
    // Loop through Starting numbers
    for(int a = 0; a <= M; a++) {
        for(int b = a; b <= M; b++) {
            start = (a * a) + (b * b);
            if(start > ((a+1) * (a+1)) * 2) {
                cout << "----- " << ((a+1) * (a+1)) * 2;
                break;
            }
            // Loop through the right amount of times
            last = start;
            count = 0;
            cout << "Start: " << start << "   " << a << " " << b << endl;
            for(int i = 0; i < N - 1; i++) {
                for(int an = 0; an <= M; an++) {
                    // Check for next num
                    for(int bn = an; bn <= M; bn++) {
                        //cout << ((an * an) + (bn * bn)) << "|" << ((an * an) + (bn * bn)) - last << " ";
                        if(((an * an) + (bn * bn)) - last == diff) {
                            weGood = true;
                            cout << (an * an) + (bn * bn) << endl;
                            last = (an * an) + (bn * bn);
                            break;
                        } else if(((an * an) + (bn * bn)) - last > diff) {
                            continue;
                        }
                    }
                    if(weGood)
                        break;
                }
                if(!weGood)
                    break;
                count++;
                weGood = false;
            }
            if(count == N - 1) {
                cout << "SUCCESS" << endl;
                fout << start << " " << diff << endl;
                sentOne = true;
            }
        }
        //if(sentOne)
        //    return true;
        //else
        //    return false;
    }
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
    cout << N << " " << M;
    iterate();
    return 0;
}
