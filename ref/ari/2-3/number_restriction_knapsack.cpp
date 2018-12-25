/**
 * @author torith
 * @date 2018-12-21
 * p.58 個数制限なしナップサック問題
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dpA[100][10000];
int dpB[100][10000];

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int v[100],w[100];
    for (int i = 0; i < N; ++i) {
        cin >> w[i] >> v[i];
    }
    int W; cin >> W;

    // 個数制限
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= W; ++j) {
            if(j >= w[i]){
                dpA[i+1][j] = max(dpA[i][j], dpA[i][j - w[i]] + v[i]); // ここが違うだけ
            }else{
                dpA[i+1][j] = dpA[i][j];
            }
        }
    }

    // 個数制限なし
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= W; ++j) {
            if(j >= w[i]){
                dpB[i+1][j] = max(dpB[i][j], dpB[i+1][j - w[i]] + v[i]);
            }else{
                dpB[i+1][j] = dpB[i][j];
            }
        }
    }

    cout << dpA[N][W] << "\n";

    cout << dpB[N][W] << "\n";

    return 0;
}

