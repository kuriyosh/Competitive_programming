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
    ll A,B;
    int K;
    cin >> A >> B >> K;

    for (int i = 0; i < K; ++i) {
        if(i % 2 == 0){
            if (A % 2 != 0) {
                A -= 1;
            }
            B += A / 2;
            A /= 2;
        }else{
            if (B % 2 != 0) {
                B -= 1;
            }
            A += B / 2;
            B /= 2;
        }
    }

    cout << A << " " << B << endl;

    return 0;
}

