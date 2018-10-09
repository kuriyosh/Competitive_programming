/**
 * @author torith
 * @date 2018-10-09
 */

#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,K;
    cin >> N >> K;
    int A[100000];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int ans;
    if ((N - K) % (K - 1) == 0) {
        ans = 1 + (N - K) / (K - 1);
    }else{
        ans = 2 + (N - K) / (K - 1);
    }
    cout << ans << "\n";
}
