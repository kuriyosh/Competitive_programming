/**
 * @author torith
 * @date 2019-02-05
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int factor_count[100] = {};
int N;

ll count_fact(int a){
    ll rtn = 0;
    for (int i = 0; i < N; ++i) {
        if(a - 1 <= factor_count[i]) rtn++;
    }
    return rtn;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 2; i < N + 1; ++i) {
        int base = i;
        for (int j = 2; j < i+1; ++j) {
            while(base % j == 0){
                factor_count[j] += 1;
                base /= j;
            }
        }
    }

    ll ans = count_fact(75) + count_fact(25) * (count_fact(3) - 1) +  count_fact(15) * (count_fact(5) - 1) + count_fact(5) * (count_fact(5) - 1) * (count_fact(3) - 2) / 2;
    cout << ans << "\n";

    return 0;
}


/*
 * 鬼のパクリ
 * 恥ずかしい
 */
