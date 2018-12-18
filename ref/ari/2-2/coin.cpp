/**
 * @author torith
 * @date 2018-12-18
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int V[6] = {1, 5, 10, 50, 100, 500};
int S[6] = {};

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 6; ++i) {
        cin >> S[i];
    }
    int N; cin >> N;

    int ans = 0;
    for (int i = 5; i >= 0; --i) {
        int sub = min(S[i], N / V[i]);
        N -= V[i] * sub;
        ans += sub;
    }

    cout << ans << "\n";

    return 0;
}
