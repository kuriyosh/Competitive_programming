/**
 * @author torith
 * @date 2018-11-09
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;

    string ans = "";
    while(N != 0){
        int r = N % 2;
        if(N % 2 == 0) ans = "0" + ans;
        else ans = "1" + ans;

        if(r < 0) r = 1;

        N = (N - r) / (-2);
    }

    if(ans.size() == 0) cout << "0" << "\n";
    else cout << ans << "\n";

    return 0;
}

