/**
 * @author torith
 * @date 2018-12-22
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll, ll> prime;

void prime_find(ll n){
    for (ll i = 2; i <= sqrt(n) + 2; i++) {
        while(n % i == 0){
            n /= i;
            prime[i]++;
        }
    }
    if(n > 1) prime[n]++;
    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, P; cin >> N >> P;

    if(N == 1) {
        cout << P << "\n";
        return 0;
    }

    prime_find(P);

    ll ans = 1;
    for(auto& i: prime) {
        if(i.second >= N) {
            ans *= pow(i.first, (i.second / N));
        };
    }
    cout << ans << "\n";

    return 0;
}

