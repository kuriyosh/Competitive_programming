/**
 * @author torith
 * @date 2018-10-24
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    bool ans = true;
    int t=0,x=0,y=0;
    for (int i = 0; i < N; ++i) {
        int a,b,c;
        cin >> a >> b >> c;
        int diffxy = abs(b - x) + abs(c  - y);
        int difft = a - t;
        if( diffxy > difft || (diffxy - difft) % 2 != 0){
            ans = false;
        }
        t = a; x = b; y = c;
    }

    if (ans) {
        cout << "Yes" << "\n";
    }else{
        cout << "No" << "\n";
    }

    return 0;
}

