/**
 * @author torith
 * @date 2018-10-15
 */

#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> X;
    int tmp;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        X.push_back(tmp);
    }
    vector<int> Y = X;

    sort(Y.begin(),Y.end());
    int med = Y[Y.size()/2];
    int s_med = Y[Y.size()/2-1];

    for(auto &i : X){
        if (i >= med){
            cout << s_med << "\n";
        }else{
            cout << med << "\n";
        }
    }

    return 0;
}

