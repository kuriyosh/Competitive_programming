/**
 * @author torith
 * @date 2019-02-01
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    int K; cin >> K;
    vector<pair<int,int>> sushi;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        int d; cin >> d;
        sushi.push_back({d, t});
    }

    sort(sushi.begin(), sushi.end(), greater<pair<int,int>>());

    // S(a)を求める
    int index = 0;
    set<int> used;
    ll S[100000] = {};
    priority_queue<int> selected_sushi;
    int tmp = 0;
    for (int i = 0; i < N; ++i) {
        selected_sushi.push(sushi[i].first);
        used.insert(sushi[i].second);
        tmp += sushi[i].first;
        index++;
    }

    S[used.size()] = tmp;

    // S(i) (a < i < K)を求める




    return 0;
}


/* MEMO
 * 全然わからんかった
 * 解説曰く、美味しさが高い寿司からまずK個取っていく(この時使った種類をa種類とする)
 * これは、言うまでもなくa種類寿司を食った時の満足度(S(a))の最大値であり
 * これをベースに a+1種類 寿司を食った時の満足度の最大値を求める
 * 具体的には、S(a)から最も美味しさの低いかつ種類が重複してるものを取り除き
 * S(a)の算出に使われていないa種類以外の寿司を食べる
 * 書くS(i) (a < i < 種類の数) から満足度を算出して最も高いものが答え
 */
