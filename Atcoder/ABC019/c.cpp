/**
 * @author torith
 * @date 2018-11-22
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> a;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        while(t % 2 == 0){
            t /= 2;
        }
        a.push_back(t);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(),a.end()), a.end());

    cout << a.size() << "\n";

    return 0;
}

