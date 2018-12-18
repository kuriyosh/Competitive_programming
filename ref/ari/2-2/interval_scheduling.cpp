/**
 * @author torith
 * @date 2018-12-18
 * p43 区間スケジューリング問題
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<pair<int,int> > task;
    int N; cin >> N;
    for (int i = 0; i < N; ++i) {
        int S, T; cin >> S >> T;
        task.push_back(make_pair(T, S)); // 終了時間でソートしたいのでTをfirstに
    }

    sort(task.begin(), task.end());

    int end = task[0].first;
    int ans = 1;
    for (int i = 1; i < N; ++i) {
        if(end < task[i].second){
            end = task[i].first;
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}

