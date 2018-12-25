/**
 * @author torith
 * @date 2018-12-22
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    int H; cin >> H;
    int W; cin >> W;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int A,B; cin >> A >> B;
        if(H <= A && W <= B){
            ans ++;
        }
    }

    cout << ans << "\n";

    return 0;
}

