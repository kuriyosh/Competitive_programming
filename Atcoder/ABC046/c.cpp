/**
 * @author torith
 * @date 2018-11-02
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    ll l, r;
    for (int i = 0; i < N; ++i) {
        ll T,A;
        cin >> T >> A;

        if(i == 0){
            l = T;
            r = A;
            continue;
        }


        ll a = max((l + (T - 1)) / T, (r + (A - 1)) / A);
        l = a * T;
        r = a * A;

    }

    cout << l + r << "\n";

    return 0;
}

