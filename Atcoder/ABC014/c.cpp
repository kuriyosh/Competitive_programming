/**
 * @author torith
 * @date 2019-01-30
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<int> R(1000001);

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        int b; cin >> b;
        R[a] += 1;
        R[b+1] -= 1;
    }

    int sum = 0;
    for (int i = 0; i < R.size(); ++i) {
        sum += R[i];
        R[i] = sum;
    }

    int ans = *max_element(R.begin(), R.end());
    cout << ans << "\n";

    return 0;
}

