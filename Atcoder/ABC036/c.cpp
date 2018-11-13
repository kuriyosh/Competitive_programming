/**
 * @author torith
 * @date 2018-11-11
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> a;
    int b[100001];
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
        a.push_back(b[i]);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    map<int,int> tmp;
    for (int i = 0; i < a.size(); ++i) {
        tmp[a[i]] = i;
    }

    for (int i = 0; i < N; ++i) {
        cout << tmp[b[i]] << "\n";
    }

    return 0;
}
