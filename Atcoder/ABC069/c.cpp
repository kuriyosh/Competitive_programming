/**
 * @author torith
 * @date 2018-10-26
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    int four = 0, two = 0;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        if (t % 4 == 0) four ++;
        else if(t % 2 == 0) two ++;
    }

    if(two/2 + four >= N / 2){
        cout << "Yes" << "\n";
    }else{
        cout << "No" << "\n";
    }

    return 0;
}

