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

    int N; cin >> N;
    vector<int> a;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        a.push_back(t);
    }

    sort(a.begin(), a.end());

    // 中央値付近で全探索
    ll ans = 1e18;
    for (int i = -100; i <= 100; ++i) {
        ll tmp = 0;
        for(auto & sa : a){
            tmp += pow(sa-i,2);
        }
        ans = min(ans, tmp);
    }

    cout << ans << "\n";

    return 0;
}

