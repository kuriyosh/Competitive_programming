/**
 * @author torith
 * @date 2018-10-13
 */

#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    char X;
    char before = 'a';
    int S_cnt = 0;
    int ans = 0;
    while(cin >> X){
        if(X == 'S'){
            S_cnt += 1;
        }else if (X == 'T' && S_cnt > 0){
            ans -= 2;
            S_cnt -= 1;
        }
        ans += 1;
        before = X;
    }
    cout << ans << "\n";

    return 0;
}

