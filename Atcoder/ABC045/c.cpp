/**
 * @author torith
 * @date 2018-11-03
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; cin >> S;
    ll ans = 0;
    for (int i = 0; i < S.size(); ++i) {
        int j = 1;
        while(i + j <= S.size()){
            int left = pow(2, max(0, i - 1));
            int right = pow(2, max(0, (int)S.size() - i - j - 1));
            ans += stoi(S.substr(i, j)) * left * right;
            j++;
        }
    }

    cout << ans << "\n";

    return 0;
}

