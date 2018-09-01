/*
 * test2.cpp
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
  int A,B,C,X;
  cin >> A;
  cin >> B;
  cin >> C;
  X=A%B;
  for(int k = 1 ; k < 10000 ; k++){
	if((X*k)%B == C){
	  cout << "YES" <<endl;
	  return 0;
	}
	if((X*k)%B == X && k!=1){
	  cout << "NO" << endl;
	  return 0;
	}
				  
  }
  
}

