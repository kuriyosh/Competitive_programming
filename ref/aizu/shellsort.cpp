/*
 * shellsort.cpp
 */

//include files
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

//DEFINE MACROS

//DEFINE CONSTANT
int cnt;
vector<int> G;
int n;
int A[100];

//DEFINE PROTOTYPE
void insertionsort(int A[],int n,int g){
  int v,j;
  for (int i = g;  i < n;  i++) {
	v = A[i];
	j = i - g;
  }
  while(j>=0 && A[j] >v){
	A[j+g] = A[j];
	j = j - g;
	cnt++;
  }
  A[j+g] = v;
}

void shellsort(int A[],int n){
  for(int h=1;;){
	if(h>n) break;
	G.push_back(h);
	h = h*3 + 1;
  }
  for (int i = G.size()-1; i >= 0; --i) insertionsort(A,n,G[i]);
}

int main(){
  cin >> n;
  for (int i = 0; i < n; ++i) scanf("%d",&A[i]);
  cnt = 0;

  shellsort(A,n);

  cout << G.size() << endl;

  for (int i = G.size()-1; i >= 0; --i) {
	printf("%d",G[i]);
	if(i) printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);
  for (int i = 0; i < n; i++) printf("%d\n", A[i]);

  return 0;  
}
