/**
 * @author torith
 * @date 2018-10-30
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N; cin >> N;

    vector<int> div = {};            // 約数のリスト

    for (int i = 1; i < sqrt(N) + 1; i ++) {
        if (N % i == 0){
            div.push_back(i);
        }
    }

    int ans = to_string(N).size();
    for (auto & i : div){
        ans = min(ans, max((int)to_string(i).size(), (int)to_string(N/i).size()));
    }

    cout << ans << "\n";

    return 0;
}

