/**
 * @author torith
 * @date 2019-02-03
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    int sum = 0;
    int max_hen = 0;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        sum += t;
        max_hen = max(t, max_hen);
    }

    if(max_hen < sum - max_hen) cout << "Yes" << "\n";
    else cout << "No" << "\n";

    return 0;
}

