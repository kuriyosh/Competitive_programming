/*p
 * areasonthecross.cpp
 */

//include files
#include <bits/stdc++.h>
#include <stack>

using namespace std;

//DEFINE MACROS

//DEFINE CONSTANT

//DEFINE PROTOTYPE

int main(){
  stack<int> S;
  stack<pair<int, int> > S2;
  vector<int> result;
  char ch;
  int sum = 0;
  for(int i=0;cin >> ch;i++){
	if(ch == '\\'){
	  S.push(i);
	}else if(ch == '/'){
	  int opposite;
	  if(S.size() != 0){
		opposite = S.top();S.pop();
		sum += i-opposite;
		int a = i-opposite;
		while(S2.size()>0 && S2.top().first > opposite){
		  a += S2.top().second;S2.pop();
		}
		S2.push(make_pair(opposite,a));
	  }
	}
  }

  cout << sum  << "\n";
  cout << S2.size()<<"\n";
  
  return 0;
}

