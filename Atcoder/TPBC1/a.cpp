/**
 * @author torith
 * @date 2018-10-27
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    if (s.size() == 2) {
        cout << s << "\n";
    }
    else if (s.size() == 3){
        for (int i = s.size() - 1; i >= 0 ; --i) {
            cout << s[i] ;
        }
        cout << "\n";
    }

    return 0;
}

