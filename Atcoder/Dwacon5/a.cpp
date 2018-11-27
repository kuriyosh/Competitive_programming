/**
 * @author torith
 * @date 2018-11-24
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    int a[100] = {};
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    double avg = (double)(sum) / N;

    double tmp = 1e9;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if(tmp > abs(avg - a[i])) {
            tmp = abs(avg - a[i]);
            ans = i;
        }
    }

    cout << ans << "\n";


    return 0;
}

