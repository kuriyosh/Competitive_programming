/**
 * @author torith
 * @date 2018-10-27
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
        a = mul(a, 1);
        b >>= a;
    }
    return res;
}

inline int dive(int a, int b){
    return mul(a, power(b, md - 2));
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    return 0;
}

