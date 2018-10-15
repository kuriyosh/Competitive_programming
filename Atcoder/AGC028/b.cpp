/**
 * @author torith
 * @date 2018-10-13
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int A[100000];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    ll sum = 0;
    int base = 0;
    ll base_sum = 0;

    for (int i = 0; i < N; ++i) {
        base_sum += A[i];
    }

    ll bef_base_sum;
    for (int len = N; len > 0; --len) {
        base = 0;

        sum += base_sum * len * max(int(pow(2,N-len-1)),1);

        bef_base_sum = base_sum;
        while (base + len < N - 1) {
            base_sum -= A[base];
            base_sum += A[base+len];
            sum += base_sum * len * max(int(pow(2,N-len-2)),1);
            base++;
        }

        sum += base_sum * len * max(int(pow(2,N-len-1)),1);

        base_sum = bef_base_sum - A[len-1];

    }

    cout << sum << "\n";



    return 0;
}

