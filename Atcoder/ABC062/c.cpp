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
    ll W,H; cin >> W >> H;

    if(W % 3 == 0 || H % 3 == 0){
        cout << 0 << "\n";
        return 0;
    }


    ll ans = 1e18;
    ll A,B,C;
    // Wを縮めていく
    for (int i = 1; i < W; ++i) {
        A = i * H;
        B = floor((W - i)/2) * H;
        C = (W - i - floor((W - i)/2)) * H;
        ans = min(ans, max(A, C) - min(A, B));

        B = (W - i) * floor(H/2);
        C = (W - i) * (H - floor(H/2));
        ans = min(ans, max(A, C) - min(A, B));
    }

    if(H == W){
        cout << ans << "\n";
        return 0;
    }

    // Hを縮めていく
    for (int i = 1; i < H; ++i) {
        A = i * W;
        B = floor((H - i)/2) * W;
        C = (H - i - floor((H-i)/2)) * W;
        ans = min(ans, max(A, C) - min(A, B));

        B = (H - i) * floor(W/2);
        C = (H - i) * (W - floor(W/2));
        ans = min(ans, max(A, C) - min(A, B));
    }

    cout << ans << "\n";

    return 0;
}

