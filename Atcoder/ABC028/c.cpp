/**
 * @author torith
 * @date 2018-11-14
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int A,B,C,D,E;
    cin >> A >> B >> C >> D >> E;
    cout << max(E + D + A, E + C + B) << "\n";

    return 0;
}

