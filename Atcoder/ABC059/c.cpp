/**
 * @author torith
 * @date 2018-10-29
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    ll sum1 = 0, sum2 = 0;
    ll ans1 = 0, ans2 = 0;
    for (int i = 0; i < N; ++i) {
        ll t; cin >> t;
        if (i == 0) {
            if (t == 0) {
                sum1 = 1; ans1 = 1;
                sum2 = -1; ans2 = 1;
            }else {
                sum1 = t;
                sum2 = t > 0 ? -1 : 1;
                ans2 += abs(t) + 1;
            }
        }
        else {
            if (sum1 < 0 && sum1 + t <= 0){
                ans1 += 1 - sum1 - t;
                sum1 = 1;
            }else if (sum1 > 0 && sum1 + t >= 0){
                ans1 += abs(-1 - sum1 - t);
                sum1 = -1;
            }else{
                sum1 += t;
            }

            if (sum2 < 0 && sum2 + t <= 0){
                ans2 += 1 - sum2 - t;
                sum2 = 1;
            }else if (sum2 > 0 && sum2 + t >= 0){
                ans2 += abs(-1 - sum2 - t);
                sum2 = -1;
            }else{
                sum2 += t;
            }
        }
    }
    cout << min(ans1, ans2) << "\n";

    return 0;
}

