/**
 * @author torith
 * @date 2018-10-10
 */

#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    char S[300000];
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    // 先頭がリーダとした時
    int ans = 0;
    for (int i = 1; i < N; ++i) {
        if(S[i] == 'E') ans++;
    }

    int tmp = ans;
    for (int i = 1; i < N; ++i) {
        if(S[i-1] == 'W') tmp++;
        if(S[i] == 'E') tmp--;
        ans = min(ans,tmp);
    }

    cout << ans << "\n";

    return 0;
}

