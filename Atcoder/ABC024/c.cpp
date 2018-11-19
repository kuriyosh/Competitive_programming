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
    int N, D, K; cin >> N >> D >> K;

    vector<pair<int,int> > LR;
    for (int i = 0; i < D; ++i) {
        int L, R; cin >> L >> R;
        LR.push_back(make_pair(L, R));
    }

    vector<pair<int,int> > ST;
    for (int i = 0; i < K; ++i) {
        int S, T; cin >> S >> T;
        ST.push_back(make_pair(S, T));
    }

    int ans = 1;
    for (auto & st : ST) {
        int now_pos = st.first;
        int tmp_turn = 1;
        for (auto & lr : LR) {
            if (lr.first <= now_pos && now_pos <= lr.second) { // 移動可能
                if (lr.first <= st.second && st.second <= lr.second) break; // ゴール
                if (now_pos < st.second){
                    now_pos = lr.second;
                }else{
                    now_pos = lr.first;
                }
            }
            tmp_turn++;
        }
        cout << tmp_turn << "\n";
    }

    return 0;
}

