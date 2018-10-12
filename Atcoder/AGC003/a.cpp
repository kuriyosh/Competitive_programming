/**
 * @author torith
 * @date 2018-10-12
 */

#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    char S;
    bool n = false;
    bool s = false;
    bool w = false;
    bool e = false;
    while(cin >> S){
        if (S == 'N'){
            n = true;
        }else if (S == 'S'){
            s = true;
        }else if (S == 'W'){
            w = true;
        }else{
            e = true;
        }
    }

    if (((n && s) || (!n && !s)) && ((w && e) || (!w && !e))) cout << "Yes" << "\n";
    else cout << "No" << "\n";

    return 0;
}

