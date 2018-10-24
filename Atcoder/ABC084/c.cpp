/**
 * @author torith
 * @date 2018-10-24
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;

    int C[500],S[500],F[500];
    for (int i = 0; i < N - 1; ++i) {
        int c,s,f;
        cin >> c >> s >> f;
        C[i] = c;
        S[i] = s;
        F[i] = f;
    }

    for (int i = 0; i < N - 1; ++i) {
        ll ans = 0;
        ans += S[i] + C[i];
        for (int j = i + 1; j < N - 1; ++j) {
            if (ans <= S[j]) ans = S[j] + C[j];
            else {
                int a = S[j];
                while(a < ans) a += F[j];
                ans = a + C[j];
            }
        }
        cout << ans << "\n";
    }
    cout << "0" << "\n";

    return 0;
}

