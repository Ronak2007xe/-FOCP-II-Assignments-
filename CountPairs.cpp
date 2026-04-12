#include <bits/stdc++.h>
using namespace std;


const int LIMIT = 10000000;


vector<int> smallestPrime(LIMIT + 1);


void buildSPF() {
    for (int i = 1; i <= LIMIT; i++) {
        smallestPrime[i] = i;
    }

    for (int i = 2; i * i <= LIMIT; i++) {
        if (smallestPrime[i] == i) { 
            for (int j = i * i; j <= LIMIT; j += i) {
                if (smallestPrime[j] == j) {
                    smallestPrime[j] = i;
                }
            }
        }
    }
}


int countDistinctFactors(int num) {
    int distinctCount = 0;

    while (num > 1) {
        int primeFactor = smallestPrime[num];
        distinctCount++;


        while (num % primeFactor == 0) {
            num /= primeFactor;
        }
    }

    return distinctCount;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    buildSPF();

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int number;
        cin >> number;

        int k = countDistinctFactors(number);

       
        cout << (1LL << k) <<endl;
    }

    return 0;
}