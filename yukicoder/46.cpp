/*
 * 46.cpp
 */

//include files
#include<bits/stdc++.h>

using namespace std;

//DEFINE CONSTANT

//DEFINE PROTOTYPE

int main(){
  int a,b;
  cin >> a >> b;
  if(b%a == 0) cout << b/a << endl;
  else cout << (int)b/a+1 << endl;
  return 0;
}

