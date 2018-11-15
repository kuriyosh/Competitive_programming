/**
 * @author torith
 * @date 2018-11-13
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    string S; cin >> S;
    vector<string> a;
    auto i = S.find("+");
    int bef = 0;
    while(i != -1){
        a.push_back(S.substr(bef, i - bef));
        bef = i + 1;
        i = S.find("+", bef);
    }
    a.push_back(S.substr(bef, S.size() - bef));

    int ans = 0;
    for (auto & t : a){
        if(t.find('0') == -1) ans++;
    }

    cout << ans << "\n";

    return 0;
}

