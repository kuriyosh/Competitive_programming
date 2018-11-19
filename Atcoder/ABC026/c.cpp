/**
 * @author torith
 * @date 2018-11-16
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> kaisya[21];

ll dfs(int now){
    if(kaisya[now].size() == 0) return 1;
    ll max_salary = 0, min_salary = 1e18;
    for (auto & k: kaisya[now]) {
        ll tmp = dfs(k);
        min_salary = min(min_salary, tmp);
        max_salary = max(max_salary, tmp);
    }
    return max_salary + min_salary + 1;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    for (int i = 1; i < N; ++i) {
        int t; cin >> t;
        kaisya[t].push_back(i+1);
    }

    cout << dfs(1) << "\n";

    return 0;
}

