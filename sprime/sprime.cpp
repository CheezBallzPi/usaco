/*
ID: cheezba1
TASK: sprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

ifstream fin("sprime.in");
ofstream fout("sprime.out");

set<long> primeses, primeses2;

bool check(long n, set<long>& s) {
    if(n == 1) {
        return false;
    }
    if(s.find(n) != s.end()) {
        return true;
    }
    for(set<long>::iterator it = primeses.begin(); it != primeses.end(); it++) {
        if(n % *it == 0) {
            return false;
        }
    }
    //cout << n << " works" << endl;
    s.insert(n);
    //cout << s.size() << endl;
    return true;
}

int getLen(long n) {
    int len = 0;
    while(n) {
        len++;
        n/=10;
    }
    
    return len;
}

int main() {
    int n, hold;
    bool cont = false;
//    for (int a = 0; a < 100; a++) {
        fin >> n;
        cout << long(sqrt(pow(10,n) - 1)) << endl;
        
        for(long i = 3; i < long(sqrt(pow(10,n) - 1)); i+=2) {
                    check(i, primeses);
        }

        for(long i = pow(10,n-1) + 1; i < pow(10,n) - 1; i+=2) {
            hold = i;
            cont = false;
            if((i / long(pow(10,n-1))) % 2 == 0)
                continue;
            for(int j = 0; j < n-1; j++) {
                if(hold % 2 == 0) {
                    cont = true;
                    break;
                }
                hold/=10;
            }
            if(cont)
                continue;
            //cout << i << endl;
            check(i, primeses2);
        }

        cout << "Done Creation" << endl;
        cout << primeses2.size() << endl;
        for(set<long>::iterator it = primeses2.begin(); it != primeses2.end(); it++) {
            hold = *it;
            //cout << hold << endl;
            if(getLen(hold) != n)
                continue;
            for(int i = 0; i < n; i++) {
                //cout << endl << hold << " Check " << i << " ";
                if(!check(hold, primeses)) {
                    break;
                }
                hold /= 10;
                //cout << hold << " ";
            }
            //cout << endl;
            if(hold == 0) {
                //cout << *it << endl;
                fout << *it << endl;
            }
        }

 //   }
    return 0;
}