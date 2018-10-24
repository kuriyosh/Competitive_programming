/**
 * @author torith
 * @date 2018-10-23
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    char c[10];
    int t[5] = {};
    for (int i = 0; i < N; ++i) {
        cin >> c;
        if (c[0] == 'M') t[0]++;
        else if (c[0] == 'A') t[1]++;
        else if (c[0] == 'R') t[2]++;
        else if (c[0] == 'C') t[3]++;
        else if (c[0] == 'H') t[4]++;
    }

    ll ans = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = i; j < 5; ++j) {
            if (i == j) continue;
            ll tmp = 1;
            for (int k = 0; k < 5; ++k) {
                if (k == i | k == j) continue;
                else if (t[k] == 0) tmp = 0;
                tmp *= t[k];
            }
            ans += tmp;
        }
    }
    cout << ans << "\n";


    return 0;
}

