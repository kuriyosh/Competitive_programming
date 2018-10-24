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

    int N; cin >> N;
    vector<int> A,B,C;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        A.push_back(t);
    }

    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        B.push_back(t);
    }

    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        C.push_back(t);
    }

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());

    int AB[100000] = {};
    int j = 0;
    for (int i = 0; i < N; ++i) {
        while(j < N){
            if(B[i] > A[j]){
                AB[i]++;
                j++;
            }else {
                break;
            }
        }
        AB[i+1] = AB[i];
    }

    j = 0;
    int CB[100000] = {};
    for (int i = 0; i < N; ++i) {
        while(j < N){
            if(B[i] < C[j]){
                CB[i] = N - j;
                break;
            }else j++;
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += CB[i] * AB[i];
    }

    cout << ans << "\n";


    return 0;
}

