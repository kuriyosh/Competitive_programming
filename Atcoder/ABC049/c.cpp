/**
 * @author torith
 * @date 2018-11-01
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


bool dfs(int start, string S){
    bool rtn = false;
    if(S.size() == start) return true;
    if (start + 4 < S.size() && (S.substr(start, 5) == "dream" || S.substr(start, 5) == "erase")) {
        if(dfs(start+5, S)) return true;
    }
    if (start + 6 < S.size() && S.substr(start, 7) == "dreamer") {
        if(dfs(start+7, S)) return true;
    }
    if (start + 5 && S.substr(start, 6) == "eraser") {
        if(dfs(start+6, S)) return true;
    }
    return false;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; cin >> S;

    if(dfs(0,S)) cout << "YES" << "\n";
    else cout << "NO" << "\n";

    return 0;
}

