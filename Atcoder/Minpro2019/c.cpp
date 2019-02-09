/**
 * @author torith
 * @date 2019-02-09
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int K; cin >> K;
    int A; cin >> A;
    int B; cin >> B;

    if(B - A < 2) cout << K + 1 << "\n";
    else {
        ll ans = 1;
        int i = 0;
        while(i < K){
            if(A <= ans && i != K-1){
                ans = ans - A + B;
                i += 2;
            }else{
                ans++;
                i++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}

