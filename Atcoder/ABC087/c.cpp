/**
 * @author torith
 * @date 2018-10-24
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int up[100] = {};
    int down[100] = {};
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        if (i == 0) up[i] = t;
        else up[i] += up[i-1] + t;
    }
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        sum += t;
        if (i != N - 1) down[i+1] = -t + down[i];
    }
    for (int i = 0; i < N; ++i) {
        down[i] += sum;
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = max(ans,up[i]+down[i]);
    }

    cout << ans << "\n";

    return 0;
}

