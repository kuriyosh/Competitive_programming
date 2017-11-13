/*
 * 3.cpp
 */

//include files
#include<bits/stdc++.h>

using namespace std;

//DEFINE MACROS
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define INT_IN(a) int a; cin >> a
#define STR_IN(s) string s; cin >> s
#define PRINTLN(s) cout << s << endl
#define PRINTDOUBLELN(s) cout << setprecision(12) << (s) << endl;

//DEFINE CONSTANT
int N;
int binary[10000];
int arrive[10000];
//DEFINE PROTOTYPE
int grid(int i,int path);

int main(){
  int tmp;
  cin >> N;
  FOR(i,1,N+1){
	tmp = i;
	binary[i] = 0;
	arrive[i] = 0;
	while(tmp != 0){
	  binary[i] += tmp%2;
	  tmp = tmp / 2;
	}
	PRINTLN(binary[i]);
  }
  int ans = grid(1,1);
  if(ans == 10000000) PRINTLN(-1);
  else PRINTLN(ans);
}

int grid(int now,int path){
  int up,down;
  if(now == N) return path;
  if(arrive[now] == 1) return 10000000;
  arrive[now] = 1;
  if(now < 1 || now > N ) return 10000000;
  up = grid(now+binary[now],path+1);
  down = grid(now-binary[now],path+1);
  return MIN(up,down);
}
