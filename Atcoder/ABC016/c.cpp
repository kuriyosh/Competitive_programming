/**
 * @author torith
 * @date 2019-01-30
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    int M; cin >> M;

    int relation[10][10] = {};
    for (int i = 0; i < M; ++i) {
        int a; cin >> a;
        int b; cin >> b;
        relation[a-1][b-1] = 1;
        relation[b-1][a-1] = 1;
    }

    for (int i = 0; i < N; ++i) {
        bool visited[10] = {};
        int ans = 0;
        visited[i] = true;

        // 先に友達は候補から外す
        for (int j = 0; j < N; ++j) {
            if(relation[i][j] == 1) visited[j] = true;
        }

        for (int j = 0; j < N; ++j) {
            if(relation[i][j] == 1){
                for (int k = 0; k < N; ++k) {
                    if(!visited[k] && relation[j][k] == 1) {
                        ans ++;
                        visited[k] = true;
                    }
                }
            }
        }
        cout << ans << "\n";
    }


    return 0;
}

