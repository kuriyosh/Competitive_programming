/**
 * @author torith
 * @date 2018-11-19
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int R, C, K; cin >> R >> C >> K;
    int N; cin >> N;
    int row[100000] = {};
    int column[100000] = {};
    vector<pair<int,int> > cell;
    for (int i = 0; i < N; ++i) {
        int r, c; cin >> r >> c;
        row[r-1]++;
        column[c-1]++;
        cell.push_back(make_pair(r-1,c-1));
    }


    int sum_row[100001] = {};
    int sum_column[100001] = {};
    for (int i = 0; i < R; ++i) {
        sum_row[row[i]]++;
    }
    for (int i = 0; i < C; ++i) {
        sum_column[column[i]]++;
    }
    ll ans = 0;
    for (int i = 0; i <= K; ++i) {
        ans += sum_row[i] * sum_column[K-i];
    }

    for (auto & c : cell) {
        if(row[c.first] + column[c.second] == K) ans--;
        else if(row[c.first] + column[c.second] == K+1) ans++;
    }

    cout << ans << "\n";

    return 0;
}

