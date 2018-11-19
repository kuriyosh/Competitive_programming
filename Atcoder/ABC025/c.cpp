/**
 * @author torith
 * @date 2018-11-18
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int b[2][3];
int c[3][2];

int score(int box[3][3]){
    int res = 0;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(box[i][j] == box[i+1][j]) res += b[i][j];
            else res -= b[i][j];
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            if(box[i][j] == box[i][j+1]) res += c[i][j];
            else res -= c[i][j];
        }
    }

    return res;

}

// 与えられたboxで打てる手の中で、直大くんの場合scoreが最大、直子さんの場合scoreが最小の手を採用しその時のscoreを返す
int follow(int box[3][3], int turn){

    int res_score;
    if(turn % 2 == 1) res_score = -1e9;
    else res_score = 1e9;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (box[i][j] == 0){
                if(turn % 2 == 1){ // 直大くんの番
                    box[i][j] = 1;
                    int tmp = follow(box, turn + 1);
                    res_score = max(tmp, res_score);
                }else{          // 直子さんの番
                    box[i][j] = -1;
                    int tmp = follow(box, turn + 1);
                    res_score = min(tmp, res_score);
                }
                box[i][j] = 0;
            }
        }
    }

    if(res_score == -1e9 || res_score == 1e9) return score(box);
    else return res_score;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int sum = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> b[i][j];
            sum += b[i][j];
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> c[i][j];
            sum += c[i][j];
        }
    }

    int box[3][3] = {};
    int ans = follow(box, 1);
    cout << (sum + ans) / 2 << "\n";
    cout << (sum - ans) / 2 << "\n";

    return 0;
}

