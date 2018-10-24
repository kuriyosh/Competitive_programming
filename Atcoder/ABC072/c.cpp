/**
 * @author torith
 * @date 2018-10-24
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int a[100000] = {};
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        a[t]++;
    }

    int ans = 0;
    for (int i = 0; i < 100000 - 2; ++i) {
        ans = max(ans,a[i]+a[i+1]+a[i+2]);
    }
    cout << ans << "\n";

    return 0;
}

