/**
 * @author torith
 * @date 2018-10-23
 */

// Dinicのアルゴリズムがよくわからなかったから写経してみる

#include <bits/stdc++.h>

using namespace std;

struct edge {int to, cap ,rev;};

vector<edge> G[100];
int level[100];
int iter[100];

void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, (int)G[to].size()});
    G[to].push_back((edge){from, 0, (int)G[from].size()-1});
}

// sからの最短距離をBFSで計算する
void bfs(int s){
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    while(!que.empty()){
        int v = que.front(); que.pop();
        for (int i = 0; i < G[v].size(); ++i) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}


// 増加パスを深さ優先探索で探す
int dfs(int v, int t, int f){
    if (v == t) return f;
    for (int &i = iter[v]; i < G[v].size(); ++i) {
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]) {
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
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while((f = dfs(s, t, 1e9)) > 0){
            flow += f;
        }
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

