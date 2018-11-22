/**
 * @author torith
 * @date 2018-11-21
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

struct edge {
    int to;
    int white;
    int black;
};

vector<edge> G[100];
int H, W;
ll T;

ll dijkstra(int s, int g, ll xcost){
    ll shortest[100];
    priority_queue<P, vector<P>, greater<P> > que;
    fill(shortest, shortest+100, 1e18);
    shortest[s] = 0;
    que.push(P(0, s));

    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if(shortest[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); ++i) {
            edge e = G[v][i];
            if(shortest[e.to] > shortest[v] + max((ll)(e.white), (ll)(e.black) * xcost)){
                shortest[e.to] = shortest[v] + max((ll)(e.white), (ll)(e.black) * xcost);
                que.push(P(shortest[e.to], e.to));
            }
        }
    }

    return shortest[g];
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W >> T;
    int start, goal;

    // グラフを作成
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            char t; cin >> t;
            edge e;
            if (t == '.'){
                e = {i * W + j, 1, 0};
            }else if (t == 'S') {
                e = {i * W + j, 1, 0};
                start = i * W + j;
            }else if (t == 'G') {
                e = {i * W + j, 1, 0};
                goal = i * W + j;
            }else if (t == '#') {
                e = {i * W + j, 0, 1};
            }
            if (i != 0) G[(i - 1) * W + j].push_back(e);
            if (i != H - 1) G[(i + 1) * W + j].push_back(e);
            if (j != 0) G[i * W + (j - 1)].push_back(e);
            if (j != W - 1) G[i * W + (j + 1)].push_back(e);
        }
    }

    int left = 0, right = T;
    while(right - left > 1){
        int med = (left + right) / 2;
        ll shortest = dijkstra(start, goal, med);
        if(shortest > T) right = med;
        else left = med;
    }

    cout << left << "\n";

    return 0;
}

