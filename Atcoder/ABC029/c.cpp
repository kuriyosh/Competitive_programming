/**
 * @author torith
 * @date 2018-11-14
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(string s, int len){
    if(s.size() == len) {
        cout << s << "\n";
        return;
    }
    solve(s + "a", len);
    solve(s + "b", len);
    solve(s + "c", len);
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;

    solve("", N);


    return 0;
}

