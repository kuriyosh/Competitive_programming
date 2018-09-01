/*
 * test1.cpp
 */

//include files
#include <bits/stdc++.h>

using namespace std;

//DEFINE MACROS

//DEFINE CONSTANT
long long int A,B,C;
int arA[10000];
int acount=0;



//DEFINE PROTOTYPE
bool checkpri(){
  if((A%2==1)||(B%2==1)||(C%2==1)) return true;
  for (int i = 0; i < acount; ++i){
	if(arA[i] == A){
	  acount = -1;
	  return true;
	}
  }
  arA[acount] = A;
  return false;
}

int main(){
  cin >> A;
  cin >> B;
  cin >> C;
  int preA,preB,preC;
  while(1){
	if(checkpri()) break;
	preA = A;
	preB = B;
	preC = C;
	A = preB/2 + preC/2;
	B = preC/2 + preA/2;
	C = preA/2 + preB/2;
	acount++;
  }
  cout << acount << "\n";
  return 0;
}

