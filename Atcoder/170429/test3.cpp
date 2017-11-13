/*
 * test3.cpp
 */

//include files
#include<iostream>

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
  int N;
  long long int	T,push;
  long long int start,end;
  long long int sum= 0;
  cin >> N;
  cin >> T;
  start = 0;
  end = T;
  for (int i = 0; i < N; ++i) {
	cin >> push;

	if(i==0) continue;
	if(end > push){
	  end = push + T;
	}else{
	  sum += end - start;
	  start = push;
	  end = push + T;
	}
  }
  sum += end - start;
  cout << sum <<endl;
}

