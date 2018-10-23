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

    int x,y;
    cin >> x >> y;

    int ans = 1e9;

    if (y - x >= 0) {
        ans = y - x;
    }

    // 符号が違う
    if ((y > 0 && x < 0) || (y < 0 && x > 0)){
        if(abs(y) - abs(x) > 0) {
            ans = min(ans,abs(y)-abs(x)+1);
        }
    }else{
        if (x < 0 && abs(y)-abs(x) > 0){
            ans = min(ans,abs(y)-abs(x)+2);
        }
    }



    return 0;
}

