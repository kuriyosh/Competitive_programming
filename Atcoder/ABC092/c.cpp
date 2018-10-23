/**
 * @author torith
 * @date 2018-10-15
 */

#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int A[100000];
    int sum = 0;
    for (int i = 0; i < N + 1; ++i) {
        cin >> A[i];
        sum += abs(A[i-1] - A[i]);
    }

    for (int i = 0; i < N + 1; ++i) {
        if(A[i]*A[i+1] <= 0) cout << sum - A[i] * 2 << "\n";
        else cout << sum << "\n";
    }

    return 0;
}
