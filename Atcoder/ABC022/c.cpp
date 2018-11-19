/**
 * @author torith
 * @date 2018-11-19
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dp[301][301];

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    vector<pair<int, int> > rec;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(i != j) dp[i][j] = 1e9;
            else dp[i][j] = 0;
        }
    }

    for (int i = 0; i < M; ++i) {
        int u, v, l; cin >> u >> v >> l;
        if(u == 1){
            rec.push_back(make_pair(v - 1, l));
        }else{
            dp[u-1][v-1] = l;
            dp[v-1][u-1] = l;
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i < rec.size(); ++i) {
        for (int j = i + 1; j < rec.size(); ++j) {
            ans = min(ans, dp[rec[i].first][rec[j].first] + rec[i].second + rec[j].second);
        }
    }

    if(ans == 1e9) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}

