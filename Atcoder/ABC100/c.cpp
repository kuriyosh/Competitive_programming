/**
 * @author torith
 * @date 2018-10-09
 */

#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int a[10000];
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        while (a[i] % 2 == 0){
            ans++;
            a[i] >>= 1;
        }
    }
    cout << ans << "\n";
}
