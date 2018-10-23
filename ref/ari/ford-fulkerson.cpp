/**
 * @author torith
 * @date 2018-10-23
 */

// Ford-Fulkersonのアルゴリズムがよくわからなかったから写経してみる

#include <bits/stdc++.h>

using namespace std;

struct edge {int to, cap ,rev;};

vector<edge> G[100];
bool used[100];

void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, (int)G[to].size()});
    G[to].push_back((edge){from, 0, (int)G[from].size()-1});
}

// 増加パスを深さ優先探索で探す
int dfs(int v, int t, int f){
    if (v == t) return f;
    used[v] = true;
    for (int i = 0; i < G[v].size(); ++i) {
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t){
    int flow = 0 ;
    while (1) {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, 1e9);
        if (f == 0) {
            return flow;
        }
        flow += f;
    }
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; ++i) {
        int a, b ,c;
        cin >> a >> b >> c;
        add_edge(a, b, c);
    }
    cout << max_flow(0,V-1) << "\n";


    return 0;
}

