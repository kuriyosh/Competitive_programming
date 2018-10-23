/**
 * @author torith
 * @date 2018-10-21
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<pair<int,int>> red;
    vector<pair<int,int>> blue;

    for (int i = 0; i < N; ++i) {
        int a,b;
        cin >> a >> b;
        red.push_back(make_pair(a,b));
    }

    for (int i = 0; i < N; ++i) {
        int a,b;
        cin >> a >> b;
        blue.push_back(make_pair(a,b));
    }

    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < blue.size(); ++j) {
            if (red[i].first < blue[j].first && red[i].second < blue[j].second) {
                blue.erase(blue.begin() + j);
                ans ++;
                break;
            }
        }
    }

    cout << ans << "\n";


    return 0;
}
