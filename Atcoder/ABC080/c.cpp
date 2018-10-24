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
    int A[100][10];
    int P[100][11];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 11; ++j) {
            cin >> P[i][j];
        }
    }

    int ans = -1e9;
    for (int i = 1; i < 1024; ++i) {

        // パターンiの各店舗との同時営業日を数える
        int bit = 0;
        int tmp[100] = {};
        while((i >> bit) > 0){
            if (i >> bit & 1){
                for (int j = 0; j < N; ++j) {
                    if (A[j][bit] == 1) tmp[j]++;
                }
            }
            bit++;
        }

        // 各店舗との同時営業日の数によって利益を加算
        int tmp_sum = 0;
        for (int j = 0; j < N; ++j) {
            tmp_sum += P[j][tmp[j]];
        }
        ans = max(tmp_sum,ans);
    }


    cout << ans << "\n";


    return 0;
}

