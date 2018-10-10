/**
 * @author torith
 * @date 2018-10-10
 */

#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int K;
    cin >> K;

    // substringの列挙
    vector<string> S;
    for (int i = min(K,int(s.size())); i > 0; --i) {
        int j = 0;
        while(j + i <= s.size()){
            S.push_back(s.substr(j, i));
            j++;
        }
    }

    // ソート＆重複削除
    sort(S.begin(),S.end());
    unique(S.begin(),S.end());

    cout << S[K-1] << "\n";

    return 0;
}

