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
        int even = 0, odd = 0;
        int max_even = 0, max_odd = 0;
        for (int j = 0; j < N; ++j) {
            if(i == j) continue;
            int l = min(i, j);
            int r = max(i, j);
            for (int k = 0; l + k <= r; ++k) {
                if(k % 2 == 0) even += A[l+k];
                else odd += A[l+k];
            }
            if(even > max_even){
                max_even = even;
                max_odd = odd;
            }
        }
        if(max_odd > ans){
            ans = max_odd;
        }
    }

    cout << ans << "\n";


    return 0;
}

