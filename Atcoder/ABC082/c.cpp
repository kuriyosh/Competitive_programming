/**
 * @author torith
 * @date 2018-10-24
 */

#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    map <int,int> cnt;
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        cnt[t] = cnt[t] + 1;
    }

    int ans = 0;
    for (auto &m : cnt){
        if(m.first <= m.second) ans += m.second - m.first;
        else ans += m.second;
    }

    cout << ans << "\n";


    return 0;
}

