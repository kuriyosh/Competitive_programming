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
    int N; cin >> N;
    int a[100001] = {};
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    ll l = 0, r = 0;
    ll ans = 0;
    while (r < N){
        while(a[r] < a[r+1]) r++;
        ans += (r - l + 1) * (r - l + 2) / 2;
        r++;
        l = r;
    }

    cout << ans << "\n";

    return 0;
}

