/**
 * @author torith
 * @date 2018-11-01
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;

    // A → B
    for (int i = 0; i < abs(sy - ty); ++i) {
        cout << "U";
    }

    for (int i = 0; i < abs(sx - tx); ++i) {
        cout << "R";
    }

    // B → A
    for (int i = 0; i < abs(sy - ty); ++i) {
        cout << "D";
    }

    for (int i = 0; i < abs(sx - tx); ++i) {
        cout << "L";
    }

    // A → B
    cout << "L" ;
    for (int i = 0; i < abs(sy - (ty + 1)); ++i) {
        cout << "U";
    }

    for (int i = 0; i < abs(sx - 1 - tx); ++i) {
        cout << "R";
    }
    cout << "D" ;

    // B → A
    cout << "R" ;
    for (int i = 0; i < abs(ty - (sy - 1)); ++i) {
        cout << "D";
    }

    for (int i = 0; i < abs(tx + 1 - sx); ++i) {
        cout << "L";
    }
    cout << "U" ;


    return 0;
}
