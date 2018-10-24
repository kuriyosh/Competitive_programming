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
    vector<int> A;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        A.push_back(t);
    }

    sort(A.begin(),A.end());

    ll ans = 1;
    int cnt = 0;
    for (int i = N-1; i > 0; --i) {
        if(A[i-1] == A[i]){
            ans *= A[i];
            cnt++;
            i--;
        }
        if (cnt == 2){
            cout << ans << "\n";
            return 0;
        }
    }


    cout << 0 << "\n";

    return 0;
}

