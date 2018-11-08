/**
 * @author torith
 * @date 2018-11-07
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int A[100000];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    ll dp[100000];
    dp[0] = 0;
    dp[1] = abs(A[0] - A[1]);
    for (int i = 2; i < N; ++i) {
        dp[i] = min(dp[i-1] + abs(A[i] - A[i-1]), dp[i-2] + abs(A[i] - A[i-2]));
    }

    cout << dp[N-1] << "\n";

    return 0;
}

