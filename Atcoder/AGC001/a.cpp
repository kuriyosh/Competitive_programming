/**
 * @author torith
 * @date 2018-10-12
 */

#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> L;
    int tmp;
    for (int i = 0; i < 2*N; ++i) {
        cin >> tmp;
        L.push_back(tmp);
    }
    sort(L.begin(),L.end());

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += min(L[2*i],L[2*i+1]);
    }

    cout << ans << "\n";

    return 0;
}

