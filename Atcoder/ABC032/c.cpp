/**
 * @author torith
 * @date 2018-11-13
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K; cin >> N >> K;
    ll A[100000];
    bool zero_frg = false;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if(A[i] == 0) zero_frg = true;
    }

    if(zero_frg) {
        cout << N << "\n";
        return 0;
    }

    int ans = 0;
    ll mul = 1;
    int l = 0;
    for (int i = 0; i < N; ++i) {
        mul *= A[i];
        if (mul <= K) {
            ans = max(i - l + 1, ans);
        } else if (mul > K) {
            while(mul > K && l <= i) {
                mul /= A[l];
                l++;
            }
            if (mul <= K) ans = max(i - l + 1, ans);
        }
    }

    cout << ans << "\n";

    return 0;
}

