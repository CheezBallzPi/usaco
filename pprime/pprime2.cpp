/*
ID: cheezba1
TASK: pprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

ifstream fin("pprime.in");
ofstream fout("pprime.out");

long a, b;
set<long> primeses;

long getLim(long n) {
    int len = 0, hold = n;
    while(hold) {
        len++;
        hold/=10;
    }
    cout << "Len: " << len << endl;
    for(int i = 0; i < len/2; i++) {
        n/=10;
    }
    return n;
}

long makeOdd(long n) {
    long len = 0, a = n, b = 0;
    while(a > 0) {
        len++;
        b += a % 10;
        b *= 10;
        a/=10;
        n*=10;
    }
    return n/10 + ((b/10) % long(pow(10,len-1)));
}

long makeEven(long n) {
    long a = n, b = 0;
    while(a > 0) {
        b += a % 10;
        b *= 10;
        a/=10;
        n*=10;
    }
    return n + b/10;
}

bool check(long n) {
    for(set<long>::iterator it = primeses.begin(); it != primeses.end(); it++) {
        if(n == *it) {
            return true;
        }
        if(n % *it == 0) {
            return false;
        }
    }
    //cout << n << " works" << endl;
    primeses.insert(n);
    return true;
}

int main() {
    fin >> a >> b;
    set<long> primes;
    long mn = getLim(a), mx = getLim(b);
    bool maxEven = false, maxOdd = false;
    cout << mn << " " << mx << endl;
    cout << makeOdd(999) << endl;
    long even, odd;
    //cout << check(5) << endl;
    cout << (mn/10) + 1 << " " << 10*(mx+1) << endl;
    primeses.insert(2);
    for(long i = 3; i <= sqrt(b); i+=2) {
        check(i);
    }
    for(long i = (mn/10) + 1; i < 10*(mx+1); i++) {
        //cout << i << endl;
        //cout << "a" << endl;
        if(!maxEven && i%10 == 0) {
            even = makeEven(i/10);
            //cout << "A" << endl;
            if(even >= a && even <= b && even%2 == 1){
                //cout << even << endl;
                if(even > b) {
                    cout << "Hit max" << endl;
                    maxEven = true;
                }
                if(check(even)) {
                    primes.insert(even);
                }
            }
        }
        //cout << "A" << endl;
        if(!maxOdd) {
            odd = makeOdd(i);
            //cout << odd << endl;
            if(odd >= a && odd <= b && odd%2 == 1) {
                //cout << odd << endl;
                if(odd > b) {
                    //cout << odd << endl;
                    maxOdd = true;
                }
                if(check(odd)) {
                    //cout << odd << endl;
                    primes.insert(odd);
                }
            }
        }
        //cout << "A" << endl;
    }
    int count = 0;
    for(set<long>::iterator it = primes.begin(); it != primes.end(); it++) {
        //cout << *it << endl;
        count++;
        fout << *it << endl;
        //if(count == 779)
        //    break;
    }
    cout << primes.size() << endl;
    return 0;
}