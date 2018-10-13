/**
 * @author torith
 * @date 2018-10-13
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int H,W;
    cin >> H >> W;
    char A[8][8];
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    int before = 0;
    for (int i = 0; i < H; ++i) {
        bool bfr_found = false;
        for (int j = 0; j < W; ++j) {
            if (j < before && A[i][j] == '#'){
                cout << "Impossible" << "\n";
                return 0;
            }else if (!bfr_found && j > before && A[i][j] == '.'){
                before = j - 1;
                bfr_found = true;
            }else if (j == before && A[i][j] == '.'){
                cout << "Impossible" << "\n";
                return 0;
            }else if (bfr_found && A[i][j] == '#'){
                cout << "Impossible" << "\n";
                return 0;
            }
        }
    }
    cout << "Possible" << "\n";

    return 0;
}

