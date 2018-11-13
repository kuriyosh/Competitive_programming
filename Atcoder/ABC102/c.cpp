/**
 * @author torith
 * @date 2018-10-01
 */

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> A;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        A.push_back(t - i - 1);
    }

    sort(A.begin(), A.end());
    if(A.size() == 0) {
        cout << "0" << "\n";
        return 0;
    }

    ll ans = 0;
    if(A.size() % 2 == 0){
        for (int i = 0; i < N; ++i) {
            ans += abs((ll) (A[i] - A[A.size()/2]));
        }

        ll tmp = 0;
        for (int i = 0; i < N; ++i) {
            tmp += abs((ll) (A[i] - A[A.size()/2-1]));
        }
        ans = min(tmp, ans);

    }else{
        for (int i = 0; i < N; ++i) {
            ans += abs((ll) (A[i] - A[A.size()/2]));
        }
    }

    cout << ans << "\n";
}
