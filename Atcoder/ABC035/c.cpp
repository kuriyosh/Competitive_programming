/**
 * @author torith
 * @date 2018-11-11
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q; cin >> N >> Q;

    ll A[200000] = {};
    for (int i = 0; i < Q; ++i) {
        int l, r; cin >> l >> r;
        A[l-1] += 1;
        A[r] -= 1;
    }

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += A[i];
        if(ans % 2 == 0) cout << "0";
        else cout << "1";
    }
    cout << "\n";


    return 0;
}

