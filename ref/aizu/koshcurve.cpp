/*
 * koshcurve.cpp
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

//DEFINE PROTOTYPE
void solve(float a,float b,float c,float d,int count){
  cout << a << " " <<  b << "\n";
  if(count == n) return;
  solve(a,b,(c-a)/3,(d-b)/3,count+1);
  solve((c-a)/3 , (d-b)/3 , (c-a)/3+(c-a)/6 , (d-b)/3+(d-b)*sqrt(3)/6 , count+1);
  solve((c-a)/3+(c-a)/6 , (d-b)/3+(d-b)*3*sqrt(3)/6 ,(c-a)*2/3 , (d-b)*2/3 , count+1);
  return;
}

int main(){
  cin >> n;
  float a = 0;
  float b = 0;
  float c = 100;
  float d = 0;
  solve(a,b,c,d,0);
  cout << c << " " << d << "\n";
  return 0;
}

