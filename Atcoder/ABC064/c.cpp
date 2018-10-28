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
    int N; cin >> N;
    bool a[8] = {};
    int rate_cnt = 0;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        if(0 < t && t < 400) a[0] = true;
        else if (399 < t && t < 800) a[1] = true;
        else if (799 < t && t < 1200) a[2] = true;
        else if (1199 < t && t < 1600) a[3] = true;
        else if (1599 < t && t < 2000) a[4] = true;
        else if (1999 < t && t < 2400) a[5] = true;
        else if (2399 < t && t < 2800) a[6] = true;
        else if (2799 < t && t < 3200) a[7] = true;
        else rate_cnt++;
    }

    int ans = 0;
    for (int i = 0; i < 8; ++i) {
        if(a[i]) ans++;
    }

    cout << max(ans,1) << " " << ans + rate_cnt << "\n";


    return 0;
}

