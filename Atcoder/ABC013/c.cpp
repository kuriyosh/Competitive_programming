/**
 * @author torith
 * @date 2019-01-30
 * 式変形でどうにかなる系だけど思い浮かばかなかった
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N; cin >> N;
    ll H; cin >> H;
    ll A; cin >> A;
    ll B; cin >> B;
    ll C; cin >> C;
    ll D; cin >> D;
    ll E; cin >> E;

    ll ans = 1e18;
    for (ll i = 0; i <= N; ++i) {
        ll t = max(((N - i) * E - H - i * B + (D + E)) / (D + E), 0ll);
        ans = min(ans, i * A + t * C);
    }

    cout << ans << "\n";

    return 0;
}

