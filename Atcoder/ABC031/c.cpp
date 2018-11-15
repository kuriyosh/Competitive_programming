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
    int N; cin >> N;

    int A[50] = {};
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int ans = -1e9;
    for (int i = 0; i < N; ++i) {
        int max_even = -1e9, max_odd = -1e9;
        for (int j = 0; j < N; ++j) {
            if(i == j) continue;
            int l = min(i, j);
            int r = max(i, j);
            int even = 0, odd = 0;
            for (int k = 0; l + k <= r; ++k) {
                if(k % 2 == 0) odd += A[l+k];
                else even += A[l+k];
            }
            if(even > max_even){
                max_even = even;
                max_odd = odd;
            }
        }
        ans = max(max_odd, ans);
    }

    cout << ans << "\n";

    return 0;
}

