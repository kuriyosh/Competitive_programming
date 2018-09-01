/*
 * FILE NAME:partition.cpp
 * DATE:2018-02-05
 * AUTHOR:Yoshiki Kurihara <y-kurihara@ist.osaka-u.ac.jp>
 値を交換すべきだったのに別の配列に分けてしまった。
 */

//include files
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>

//DEFINE MACROS
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define PRINTLN(s) cout << s << endl

using namespace std;


//DEFINE CONSTANT

//DEFINE PROTOTYPE

int main(){
  int N;
  int A[10000];
  cin >> N;

  for (auto i=0; i < N; i++) {
	cin >> A[i];
  }
  
  int mid = A[N-1];

  vector<int> B,C;
  for (auto i=0; i < N; i++) {
    if (A[i] < mid) {
	  B.push_back(A[i]);
	}else if (A[i] > mid) {
	  C.push_back(A[i]);
	}
  }

  for (auto a :B){
	cout << a <<' ';
  }
  cout << '[' <<mid <<"] ";
  for (auto a :C){
    cout << a <<' ';
  }
return 0;
}

