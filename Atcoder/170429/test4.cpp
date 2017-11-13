/*
 * test4.cpp
 */

//include files
#include <iostream>

using namespace std;

//DEFINE MACROS

//DEFINE CONSTANT
#define MAX 1000000000

//DEFINE PROTOTYPE

int max( int a,  int b){
  if(a>b) return a;
  else return b;
}

int main(){
  int W,w[100],v[100];
  int N;
  int dp[100][MAX];
  cin >> N;
  cin >> W;
  for (int i = 0; i < N; ++i) {
	cin >> w[i];
    cin >> v[i];
  }
  for (int j = 0; j <= W; j++) {
    dp[N][j] = 0;
  }
  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j <= W; j++) {
      if (j < w[i])
        dp[i][j] = dp[i + 1][j];
      else
        dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
    }
  }
  cout << dp[0][W] << endl;
}

