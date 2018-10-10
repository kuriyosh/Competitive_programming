/**
 * @author torith
 * @date 2018-10-10
 */

#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int H,W;
    cin >> H >> W;

    char s[50][50];
    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < H; ++j) {
            cin >> s[j][i];
        }
    }

    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < H; ++j) {
            if (s[j][i] == '#'){
                if(j != 0 && s[j-1][i] == '#') continue; // 上
                else if(j != W-1 && s[j+1][i] == '#') continue; // 下
                else if(i != 0 && s[j][i-1] == '#') continue;   // 左
                else if(i != H-1 && s[j][i+1] == '#') continue; // 右
                cout << "No" << "\n";
                return 0;
            }
        }
    }
    cout << "Yes" << "\n";

    return 0;
}

