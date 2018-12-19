/**
 * @author torith
 * @date 2018-12-19
 * p.47 Saruman's Army (POJ 3069)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int R; cin >> R;
    vector<int> X;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        X.push_back(t);
    }

    sort(X.begin(), X.end());

    int i = 0, ans = 0;
    while(i < N){
        int s = X[i];
        while(i < N && X[i] <= s + R) i++;

        int p = X[i - 1];

        while(i < N && X[i] <= p + R) i++;
        ans++;
    }

    cout << ans << "\n";

    return 0;
}

