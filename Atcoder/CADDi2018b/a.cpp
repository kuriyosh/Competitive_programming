/**
 * @author torith
 * @date 2018-12-22
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    string a; cin >> a;
    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
        if(a[i] == '2') ans++;
    }
    cout << ans << "\n";


    return 0;
}
