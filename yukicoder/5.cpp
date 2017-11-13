/*
 * 5.cpp
 */

//include files
#include<bits/stdc++.h>

using namespace std;

//DEFINE CONSTANT

//DEFINE PROTOTYPE

int main(){
  int L,N;
  int W[10000];
  int min,min_i,sum=0;
  int count=0;
  cin >> L;
  cin >> N;
  for(int i = 0 ; i < N ; i++)	cin >> W[i];
  while(1){
	min = 100000;
	for(int i = 0 ; i < N ; i ++){
	  if(min > W[i]){
		min = W[i];
		min_i=i;
	  }
	}
	if(sum + min <= L){
	  sum += min;
	  W[min_i] = 100000;
	  count++;
	}else break;
  }
  cout << count << endl;
  
}

