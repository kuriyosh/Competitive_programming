/**
 * @author torith
 * @date 2018-11-08
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    map<int,int> rec1,rec2;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        if(i % 2 == 0){
            rec1[t]++;
        }else{
            rec2[t]++;
        }
    }

    vector<pair<int,int> > rrec1, rrec2;
    for(auto & r: rec1){
        rrec1.push_back(make_pair(r.second, r.first));
    }

    for(auto & r: rec2){
        rrec2.push_back(make_pair(r.second, r.first));
    }

    sort(rrec1.begin(), rrec1.end());
    sort(rrec2.begin(), rrec2.end());

    int ans = N;
    // 最大値が同じだったとき2番めにかえる　
    auto end1 = rrec1.rbegin();
    auto end2 = rrec2.rbegin();
    if(end1->second == end2->second){
        if ((end1+1) != rrec1.rend()) {
            ans = N - (end1+1)->first - end2->first;
        }else{
            ans = N - end2->first;
        }

        if ((end2+1) != rrec2.rend()) {
            ans = min(ans, N - (end2+1)->first - end1->first);
        }else{
            ans = min(ans, N - end1->first);
        }

    }else{
        ans -= end1->first + end2->first;
    }

    cout << ans << "\n";

    return 0;
}

