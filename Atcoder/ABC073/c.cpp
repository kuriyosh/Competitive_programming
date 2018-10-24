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

    int A,B,C,D,E,F;
    cin >> A >> B >> C >> D >> E >> F;

    // ありえる水の容量を列挙
    int a = 0;
    vector<int> tmp = {};
    while(100 * A * a <= F){
        tmp.push_back(100 * A * a);
        a++;
    }

    vector<int> water;
    for(auto & w : tmp){
        int b = 0;
        while(w + 100 * B * b <= F){
            water.push_back(w + 100 * B * b);
            b++;
        }
    }

    // ありえる砂糖の容量を列挙
    a = 0;
    vector<int> tmp2 = {};
    while(C * a <= F){
        tmp2.push_back(C * a);
        a++;
    }

    vector<int> sugar = {};
    for(auto & s : tmp2){
        int b = 0;
        while(s + D * b <= F){
            sugar.push_back(s + D * b);
            b++;
        }
    }

    sort(water.begin(),water.end());
    sort(sugar.begin(),sugar.end());
    water.erase(unique(water.begin(), water.end()), water.end());
    sugar.erase(unique(sugar.begin(), sugar.end()), sugar.end());

    // あり得る砂糖の量を列挙
    double max_con = 0;
    int max_w,max_s;
    for(auto & w: water){
        for (auto & s: sugar){
            if (w+s <= F && (double) s/(w+s) <= (double) E/(100+E) && max_con < (double) s/(w+s)){
                max_con = (double) s/(w+s);
                max_w = w;
                max_s = s;
            }
        }
    }

    cout << (max_w+max_s) << " " << max_s << "\n";


    return 0;
}

