/**
 * @author torith
 * @date 2018-11-10
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    string def = "WBWBWWBWBWBW";
    string s; cin >> s;

    string ans;
    switch (s) {
    case "WBWBWWBWBWBWWBWBWWBW": {
        ans = "Do";
        break;
    }
    case "WBWWBWBWBWWBWBWWBWWB": {
        ans = "Re";
        break;
    }
    case "WWBWBWBWWBWBWWBWWBWB": {
        ans = "Mi";
        break;
    }
    case "WBWBWBWWBWBWWBWWBWBW": {
        ans = "Fa";
        break;
    }
    case "WBWBWWBWBWWBWWBWBWWB": {
        ans = "So";
        break;
    }
    case "WBWWBWBWWBWWBWBWWBWB": {
        ans = "Ra";
        break;
    }
    case "WWBWBWWBWWBWBWWBWBWB": {
        ans = "Si";
        break;
    }
    default:
        break;
    }

    cout << ans << "\n";

    return 0;
}

