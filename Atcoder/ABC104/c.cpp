/**
 * @author torith
 * @date 2018-09-30
 */

#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int D,G;
    cin >> D >> G;
    vector<int> num_q,scores;
    for (int i = 0; i < D; ++i) {
        int a,b;
        cin >> a >> b;
        num_q.emplace_back(a);
        scores.emplace_back(b);
    }

    int tmp = 1;
    int dgt = 1;

    int ans = 1e9;
    for (int mask = 0; mask < (1<<D); ++mask) {
        int sum = 0;
        int tmp_ans = 0;
        int par_max = 0;

        // 全回答を加算 & 部分回答をする問題の種類を選ぶ
        int tmp_mask = mask;
        for (int i = 0; i < D; ++i) {
            if (tmp_mask & 1) {
                sum += 100 * (i + 1) * num_q[i] + scores[i];
                tmp_ans += num_q[i];
            }else{
                par_max = i;
            }
            tmp_mask = tmp_mask >> 1;
        }

        if (sum >= G) {
            ans = min(ans,tmp_ans);
        }else{
            // 部分回答を加算
            for (int j = 1; j < num_q[par_max]; ++j) {
                if (sum + 100 *(par_max + 1)  * j >= G){
                    tmp_ans += j;
                    ans = min(ans,tmp_ans);
                    break;
                }
            }
        }
    }

    cout << ans << "\n";
}
