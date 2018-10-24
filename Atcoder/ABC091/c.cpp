/**
 * @author torith
 * @date 2018-10-23
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[100];
int match[100];

bool dfs(int v, bool * visited){
    for (auto &u : edges[v]) {
        if (visited[u]) continue;
        visited[u] = true;
        if (match[u] == -1 || dfs(match[u],visited)){
            match[u] = v;
            return true;
        }
    }
    return false;
}

int main(){

    // cin.tie(0);
    // ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<pair<int,int>> red;
    vector<pair<int,int>> blue;

    for (int i = 0; i < N; ++i) {
        int a,b;
        cin >> a >> b;
        red.push_back(make_pair(a,b));
    }

    for (int i = 0; i < N; ++i) {
        int a,b;
        cin >> a >> b;
        blue.push_back(make_pair(a,b));
        for (int j = 0; j < N; ++j) {
            if (red[j].first < a && red[j].second < b) {
                edges[j].push_back(i);
            }
        }
    }

    memset(match, -1 ,sizeof(match));

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        bool v[100] = {};
        if(dfs(i,v)) ans ++;
    }
    cout << ans << "\n";

    return 0;
}

