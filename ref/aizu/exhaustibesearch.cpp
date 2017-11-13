/*
 * exhaustibesearch.cpp
 */

//include files
#include <bits/stdc++.h>

using namespace std;

//DEFINE MACROS
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define PRINTLN(s) cout << s << endl

//DEFINE CONSTANT
int n;
int A[2000];
int q;
int m[2000];
int result;


//DEFINE PROTOTYPE
bool solve(int sum,int i){
  if (sum == result) return true;
  if(i == n) return false;
  if(solve(sum+A[i],i+1)) return true;
  if(solve(sum,i+1)) return true;
  return false;
}

int main(){
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> A[i];
  cin >> q;
  for (int i = 0; i <q; ++i) cin >> m[i];

  for (int i = 0; i < q; ++i) {
	result = m[i];
    if(solve(0,0)) cout << "yes" << "\n";
	else cout << "no" << "\n";
  }



  
  return 0;
}

