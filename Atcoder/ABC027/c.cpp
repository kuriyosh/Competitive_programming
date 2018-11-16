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
    ll tmp = N;
    int height = 0;

    while(tmp != 1) {
        height++; tmp /= 2;
    }

    ll sum = 1;
    bool isTakahashi = false;
    if (height % 2 == 0) {
        while (sum <= N) {
            if(!isTakahashi){  // 高橋くんの番
                sum = sum * 2 + 1;
                isTakahashi = true;
            }else{              // 青木くんの番
                sum = sum * 2;
                isTakahashi = false;
            }
        }
    }else{
        while (sum <= N) {
            if(!isTakahashi){  // 高橋くんの番
                sum = sum * 2 ;
                isTakahashi = true;
            }else{              // 青木くんの番
                sum = sum * 2 + 1;
                isTakahashi = false;
            }
        }
    }

    if(!isTakahashi) cout << "Takahashi" << "\n";
    else cout << "Aoki" << "\n";

    return 0;
}

