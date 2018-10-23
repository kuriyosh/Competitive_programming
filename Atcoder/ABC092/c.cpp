/**
 * @author torith
 * @date 2018-10-21
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int A[100001];
    A[0] = 0;
    int sum = 0;
    for (int i = 1; i < N+1; ++i) {
        cin >> A[i];
        sum += abs(A[i] - A[i-1]);
    }
    A[N+1] = 0;
    sum += abs(A[N+1] - A[N]);

    for (int i = 1; i < N+1; ++i) {
        cout << sum - abs(A[i] - A[i-1]) - abs(A[i+1] - A[i]) + abs(A[i+1] - A[i-1]) << "\n";
    }
    return 0;
}

