/**
 * @author torith
 * @date 2018-11-02
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    string s; cin >> s;
    char bef = s[0];
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(bef != s[i]) ans++;
        bef = s[i];
    }

    cout << ans << "\n";


    return 0;
}

