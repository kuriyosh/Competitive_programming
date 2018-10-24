/**
 * @author torith
 * @date 2018-10-23
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N,M;
    cin >> N >> M;

    if (N == 1 && M == 1){
        cout << 1 << "\n";
        return 0;
    }

    if (N == 1 || M == 1){
        cout << max(N,M) - 2 << "\n";
        return 0;
    }

    cout << N * M - (N * 2 + M * 2 - 4) << "\n";

    return 0;
}

