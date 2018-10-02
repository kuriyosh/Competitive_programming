/**
 * @author torith
 * @date 2018-10-01
 */

#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A;
    int minA = 1e9;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        tmp = abs(tmp-1);
        A.emplace_back(tmp);
        minA = min(minA,abs(tmp));
    }

    int ans = 0;
    for(auto & a:A){
        ans += a - minA;
    }
    cout << ans << "\n";
}
