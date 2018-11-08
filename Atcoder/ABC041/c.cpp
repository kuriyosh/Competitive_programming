/**
 * @author torith
 * @date 2018-11-07
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<pair<int,int> > A;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        A.push_back(make_pair(a, i+1));
    }

    sort(A.begin(),A.end());
    for (int i = N-1; i >= 0; --i) {
        cout << A[i].second << "\n";
    }

    return 0;
}

