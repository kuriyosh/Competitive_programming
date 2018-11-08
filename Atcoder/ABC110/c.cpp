/**
g * @author torith
 * @date 2018-11-08
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    string S,T;
    cin >> S >> T;

    set<char> visited;
    for (int i = 0; i < S.size(); ++i) {
        if(S[i] != T[i]) {
            char s = S[i];
            char t = T[i];
            auto a = visited.find(S[i]);
            auto b = visited.find(T[i]);
            if(a != visited.end() || b != visited.end()){
                cout << "No" << "\n";
                return 0;
            }
            for (int j = i; j < S.size(); ++j) {
                if(S[j] == s){
                    S[j] = t;
                }else if (S[j] == t) {
                    S[j] = s;
                }
            }
        }
        visited.insert(T[i]);
    }

    if(S == T) cout << "Yes" << "\n";
    else cout << "No" << "\n";

    return 0;
}

