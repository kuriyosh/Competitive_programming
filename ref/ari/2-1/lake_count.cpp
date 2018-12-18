/**
 * @author torith
 * @date 2018-12-17
 * p.37 迷路の最短経路
 */
#include <iostream>

using namespace std;

typedef long long ll;

char lake[100][100];
void dfs(int i, int j){
    if(i < 0 || i >= 100 || j < 0 || j >= 100) return;

    lake[i][j] = '.';
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if(dx == 0 && dy == 0) continue;
            if(lake[i - dx][j - dy] == 'W') {
                dfs(i - dx, j - dy);
            }
        }
    }
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int W, H; cin >> W >> H;
    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < H; ++j) {
            cin >> lake[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < H; ++j) {
            if(lake[i][j] == 'W'){
                dfs(i, j);
                ans ++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
