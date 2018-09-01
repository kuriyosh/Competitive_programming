/*
 * test1.cpp
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
  string A,B,C;
  cin >> A;
  cin >> B;
  cin >> C;
  if(A[A.length()-1]==B[0] && B[B.length()-1]==C[0]) cout <<"YES"<<endl;
  else cout<<"NO"<<endl;
  
}

