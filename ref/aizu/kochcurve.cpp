/*
 * koshcurve.cpp
 */

//include files
#include <bits/stdc++.h>

using namespace std;

struct Point{double x,y;};

//DEFINE MACROS
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define PRINTLN(s) cout << s << endl

//DEFINE CONSTANT
int N;

//DEFINE PROTOTYPE
void koch(int n,Point a, Point b){
  if(n == N) return;
  
  return;
}

int main(){
  cin >> N;
  Point a,b;
  a.x = 0;
  b.x = 100;
  a.y = 0;
  b.y = 0;
  koch(N,a,b);

  return 0;
}

