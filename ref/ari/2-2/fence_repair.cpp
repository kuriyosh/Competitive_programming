/**
 * @author torith
 * @date 2018-12-19
 * p.49 Fence Repair
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> L;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        L.push_back(t);
    }

    int ans = 0;
    while(L.size() > 1){
        sort(L.begin(), L.end());
        L.push_back(L[0]+L[1]);
        ans += L[0]+L[1];
        L.erase(L.begin());
        L.erase(L.begin());
    }

    cout << ans << "\n";

    return 0;
}

