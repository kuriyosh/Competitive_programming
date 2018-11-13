/**
 * @author torith
 * @date 2018-11-07
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct hint
{
    int x;
    int y;
    int h;
};

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<hint> hints;
    hint sample;
    for (int i = 0; i < N; ++i) {
        int x,y,h; cin >> x >> y >> h;
        hint a = {x, y, h};
        hints.push_back(a);
        if (h != 0) sample = a;
    }

    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 100; ++j) {
            bool frg = true;
            int height = abs(i - sample.x) + abs(j - sample.y) + sample.h;
            for (int k = 0; k < N; ++k) {
                int dis = abs(i - hints[k].x) + abs(j - hints[k].y);
                if (hints[k].h != max(height - dis, 0)) {
                    frg = false;
                    break;
                }
            }
            if(frg){
                cout << i << " " << j << " " << height << "\n";
                return 0;
            }
        }
    }


    return 0;
}

