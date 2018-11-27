/**
 * @author torith
 * @date 2018-11-25
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct remain{
    int l;
    int r;
    int s;
};

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M; cin >> N >> M;

    vector<remain> remains;
    for (int i = 0; i < N; ++i) {
        int l, r, s;
        cin >> l >> r >> s;
        remain re = {l, r, s};
        remains.push_back(re);
    }

    int dp[100000] = {};
    bool visted[100000] = {};

    // DPの更新
    for (int i = 1; i < M; ++i) {
        if()
    }


    return 0;
}

