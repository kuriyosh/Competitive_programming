/**
 * @author torith
 * @date 2018-12-21
 * p.56 最長共通部分列問題
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
char s[1000], t[1000];
int dp[1000][1000];

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int m; cin >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> t[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(s[i] == t[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            }else{
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }

    cout << dp[n][m] << "\n";

    return 0;
}

