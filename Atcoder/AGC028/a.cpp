/**
 * @author torith
 * @date 2018-10-13
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return (a * b / gcd(a, b));
}


int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    char S[100000],T[100000];
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> T[i];
    }
    ll L = lcm(N,M);

    ll a = lcm(L/N,L/M);
    ll i = 1;
    while (i <= L){
        if (S[(i-1)/(L/N)] != T[(i-1)/(L/M)]){
            cout << "-1" << "\n";
            return 0;
        }
        i += a;
    }

    cout << L << "\n";

    return 0;
}

