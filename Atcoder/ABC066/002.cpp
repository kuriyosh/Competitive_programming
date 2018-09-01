/*
 * 002.cpp
 */

//include files
#include<bits/stdc++.h>

using namespace std;

//DEFINE MACROS
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define PRINTLN(s) cout << s << endl

//DEFINE CONSTANT

//DEFINE PROTOTYPE

int main(){
  string s;
  cin >> s;

  for (int i = 1 ; i  < s.length();++i) {
	cout << s.length() << "\n";
	int tmp = s.length() - i;
	cout << tmp << "\n";		
	if(tmp%2)  continue;
	cout << s.substr(0,tmp) << "\n";
	cout << s.substr(0,tmp/2) << "\n";
	cout << s.substr(tmp/2,tmp-1) << "\n";	
	if(s.substr(0,tmp/2) == s.substr(tmp/2,tmp-1)){
	  cout << i+1 << "\n";
	  return 0;
	}
  }

  return 0;
}
