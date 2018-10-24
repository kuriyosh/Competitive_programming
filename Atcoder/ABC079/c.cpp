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
    int A[4];
    string tmp;
    cin >> tmp;
    A[0] = tmp[0] - '0';
    A[1] = tmp[1] - '0';
    A[2] = tmp[2] - '0';
    A[3] = tmp[3] - '0';

    for (int i = 0; i < 8; ++i) {
        int tmp_sum = A[0];
        int bit = 0;
        string ans = to_string(A[0]);
        while(bit < 3){
            if(i >> bit & 1) {
                // 足し算
                tmp_sum += A[bit+1];
                ans += "+" + to_string(A[bit+1]);
            }else{
                // 引き算
                tmp_sum -= A[bit+1];
                ans += "-" + to_string(A[bit+1]);
            }
            bit++;
        }
        if (tmp_sum == 7){
            ans += "=7";
            cout << ans << "\n";
            break;
        }
    }


    return 0;
}

