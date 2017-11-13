/*
 * libstack.cpp
 */

//include files
#include <bits/stdc++.h>
#include <stack>

using namespace std;

//DEFINE MACROS

//DEFINE CONSTANT

//DEFINE PROTOTYPE

int main(){
  stack<int> S;
  S.push(3);
  S.push(7);
  S.push(1);

  cout << S.size() << " ";
  cout << S.top() << " ";
  S.pop();

  cout << S.top() <<" ";
  S.pop();
  
  
  return 0;
}

