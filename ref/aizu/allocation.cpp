/*
 * allocation.cpp
 */

//include files
#include <bits/stdc++.h>

using namespace std;

//DEFINE MACROS
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define PRINTLN(s) cout << s << endl

//DEFINE CONSTANT
int w[10000];
int n,k;

//DEFINE PROTOTYPE
int counttrack(int P){
  int count=0;
  int wsum=0;
  for (int  i = 0; i < n; ++i) {
    if(wsum + w[i] <= P){
	  wsum += w[i];
	}else{
	  count++;
	  wsum=0;
	  wsum+=w[i];
	}
  }
  return count+1;
}

int main(){
  int left=0,right=0;
  cin >> n;
  cin >> k;
  for (int i = 0; i < n; ++i){
	cin >> w[i];
	left = MAX(left,w[i]);
	right += w[i];
  }
  //binary search
  while(right-left > 1){
	int mid = (left+right)/2;
	int answer = counttrack((left+right)/2);
	if(answer == k){
	  while(counttrack(mid--) == k);
	  cout << mid + 2 << endl;
	  return 0;
	}else if(k >= answer) right = mid;
	else left = mid;
  }
  
  return 0;
}

