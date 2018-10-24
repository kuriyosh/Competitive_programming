/**
 * @author torith
 * @date 2018-10-23
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[100];
int match[100];

bool dfs(int v, vector<int> visited){
    for (auto &u : edges[v]) {
        if (find(visited.begin(),visited.end(),v) != visited.end()) continue;
        visited.push_back(u);
        if (match[u] == -1 || dfs(match[u],visited)){
            match[u] = v;
            return true;
        }
    }
    return false;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int X,Y,E;
    cin >> X >> Y >> E;
    for (int i = 0; i < E; ++i) {
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
    }

    memset(match, -1 ,sizeof(match));

    int ans = 0;
    for (int i = 0; i < X; ++i) {
        vector<int> v {};
        if(dfs(i,v)) ans ++;
    }
    cout << ans << "\n";

    return 0;
}

