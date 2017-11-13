/*
 * alds1-1-d.cpp
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
  int r;
  long long int summax=-10000000000,min=1000000000;
  INT_IN(n);
  for (int i = 0; i < n; ++i) {
	cin >> r;
	if (r-min > summax){
	  summax = r-min;
	  if (min > r) min = r;
	}
  }
  cout << summax <<endl;
}

