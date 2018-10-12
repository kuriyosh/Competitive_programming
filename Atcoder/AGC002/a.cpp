/**
 * @author torith
 * @date 2018-10-12
 */

#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int a,b;
    cin >> a >> b;
    if (a > 0){
        cout << "Positive" << "\n";
        return 0;
    }else if((b == 0) || (a == 0) || (a < 0 && b > 0)){
        cout << "Zero" << "\n";
        return 0;
    }

    if((min(0,b) - a) % 2 == 0){
        cout << "Negative" << "\n";
    }else{
        cout << "Positive" << "\n";
    }


    return 0;
}

