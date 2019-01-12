/**
 * @author torith
 * @date 2019-01-12
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, H, W;
    cin >> N >> H >> W;

    cout << (N - H + 1) * (N - W + 1) << "\n";

    return 0;
}

