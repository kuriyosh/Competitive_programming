/**
 * @author torith
 * @date 2019-02-03
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll power(ll a, ll r) {
    ll sum = 1;
    while (r > 0) {
        if ((r & 1) == 1) {
            sum *= a;
        }
        a *= a;
        r >>= 1;
    }
    return sum;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    ll K; cin >> K;

    int max_bit = 0;
    ll tmp = K;
    while(tmp != 0){
        tmp >>= 1;
        max_bit++;
    }

    vector<int> one(41);
    vector<int> zero(41);

    for (int i = 0; i < N; ++i) {
        ll t; cin >> t;
        for (int j = 0; j < 41; ++j) {
            ll tmp = t >> j;
            if((tmp & 1) == 1) {
                one[j] += 1;
                max_bit = max(j, max_bit);
            }
            else zero[j] += 1;
        }
    }


    ll dk = 0;
    ll ans = 0;
    for (int i = max_bit; i >= 0; --i) {
        if(one[i] >= zero[i] || dk + power(2,i) > K) {  // その桁に0を選ぶ
            ans += power(2, i) * one[i];
        }else{      // その桁に1を選ぶ
            ans += power(2, i) * zero[i];
            dk += power(2, i);
        }
    }

    cout << ans << "\n";


    return 0;
}

