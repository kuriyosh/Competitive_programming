/*
 * queue.cpp
 */

//include files
#include <bits/stdc++.h>


using namespace std;

//DEFINE MACROS

//DEFINE CONSTANT

//DEFINE PROTOTYPE

int main(){
  int q,n;
  int maxtime=0;
  pair <string,int> p[10000];
  cin >>n;
  cin >>q;
  for (int i = 0;  i < n; i++){
	cin >> p[i].first;
	cin >> p[i].second;
	maxtime+=p[i].second;
  }
  
  int time=0;
  while(1){
	for (int i = 0; i < n; ++i) {
	  if(p[i].second  ==0) continue;
	  if(p[i].second - q < 0){
		time += p[i].second;
		p[i].second = 0;
		cout << p[i].first << " " << time <<endl;
	  }else{
		time += q;
		p[i].second -= q;
		if(p[i].second == 0) cout << p[i].first << " " << time <<endl;
	  }
	}
	if(time >= maxtime) return 0;
  }
}
