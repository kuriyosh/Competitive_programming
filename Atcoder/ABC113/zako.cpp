w/**
 * @author torith
 * @date 2018-11-04
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;

    vector<int> pref_rec[100000];
    vector<pair<int,int>> rec;
    for (int i = 0; i < M; ++i) {
        int P,Y; cin >> P >> Y;
        pref_rec[P].push_back(Y);
        rec.push_back(make_pair(P, Y));
    }

    
    cout << std::setfill('0') << std::right << std::setw(6) << P << std::setfill('0') << std::right << std::setw(6) << pref[P] - 1 << "\n";

    return 0;
}

