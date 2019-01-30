/**
 * @author torith
 * @date 2019-01-31
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> prime;

void prime_find(ll n){
    for (ll i = 2; i <= sqrt(n) + 2; i++) {
        while(n % i == 0){
            n /= i;
            prime.push_back(i);
        }
    }
    if(n > 1) prime.push_back(n);
    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;

    int M = 2025 - N;

    // prime_find(M);

    for (int i = 1; i < 10; ++i) {
        if(M % i == 0 && M / i < 10 && i < 10) {
            printf("%d x %d\n", i, M / i);
        }
    }


    bool used[10] = {};
    for (int i = 0; i < pow(2, prime.size()); ++i) {
        int first = i;
        int r = 1, l = 1;
        for (int j = 0; j < prime.size(); ++j) {
            if(first & 1) {
                r *= prime[j];
            }else{
                l *= prime[j];
            }
            first = first >> 1;
        }
        if(l < 10 && r < 10 && !used[r]) {
            printf("%d x %d\n", r, l);
            used[r] = true;
        }
    }

    return 0;
}
