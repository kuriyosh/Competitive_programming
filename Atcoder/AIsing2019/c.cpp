/**
 * @author torith
 * @date 2019-01-12
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> d[160000];
char S[160401];
int memo[160000] = {};

int solve(int s, bool used[]){
    if(used[s]) return 0;
    if(memo[s] != -1) return memo[s];
    int rtn = 0;
    for (auto& t : d[s]) {
        if(S[t] != S[s])rtn ++;
        rtn += solve(t, used);
        used[t] = true;
    }
    memo[s] = rtn;
    return rtn;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    fill(memo, memo + 160000, -1);

    int H; cin >> H;
    int W; cin >> W;
    int N = H * W;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin  >> S[i * H + j];
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if(S[i * H + j] == '.'){
                if(S[(i + 1) * H + j] == '#'){
                    d[i * W + j].push_back((i + 1) * W + j);
                }
                if(S[i * H + j + 1] == '#'){
                    d[i * W + j].push_back(i * W + j + 1);
                }
            }else{
                if(S[(i + 1) * H] == '.') {
                    d[i * W + j].push_back((i + 1) * W + j);
                }
                if(S[i * H + j + 1] == '.') {
                    d[i * W + j].push_back(i * W + j + 1);
                }
            }
        }
    }

    int ans = 0;
    bool used[160000];
    for (int k = 0; k < N; ++k) {
        fill(used, used+160000, false);
        ans += solve(k, used);
        printf("[%d]%d\n", k, ans);
    }

    cout << ans << "\n";

    return 0;
}

