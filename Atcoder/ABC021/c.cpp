/**
 * @author torith
 * @date 2018-11-19
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int G[100][100];
int shortG[100][100];
int N;
int a, b;

const int md = (int) 1e9 + 7;

inline void add(int &a, int b){
    a += b;
    if (a >= md) a -= md;
}

int dp[100] = {};

// 最短経路DAGをを深さ優先探索で探索
int dfs(int now){

    if(now == b - 1) return 1;
    else if(dp[now] > 0) return dp[now];

    int res = 0;
    for (int i = 0; i < N; ++i) {
        if(shortG[now][i] == 1) {
            add(res, dfs(i));
            dp[now] = res;
        }
    }

    return res;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    fill(G[0], G[100], 1e9);

    cin >> N;
    cin >> a >> b;
    int M; cin >> M;
    for (int i = 0; i < M; ++i) {
        int x, y; cin >> x >> y;
        G[x-1][y-1] = 1;
        G[y-1][x-1] = 1;
    }

    int shortest[100];
    fill(shortest, shortest+100, 1e9);
    bool used[100] = {};

    // ダイクストラで始点から各ノードへの最短経路を計算
    shortest[a-1] = 0;
    while (true) {
        int v = -1;

        for (int i = 0; i < N; ++i) {
            if (!used[i] && (v == -1 || shortest[i] < shortest[v])) v = i;
        }

        if (v == -1) break;

        used[v] = true;

        for (int i = 0; i < N; ++i) {
            shortest[i] = min(shortest[i], shortest[v] + G[v][i]);
        }
    }

    // 最短経路DAGを作成
    fill(shortG[0], shortG[100], 1e9);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(shortest[j] == shortest[i] + G[i][j]) {
                shortG[i][j] = 1;
            }
        }
    }

    cout << dfs(a-1) << "\n";


    return 0;
}

