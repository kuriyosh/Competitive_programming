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
    int N,M;
    cin >> N >> M;

    cout << (1900 * M + 100 * (N - M)) * pow(2,M) << "\n";

    return 0;
}
