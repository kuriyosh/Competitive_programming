/**
 * @author torith
 * @date 2018-10-13
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    ll A,B,C;
    cin >> A >> B >> C;

    if (A % 2 == 0 || B % 2 == 0 || C % 2 == 0){
        cout << '0' << "\n";
        return 0;
    }

    ll ans = min(min(A*B,A*C),B*C);
    cout << ans << "\n";

    return 0;
}

