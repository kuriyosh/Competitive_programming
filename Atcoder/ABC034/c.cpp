/**
 * @author torith
 * @date 2018-11-13
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
    int W, H; cin >> W >> H;

    int a = (W - 1) + (H - 1);

    int ans = 1;
    for (int i = a; i > 0; --i) {
        ans = mul(ans, i);
    }

    int w = 1;
    for (int i = W - 1; i > 0; --i) {
        w = mul(w, i);
    }

    int h = 1;
    for (int i = H - 1; i > 0; --i) {
        h = mul(h, i);
    }

    ans = dive(ans, w);
    ans = dive(ans, h);

    cout << ans << "\n";


    return 0;
}

