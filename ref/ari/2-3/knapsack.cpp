/**
 * @author torith
 * @date 2018-12-21
 * 01ナップサック問題
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dp[100][10000];

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<pair<int,int> > item;
    for (int i = 0; i < N; ++i) {
        int w, v;
        cin >> w >> v;
        item.push_back(make_pair(w,v));
    }
    int W; cin >> W;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (j >= item[i-1].first) {
                dp[i][j] = max(dp[i-1][j - item[i-1].first] + item[i-1].second, dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[N][W] << "\n";

    return 0;
}

