/**
 * @author torith
 * @date 2018-11-14
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    int X, Y; cin >> X >> Y;
    vector<pair<int,int> > sum;
    ll now_time;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        sum.push_back(make_pair(t, 1));
        if(i == 0) now_time = t;
    }

    for (int i = 0; i < M; ++i) {
        int t; cin >> t;
        sum.push_back(make_pair(t, 2));
    }

    sort(sum.begin(), sum.end());

    bool now_a = false;
    int ans = 0;
    for (auto & m : sum){
        if(now_a && m.second == 1 && m.first >= now_time + Y) { // Aにいる時
            now_time = m.first;
            now_a = !now_a;
        }else if(!now_a && m.second == 2 && m.first >= now_time + X){ // Bにいる時
            now_time = m.first;
            ans++;
            now_a = !now_a;
        }
    }

    cout << ans << "\n";

    return 0;
}

