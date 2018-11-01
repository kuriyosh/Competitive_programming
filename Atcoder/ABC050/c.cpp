/**
 * @author torith
 * @date 2018-11-01
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int md = (int) 1e9 + 7;

inline void add(int &a, int b){
    a += b;
    if (a >= md) a -= md;
}

inline void sub(int &a, int b){
    a -= b;
    if (a < 0) a += md;
}

inline int mul(int a, int b){
    return (int) ((ll) a * b % md);
}

inline int power(int a, long long b){
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

inline int dive(int a, int b){
    return mul(a, power(b, md - 2));
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    int ans = 0;
    if(N % 2 == 1) ans = power(2,(N-1)/2);
    else ans = power(2,N/2);

    int A[100001] = {};
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        A[t]++;
    }

    if(N % 2 == 1){
        for (int i = 0; i < N/2 + 1; ++i) {
            if(i == 0 && A[i] != 1){
                cout << 0 << "\n";
                return 0;
            }else if(i != 0 && i % 2 == 0 && A[i] != 2){
                cout << 0 << "\n";
                return 0;
            }
        }
    }else {
        for (int i = 0; i < N/2 + 1; ++i) {
            if(i % 2 == 1 && A[i] != 2){
                cout << 0 << "\n";
                return 0;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}

