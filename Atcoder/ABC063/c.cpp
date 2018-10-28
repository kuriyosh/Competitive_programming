/**
 * @author torith
 * @date 2018-10-28
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int sum = 0;
    vector<int> s;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        s.push_back(t);
        sum += t;
    }

    if(sum % 10 != 0){
        cout << sum << "\n";
        return 0;
    }

    sort(s.begin(),s.end());

    for (auto & a: s){
        if (a % 10 != 0) {
            cout << sum - a << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
    return 0;
}

