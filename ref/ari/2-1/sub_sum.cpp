/**
 * @author torith
 * @date 2018-12-17
 * p.34 部分和問題
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, K, A[20];

bool dfs(int now, int sum){
    if(sum == K) return true;
    if(now >= N) return false;

    if(dfs(now+1, sum + A[now]) || dfs(now+1, sum)) return true;

    return false;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cin >> K;

    if(dfs(0,0)){
        cout << "Yes" << "\n";
    }else{
        cout << "No" << "\n";
    }

    return 0;
}

