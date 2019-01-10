/**
 * @author torith
 * @date 2019-01-10
 * p.62 個数制限付き部分和問題
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    int a[100], m[100];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> m[i];
    }
    int K; cin >> K;

    // 配列の再利用を行うバージョンのDP
    // 基本DPの更新は1次元が1つ前のやつを確認すればよいので有効
    int dp[100001];
    fill(dp, dp + 100001, -1);

    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= K; ++j) {
            if(dp[j] >= 0) {
                dp[j] = m[i];   // 過去にjが作れるならそのままの値を格納
            }else if (j < a[i] || dp[j - a[i]] <= 0) {
                dp[j] = -1;     // 過去にjを作れない かつ j - a[i] になるパターンもないなら無理
            }else {
                dp[j] = dp[j - a[i]] - 1; // j-a[i]になるパターンがあるならOK
            }
        }
    }

    if(dp[K] >= 0) cout << "Yes" << "\n";
    else cout << "No" << "\n";

    return 0;
}

