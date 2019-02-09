/**
 * @author torith
 * @date 2019-02-09
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    int K; cin >> K;

    if(N % 2 == 1) {
        if(N/2 + 1 >= K) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }else {
        if(N/2 >= K) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

    return 0;
}

