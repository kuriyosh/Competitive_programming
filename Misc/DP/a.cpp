
/**
 * @author torith
 * @date 2018-10-01
 */

// 基本的なナップサック問題を解いてみる

#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N,W;
    cin >> N >> W;

    vector<int> weight,value;
    for (int i = 0; i < N; ++i) {
        int tmpA,tmpB;
        cin >> tmpA >> tmpB;
        weight.push_back(tmpA);
        value.push_back(tmpB);
    }

    int dp[100][10000];


    for (int i = 0; i < N; ++i) {

    }


}
