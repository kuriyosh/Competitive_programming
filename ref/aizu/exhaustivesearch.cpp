/*
 * exhaustivesearch.cpp
 */

//include files
#include <bits/stdc++.h>

using namespace std;

//DEFINE MACROS
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define PRINTLN(s) cout << s << endl

//DEFINE CONSTANT
int A[2000],S[2000];
int n,q;
int answer;
//DEFINE PROTOTYPE
bool rec(int now){
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    if(S[i] == 1) sum+=A[i];
  }
  if(sum == answer) return true;
  
  if(now == n) return false;
  S[now] = 0;
  if(rec(now+1)) return true;
  S[now] = 1;
  if(rec(now+1)) return true;

  return false;
}

void init(){
  for (int i = 0; i < n; ++i) S[i] = 0;
  if(rec(0)) cout << "yes" << endl;
  else cout << "no" << "\n";
}

int main(){
  int B[200];
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }

  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> B[i];
  }
  for (int i = 0; i < q; ++i) {
    answer = B[i];
	init();
  }


  
  return 0;
}

