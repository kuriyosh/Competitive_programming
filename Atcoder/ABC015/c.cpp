/**
 * @author torith
 * @date 2019-01-30
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N;
int K;
int T[5][5];

bool solve(int depth, int value){
    if(depth == N) return (value == 0);
    for (int i = 0; i < K; ++i) {
        if(solve(depth+1, value^T[depth][i])) return true;
    }
    return false;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    cin >> K;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            cin >> T[i][j];
        }
    }

    for (int i = 0; i < K; ++i) {
        if(solve(1, T[0][i])) {
            cout << "Found" << "\n";
            return 0;
        }
    }

    cout << "Nothing" << "\n";

    return 0;
}

