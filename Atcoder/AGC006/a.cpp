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

    int N;
    cin >> N;
    string s,t;
    cin >> s;
    cin >> t;

    int ans = 2 * N;
    string tmp;
    for (int i = 1; i <= N; ++i) {
        tmp = s.substr(N-i,i);
        if (tmp == t.substr(0,i)){
            ans = 2 * N - i;
        }
    }

    cout << ans << "\n";
    return 0;
}

