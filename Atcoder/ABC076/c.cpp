/**
 * @author torith
 * @date 2018-10-24
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    // cin.tie(0);
    // ios::sync_with_stdio(false);
    string S,T;
    cin >> S;
    cin >> T;

    vector<string> cand;
    for (int i = 0; i < (int) (S.size() - T.size()) + 1; i++) {
        int frg = true;
        for (int j = i; j < (int) i + T.size(); ++j) {
            if (T[j - i] != S[j] && '?' != S[j]) frg = false;
        }
        if(frg){
            string a = S;
            a.replace(i,T.size(),T);
            replace(a.begin(),a.end(),'?','a');
            cand.push_back(a);
        }
    }

    if (cand.size() > 0) {
        sort(cand.begin(),cand.end());
        cout << cand[0] << "\n";
    }else{
        cout << "UNRESTORABLE" << "\n";
    }
    return 0;
}

