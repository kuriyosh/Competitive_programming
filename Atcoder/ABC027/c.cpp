/**
 * @author torith
 * @date 2018-11-15
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N; cin >> N;
    if(N == 1){
        cout << "Aoki" << "\n";
        return 0;
    }else if (N == 2) {
        cout << "Takahashi" << "\n";
        return 0;
    }

    ll a = N / 2 + 1;
    int cnt = 0;
    while (a != 1) {
        if(a % 2 == 0) a = a / 2;
        else a = a / 2 + 1;
        cnt ++;
    }

    if(cnt % 2 == 0) cout << "Aoki" << "\n";
    else cout << "Takahashi" << "\n";

    return 0;
}

