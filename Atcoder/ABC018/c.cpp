/**
 * @author torith
 * @date 2018-11-25
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int R, C, K; cin >> R >> C >> K;
    char G[500][500];
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> G[i][j];
        }
    }

    vector<vector<pair<int,int> > > updown(R,vector<pair<int, int> >(C, make_pair(0,0)));

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {

            if (G[i][j] == 'o') {
                // 上側をカウント
                int up = 0;
                for (int k = i; k >= 0; --k) {
                    if(G[k][j] == 'x') break;
                    up++;
                }

                // 下側をカウント
                int down = 0;
                for (int k = i; k < R; ++k) {
                    if(G[k][j] == 'x') break;
                    down++;
                }
                updown[i][j] = make_pair(up, down);
            }
        }
    }

    // updownを元にひし形をカウントする
    int ans = 0;
    for (int i = K - 1; i + K - 1 < R; ++i) {
        for (int j = K - 1; j + K - 1 < C; ++j) {
            if(updown[i][j].first >= K && updown[i][j].second >= K) {
                // 左側
                bool on_cnt = true;
                for (int k = 1; k < K; ++k) {
                    if(!(updown[i][j - k].first >= K - k && updown[i][j - k].second >= K - k)){
                        on_cnt = false;
                    }
                }

                if(!on_cnt) continue;

                // 右側
                for (int k = 1; k < K; ++k) {
                    if(!(updown[i][j + k].first >= K - k && updown[i][j + k].second >= K - k)){
                        on_cnt = false;
                    }
                }

                if(on_cnt) ans++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}

