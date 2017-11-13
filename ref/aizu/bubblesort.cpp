/*
 * bubblesort.cpp
 */

//include files
#include <iostream>

using namespace std;

//DEFINE MACROS

//DEFINE CONSTANT

//DEFINE PROTOTYPE
void trace(int A[],int N){
  for (int i = 0; i <N; ++i){
	cout << A[i] <<" ";
  }
  cout << endl;
}

void swap(int* a,int* b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void bubblesort(int A[],int N){
  int sw =0;
  bool flag = 1;
  for (int j = 0; flag ; ++j) {
	flag = 0;
	for (int i = N-1; i >= j + 1; --i) {
	  if(A[i]<A[i-1]){
		swap(A[i],A[i-1]);
		flag = 1;
		sw++;
	  }
	}
  }
}

int main(){;
  int N,A[100];
  cin >> N;
  for (int i = 0; i <N ; ++i) cin >> A[i];

  bubblesort(A,N);
  trace(A,N);
  return 0;
}

