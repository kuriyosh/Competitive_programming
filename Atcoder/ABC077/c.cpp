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
    vector<int> A,B,C;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        A.push_back(t);
    }

    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        B.push_back(t);
    }

    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        C.push_back(t);
    }

    sort(A.begin(),A.end());
    sort(C.begin(),C.end());

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ll l = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        ll r = C.end() - upper_bound(C.begin(), C.end(), B[i]);
        ans += l*r;
    }

    cout << ans << "\n";


    return 0;
}

