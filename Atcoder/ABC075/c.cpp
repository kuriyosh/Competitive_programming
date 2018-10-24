/**
 * @author torith
 * @date 2018-10-24
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int G[50][50] = {};
int N,M;

int solve(int i,int j,bool * visited){
    if(i == j) return 1;
    if(visited[i]) return 0;
    visited[i] = true;
    int sum = 0;
    for (int k = 0; k < N; ++k) {
        if(G[i][k]){
            sum += solve(k,j,visited);
        }
    }
    return sum;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a,b;
        cin >> a >> b;
        G[a-1][b-1] = 1;
        G[b-1][a-1] = 1;
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(G[i][j]){
                bool visited[50] = {};
                if (solve(i,j,visited) == 1) ans ++;
            }
        }
    }

    cout << ans/2 << "\n";


    return 0;
}

