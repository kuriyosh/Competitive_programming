/**
 * @author torith
 * @date 2018-11-02
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int l, r;

    for (int i = 0; i < N; ++i) {
        int T,A;
        cin >> T >> A;

        if(i == 0){
            l = T;
            r = A;
            continue;
        }

        if (T < A) {
            if (l % T == 0) {
                r = l * A / T;
            }else {
                l += A % T;
                r = l * A / T;
            }
        }else if (T > A) {
            if (r % A == 0) {
                l = r * T / A;
            }else {
                r += T % A;
                l = r * T / A;
            }
        }else {
            l = max(l, r);
            r = max(l, r);
        }
        printf("l: %d, r: %d\n", l,r);
    }

    cout << l + r << "\n";

    return 0;
}

