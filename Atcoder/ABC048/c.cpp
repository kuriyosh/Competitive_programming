/**
 * @author torith
 * @date 2018-11-01
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; ll x;cin >> N >> x;
    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ll t; cin >> t;
        sum += t;
        if (i > 0) {
            if(sum > x) {
                ans += sum - x;
                sum = max((ll) 0, t - sum + x);
            }else{
                sum = t;
            }
        }
    }

    cout << ans << "\n";


    return 0;
}

