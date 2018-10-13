/**
 * @author torith
 * @date 2018-10-12
 */

#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int ans = 0;
    int A[200000];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] == 0) {
            ans += 1;
        }
    }

    int base = 0;

    for (int i = 0; i < N; ++i) {
        base += A[i];
    }

    for (int len = N; len > 1; --len) {

        int tmp = base;
        int j = 0;
        while(1){
            cout << tmp << "\n";
            if (tmp == 0) ans += 1;
            if (j + len < N) {
                tmp -= A[j];
                tmp += A[j+len];
                j++;
            }else{
                break;
            }
        }

        base -= A[len-1];
    }

    cout << ans << "\n";

    return 0;
}

