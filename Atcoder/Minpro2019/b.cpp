/**
 * @author torith
 * @date 2019-02-09
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int path[4][4];
bool solve(int now, bool used[]){

    bool frag = true;
    for (int i = 0; i < 4; ++i) {
        if(!used[i]) frag = false;
    }
    if(frag) return true;

    for (int i = 0; i < 4; ++i) {
        if(!used[i] && path[now][i] == 1) {
            used[i] = true;
            if(solve(i, used)) return true;
            used[i] = false;
        }
    }
    return false;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);


    for (int i = 0; i < 3; ++i) {
        int a; cin >> a;
        int b; cin >> b;
        path[a-1][b-1] = 1;
        path[b-1][a-1] = 1;
    }

    for (int i = 0; i < 4; ++i) {
        bool used[4] = {};
        used[i] = true;
        if(solve(i, used)){
            cout << "YES" << "\n";
            return 0;
        }
    }

    cout << "NO" << "\n";

    return 0;
}

