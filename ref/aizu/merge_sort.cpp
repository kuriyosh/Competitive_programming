/*
 * FILE NAME:merge_sort.cpp
 * DATE:2017-11-14
 * AUTHOR:Yoshiki Kurihara <y-kurihara@ist.osaka-u.ac.jp>
 */

//include files
#include <bits/stdc++.h>

using namespace std;

//DEFINE MACROS
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define PRINTLN(s) cout << s << endl

//DEFINE CONSTANT
#define MAX_LENGTH 500000
#define INFTY 2147483647

int L[MAX_LENGTH/2],R[MAX_LENGTH/2];
int compare = 0;

//DEFINE PROTOTYPE
void merge(int A[],int left,int mid,int right){
  int n1 = mid - left;
  int n2 = right - mid;
  for (int i = 0; i <= n1-1; ++i)  L[i] = A[left+i];
  for (int i = 0; i <= n2-1; ++i)  R[i] = A[mid+i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  int i = 0,j = 0;
  for (int k = left; k <= right-1; k++) {
	compare ++;
    if(L[i] <= R[j]){
	  A[k] = L[i];
	  i++;
	}else{
	  A[k] = R[j];
	  j = j+1;
	}
  }
}

void mergeSort(int A[],int left,int right){
  if(left+1 < right){
	int mid = (left+right)/2;
	mergeSort(A,left,mid);
	mergeSort(A,mid,right);
	merge(A,left,mid,right);
  }
}

int main(){
  int n;
  int A[MAX_LENGTH];
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> A[i];
  mergeSort(A,0,n);
  for (int i = 0; i < n; ++i) cout << A[i] << " ";
  cout << "\n";
  cout << compare << "\n";
  
  return 0;
}

