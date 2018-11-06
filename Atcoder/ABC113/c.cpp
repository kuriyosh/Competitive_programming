/**
 * @author torith
 * @date 2018-11-04
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;

    map<int,int> rec;
    vector<pair<int,int>> par;

    for (int i = 0; i < M; ++i) {
        int P,Y; cin >> P >> Y;
        rec[Y] = P;
        par.push_back(make_pair(P,Y));
    }

    int A[100001] = {};
    map<int,int> B;
    for(auto &m : rec){
        B[m.first] = A[m.second] + 1;
        A[m.second]++;
    }

    for (auto & p : par){
        cout << setfill('0') << right << setw(6) << p.first
             << setfill('0') << right << setw(6) << B[p.second] << "\n";
    }

    return 0;
}

