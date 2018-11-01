/**
 * @author torith
 * @date 2018-10-31
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N; cin >> N;

    ll ans = (N / 11) * 2;
    if (N % 11 == 0) cout << ans << "\n";
    else if (N % 11 > 6) cout << ans + 2 << "\n";
    else cout << ans + 1 << "\n";

    return 0;
}
