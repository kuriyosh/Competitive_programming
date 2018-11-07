/**
 * @author torith
 * @date 2018-11-06
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, A; cin >> N >> A;
    int a[50] = {};
    int max_a = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        max_a = max(a[i], max_a);
    }
    max_a = (A, max_a);

    vector<vector<vector<ll>>> dp(N+1,vector<vector<ll>>(N+1, vector<ll>(max_a * N + 1,0)));
    dp[0][0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
            for (int k = 0; k <= N*max_a; ++k) {
                if (j >= 1 && k >= a[i-1]) {
                    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k-a[i-1]];
                }else if (k < a[i-1]) {
                    dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans += dp[N][i][i*A];
    }

    cout << ans << "\n";

    return 0;
}

