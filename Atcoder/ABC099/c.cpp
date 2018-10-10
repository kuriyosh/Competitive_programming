/**
 * @author torith
 * @date 2018-10-10
 */

#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int dp[100000];
    for (int i = 0; i <= N; ++i) {
        dp[i] = 0;
    }

    for (int i = 1; i <= N; ++i) {
        // 1について
        dp[i] = dp[i-1] + 1;

        // 6について
        int j = 6;
        while(i - j >= 0){
            dp[i] = min(dp[i],dp[i-j] + 1);
            j *= 6;
        }

        // 9について
        j = 9;
        while(i - j >= 0){
            dp[i] = min(dp[i],dp[i-j] + 1);
            j *= 9;
        }
    }

    cout << dp[N] << "\n";
}
