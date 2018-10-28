/**
 * @author torith
 * @date 2018-10-28
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int W,H; cin >> W >> H;

    if(W % 3 == 0 || H % 3 == 0){
        cout << 0 << "\n";
        return 0;
    }

    int a = max(W,H);
    int b = min(W,H);

    // 3の等分を求める
    int tmp[3];
    for (int i = 0; i < 3; ++i) {
        tmp[i] = (a+i)/3;
    }

    int max_a = max(tmp[1] * b, b / 2 * (a - tmp[1]));
    max_a = max(max_a, (b - b/2) / 2 * (a - tmp[1]));
    int min_a = min(tmp[1] * b, b / 2 * (a - tmp[1]));
    min_a = min(min_a, (b - b/2) / 2 * (a - tmp[1]));
    int ans = max_a - min_a;

    max_a = max(tmp[1] * b, (a - tmp[1]) / 2 * b);
    max_a = max(max_a, (a - tmp[1] - (a - tmp[1]) / 2) / 2 * b);
    min_a = min(tmp[1] * b, (a - tmp[1]) / 2 * b);
    min_a = min(max_a, (a - tmp[1] - (a - tmp[1]) / 2) / 2 * b);
    ans = min(ans,max_a - min_a);

    cout << max_a - min_a << "\n";

    return 0;
}

