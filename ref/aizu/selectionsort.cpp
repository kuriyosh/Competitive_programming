/*
 * selectionsort.cpp
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

void selectionsort(int A[],int N){
  for (int i = 0; i < N; ++i) {
	int minj = i;
	for (int j =i; j < N; ++j) {
	  if(A[j]<A[minj]) minj=j;
	}
	swap(A[i],A[minj]);
  }
}

int main(){
  int N,A[100];
  cin >> N;
  for (int i = 0; i <N ; ++i) cin >> A[i];
  selectionsort(A,N);
  trace(A,N);  
  return 0;
}

