/**
 * @author torith
 * @date 2019-02-03
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    int M; cin >> M;

    vector<int> X;
    for (int i = 0; i < M; ++i) {
        int t; cin >> t;
        X.push_back(t);
    }

    sort(X.begin(), X.end());

    vector<int> range;
    int before = -1e9;
    for (auto & x : X) {
        if(before != -1e9){
            range.push_back(x - before);
        }
        before = x;
    }

    sort(range.begin(), range.end(), greater<int>());

    ll ans = 0;
    for (int i = 0; i < range.size(); ++i) {
        if(i >= N - 1) ans += range[i];
    }
    cout << ans << "\n";


    return 0;
}

