#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

string solve(int N, vector<int> A) {
    sort(A.begin(), A.end(), greater<int>());

    set<int> alexUsed, bobUsed;
    int alex = 0, bob = 0;
    bool alexTurn = true;

    for (int i = 0; i < N; i++) {
        if (alexTurn) {
            if (alexUsed.find(A[i]) == alexUsed.end()) {
                alex += A[i];
                alexUsed.insert(A[i]);
                alexTurn = false;
            }
        } else {
            if (bobUsed.find(A[i]) == bobUsed.end()) {
                bob += A[i];
                bobUsed.insert(A[i]);
                alexTurn = true;
            }
        }
    }

    if (alex > bob)
        return "Alex";
    else
        return "Bob";
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        cout << solve(N, A) << endl;
    }

    return 0;
}