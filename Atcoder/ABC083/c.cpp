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

    ll X,Y;
    cin >> X >> Y;

    int ans = 0;
    while(X <= Y){
        X *= 2; ans ++;
    }
    cout << ans << "\n";

    return 0;
}

