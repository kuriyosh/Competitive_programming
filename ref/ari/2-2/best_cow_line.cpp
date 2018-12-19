/**
 * @author torith
 * @date 2018-12-19
 * p.45 Best Cow Line
 */

// #include <bits/stdc++.h>
#include <string>
#include <iostream>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    char S[2000];
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    int left = 0;
    int right = N - 1;
    string ans = "";
    while(left <= right){
        bool left_frg = false;
        for (int i = 0; left + i <= right; ++i) {
            if(S[left + i] < S[right - i]){
                left_frg = true;
                break;
            }else if (S[left + i] > S[right - i]) {
                break;
            }
        }

        if(left_frg) ans += S[left++];
        else ans += S[right--];
    }

    cout << ans << "\n";

    return 0;
}

