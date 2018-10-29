/**
 * @author torith
 * @date 2018-10-29
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K; cin >> N >> K;

    map<ll,ll> abpair;
    for (int i = 0; i < N; ++i) {
        ll a,b;
        cin >> a >> b;
        abpair[a] += b;
    }

    ll ans = 0;
    ll last = 0;
    for (auto & p: abpair) {
        ans += p.second;
        if (ans >= K) {
            cout << p.first << "\n";
            return 0;
        }
        last = p.first;
    }

    cout << last << "\n";

    return 0;
}

