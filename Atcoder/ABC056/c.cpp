/**
 * @author torith
 * @date 2018-10-31
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N; cin >> N;

    cout << (ll) ceil((- 1 + sqrt(1 + 8 * N)) / 2)  << "\n";

    return 0;
}

