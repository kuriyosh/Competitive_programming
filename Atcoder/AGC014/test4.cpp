/*
 * test4.cpp
 */

//include files
#include <bits/stdc++.h>

using namespace std;

//DEFINE MACROS

//DEFINE CONSTANT
int N;
int link[1000][1000];
//DEFINE PROTOTYPE

int linkcount(int a[]){
  int count=0;
  for (int i = 0; i < N; ++i) {
	  if(a[i]==1) count++;
  }
  return count;

}

int main(){
  cin >>N;
  int a,b;
  int result[1000];
  bool turn = false;
  for (int i = 0; i < N-1; ++i) {
	cin >> a;
	cin >> b;
	link[a][b] = 1;
	link[b][a] = 1;
  }
  
  for (int i = 0; i < N; ++i) {
    result[i]=0;
  }
  
  for (int i = 0; i < N; ++i) {
	int maxcount=0;
	int maxid;
	for (int j = 0; j < N; ++j) {
	  if(maxcount < linkcount(link[j]) && result[j] ==0){
		maxcount = max(maxcount,linkcount(link[j]));
		maxid = j;
	  }
	  if(turn) result[maxid] =1;
	  else  result[maxid] =2;
	}
	if(turn) turn = false;
	else  turn = true;
  }

  int fin[1000];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
	  if(link[i][j] == 1) fin[j] = result[i];
	}
  }
  int A = 0;
  for (int i = 0; i < N; ++i) {
	if(fin[i] == 1) A++;
  }
  if(A > N/2) cout << "First"<< endl;
  else cout << "Second" << "\n";

  return 0;
}

