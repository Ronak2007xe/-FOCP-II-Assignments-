#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000001;

int spf[MAXN];
unsigned char cnt[MAXN]; 

void sieve() {
    for (int i = 1; i < MAXN; i++) spf[i] = i;

    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

void precompute() {
    cnt[1] = 0;

    for (int i = 2; i < MAXN; i++) {
        int p = spf[i];
        int x = i / p;

        if (spf[x] == p)
            cnt[i] = cnt[x];      
        else
            cnt[i] = cnt[x] + 1;  
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    precompute();

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        cout << (1 << cnt[n]) << '\n';
    }

    return 0;
}