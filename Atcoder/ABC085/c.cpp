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
    int N,Y;
    cin >> N >> Y;

    int tmp = Y / 1000 - N;
    bool ans = false;
    for (int i = 0; 9 * i <= tmp; ++i) {
        int hm = (tmp - 9 * i);
        if(hm % 4 == 0 && (N - hm/4 - i) >= 0){
            cout << i << " " << hm/4 << " " << (N - hm/4 - i) << "\n";
            return 0;
        }
    }
    cout << "-1 -1 -1" << "\n";

    return 0;
}

