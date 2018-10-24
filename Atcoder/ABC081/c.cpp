/**
 * @author torith
 * @date 2018-10-24
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N,K;
    cin >> N >> K;

    map <int,int> cnt;

    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        cnt[t] = cnt[t] + 1;
    }

    int size = cnt.size();
    vector<int> vec;
    for (auto &m: cnt){
        vec.push_back(m.second);
    }
    sort(vec.begin(),vec.end());

    int ans = 0;
    int i = 0;
    while(size > K){
        size--;
        ans += vec[i++];
    }
    cout << ans << "\n";

    return 0;
}

