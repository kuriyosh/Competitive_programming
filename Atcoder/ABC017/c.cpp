/**
 * @author torith
 * @date 2018-11-25
 * 方針: 全体から最も価値のない区間を使わないことにする
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M; cin >> N >> M;

    vector<int> a(100000);
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        int l, r, s;
        cin >> l >> r >> s;
        sum += s;
        a[l-1] += s;
        a[r] -= s;
    }

    int ims = 0;
    int min_sum = 1e9;
    for (int i = 0; i < M; ++i) {
        ims += a[i];
        min_sum = min(ims, min_sum);
    }

    cout << sum - min_sum << "\n";

    return 0;
}

