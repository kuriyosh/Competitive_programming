/**
 * @author torith
 * @date 2018-10-26
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    vector<int> edge[200000];
    for (int i = 0; i < M; ++i) {
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
    }

    for(auto &e : edge[1]){
        for(auto &e2 : edge[e]){
            if(e2 == N){
                cout << "POSSIBLE" << "\n";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << "\n";

    return 0;
}

