/*
 * 8.cpp
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

//DEFINE PROTOTYPE

int main(){
  string result[100];
  INT_IN(P);
  REP(i,P){
	  INT_IN(N);INT_IN(K);
	  if(N <= K){
		result[i] = "Win";
		continue;
	  }
	  if((N-1) % (K+1) == 0) result[i] = "Lose";
	  else result[i] = "Win";
  }
  REP(i,P) PRINTLN(result[i]);
}

