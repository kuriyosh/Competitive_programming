/**
 * @author torith
 * @date 2019-01-12
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    int A, B; cin >> A >> B;
    vector<int> P;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        P.push_back(t);
    }

    sort(P.begin(),P.end());

    int first=0, second=0, third=0;
    for(auto &p : P){
        if(p <= A) first++;
        else if(A < p && p <= B) second++;
        else if(B < p) third++;
    }

    int ans = min(first, min(second, third));
    cout << ans << "\n";


    return 0;
}

