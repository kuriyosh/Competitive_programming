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
    int N, K; cin >> N >> K;
    ll ans = 0;
    ll tmp_sum = 0;
    queue<ll> rec;
    for (int i = 0; i < N; ++i) {
        ll a; cin >> a;
        tmp_sum += a;
        rec.push(a);
        if(i + 1 >= K){
            ans += tmp_sum;
            tmp_sum -= rec.front();
            rec.pop();
        }
    }

    cout << ans << "\n";

    return 0;
}

