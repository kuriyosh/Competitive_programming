/**
 * @author torith
 * @date 2018-11-04
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    double T,A; cin >> T >> A;

    int ans = 0;
    double diff = 1e9;
    for (int i = 0; i < N; ++i) {
        int H; cin >> H;
        if (diff > abs(T - H * 0.006 - A)){
            ans = i;
            diff = (abs(T - H * 0.006 - A));
        }
    }

    cout << ans+1 << "\n";

    return 0;
}

