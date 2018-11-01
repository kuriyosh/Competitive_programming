/**
 * @author torith
 * @date 2018-10-31
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M; cin >> N >> M;

    if (N < M/2) {
        cout << N + (M - 2*N)/4 << "\n";
    }else if (N >= M/2) {
        cout << M/2 << "\n";
    }

    return 0;
}

