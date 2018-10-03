/**
 * @author torith
 * @date 2018-10-01
 */

#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int sum = 0;
    vector<int> A;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        A.emplace_back(tmp - (i + 1));
        sum += tmp - (i + 1);
    }

    int ans = 0;

    // 切り上げ
    int b;
    if (sum > 0) {
        b = (sum + N - 1) / N;
    }else{
        b = (sum - N + 1) / N;
    }
    for (auto & i: A){
        ans += abs(i-b);
    }

    // 切り捨て
    b = sum / N;
    int tmp = 0;
    for (auto & i: A){
        tmp += abs(i-b);
    }
    ans = min(tmp,ans);

    cout << ans << "\n";
}
