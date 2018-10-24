/**
 * @author torith
 * @date 2018-10-24
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    ll t = gcd(a, b);
    return (a / t * b);
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    ll ans = 1LL;
    for (int i = 0; i < N; ++i) {
        ll t;
        cin >> t;
        ans = lcm(ans,t);
    }

    cout << ans << "\n";

    return 0;
}

