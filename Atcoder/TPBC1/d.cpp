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
    int group_num = -1;
    for (int i = 1; i <= N; ++i) {
        if(i * (i-1) == 2 * N){
            group_num = i;
            break;
        }
    }

    if(group_num == -1){
        if(N == 1){
            cout << "Yes\n2\n1 1\n1 1\n";
        }else{
            cout << "No" << "\n";
        }
        return 0;
    }

    cout << "Yes" << "\n";
    cout << group_num << "\n";

    vector<int> group[100000];
    int a = 1;
    for (int i = 0; i < group_num; ++i) {
        cout << group_num-1;
        for (int j = 0; j < i; ++j) {
            group[i].push_back(group[i-1][i-1]);
            cout << " " << group[j][i-1] ;
        }
        for (int j = i; j < group_num - 1; ++j) {
            cout << " " << a;
            group[i].push_back(a++);
        }
        cout << "\n";
    }

    return 0;
}
