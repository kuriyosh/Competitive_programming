/**
 * @author torith
 * @date 2018-11-08
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K; cin >> N >> K;

    ll ans = 0;
    ll tmp = N/K;
    ans += tmp * tmp * tmp;

    if (K % 2 == 0) {
        tmp = N / (K/2) - N/K;
        ans += tmp * tmp * tmp;
    }

    cout << ans << "\n";

    return 0;
}

