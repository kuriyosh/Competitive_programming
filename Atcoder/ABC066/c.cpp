/**
 * @author torith
 * @date 2018-10-27
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> a,b;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        if(i % 2 == 0) a.push_back(t);
        else b.push_back(t);
    }

    if(N % 2 == 0){
        // bを先に出していく
        for (int i = 0; i < b.size(); ++i) {
            cout << *(b.end()-1-i)  << " ";
        }
        for (auto &i: a){
            cout << i << " ";
        }
    }else{
        for (int i = 0; i < a.size(); ++i) {
            cout << *(a.end()-1-i)  << " ";
        }
        for (auto &i: b){
            cout << i << " ";
        }
    }
    return 0;
}

