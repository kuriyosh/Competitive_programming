/*
 * 001.cpp
 */

//include files
#include<bits/stdc++.h>

using namespace std;

//DEFINE MACROS
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define PRINTLN(s) cout << s << endl

//DEFINE CONSTANT

//DEFINE PROTOTYPE

int main(){
  int a,b,c;
  cin >> a;
  cin >> b;
  cin >> c;

  int min = a+b;
  if (min > b+c) {
    min = b+c;
  }
  if (min > c+a) {
    min = c+a;
  }

  cout << min << "\n";
  return 0;
}

