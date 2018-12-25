/**
 * @author torith
 * @date 2018-12-21
 * 01ナップサック問題その2
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
    int sum_value = 0;
    for (int i = 0; i < N; ++i) {
        int w, v;
        cin >> w >> v;
        sum_value += v;
        item.push_back(make_pair(w,v));
    }
    int W; cin >> W;

    // 無限で初期化する処理が必要
    
    // 基本的な knapsack 問題の2次元目をvalueにして、
    // i番目までの品物を使って合計をsumにするために必要な、weightの最小を求める問題にする。
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= sum_value; ++j) {
            if(j >= item[i-1].second) dp[i][j] = min(dp[i-1][j], dp[i-1][j-item[i-1].second] + item[i-1].first);
            else dp[i][j] = dp[i-1][j];
        }
    }

    int ans = 0;
    for (int i = sum_value; i > 0; --i) {
        if(dp[N][i] != 0 && dp[N][i] <= W) {
            ans = dp[N][i];
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}

