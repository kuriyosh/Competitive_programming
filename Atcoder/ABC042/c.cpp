/**
 * @author torith
 * @date 2018-11-06
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K; cin >> N >> K;
    char D[9];
    for (int i = 0; i < K; ++i) {
        cin >> D[i];
    }

    int ans = N;
    while(1) {
        if (N <= ans) {
            bool frg = true;
            string str_ans = to_string(ans);
            for (int i = 0; i < str_ans.size(); ++i) {
                for (int j = 0; j < K; ++j) {
                    if (D[j] == str_ans[i]) {
                        frg = false;
                    }
                }
                if(!frg) break;
            }
            if(frg) break;
        }
        ans++;
    }

    cout << ans << "\n";

    return 0;
}

