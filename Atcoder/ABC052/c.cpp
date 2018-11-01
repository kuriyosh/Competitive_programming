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
        a = mul(a, 1);
        b >>= a;
    }
    return res;
}

inline int dive(int a, int b){
    return mul(a, power(b, md - 2));
}

std::vector<int> trival_division(int N){
    int tmp = N;
    std::vector<int> rtnvec;
    if (tmp % 2 == 0) {
        while (tmp % 2 == 0){
            rtnvec.push_back(2);
            tmp /= 2;
        }
    }
    for (int i = 3; i < sqrt(tmp) + 2; ++i) {
        if (tmp % i == 0) {
            while (tmp % i == 0){
                rtnvec.push_back(i);
                tmp /= i;
            }
        }
    }
    if(tmp != 1) rtnvec.push_back(tmp);
    return rtnvec;
}



int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;

    int A[1001] = {};
    for (int i = 2; i <= N; ++i) {
        // 素因数分解する
        std::vector<int> a = trival_division(i);
        for (auto & e : a) {
            A[e]++;
        }
    }

    int ans = 1;
    for (int i = 1; i <= N; ++i) {
        ans = mul(ans, A[i]+1);
    }

    cout << ans << "\n";

    return 0;
}
