/**
 * @author torith
 * @date 2018-10-15
 */

#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<int> A;
    int tmp;
    for (int i = 0; i < 3; ++i) {
        cin >> tmp;
        A.push_back(tmp);
    }

    sort(A.begin(),A.end());
    int first = A[2];
    int second = A[1];
    int third = A[0];

    int ans = 0;

    ans += (first - second) / 2;
    second += int ((first - second) / 2) * 2;
    ans += (first - third) / 2;
    third += int ((first - third) / 2) * 2;
    if ((first - second) == 1 && (first - third) == 1) {
        ans += 1;
    }else if (!( first - second == 0 && first - third == 0)) {
        ans += 2;
    }else{

    }

    cout << ans << "\n";

    return 0;
}

