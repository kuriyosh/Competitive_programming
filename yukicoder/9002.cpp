/*
 * 9002.cpp
 */

//include files
#include<bits/stdc++.h>

using namespace std;

//DEFINE CONSTANT

//DEFINE PROTOTYPE

int main(){
  int a;
  cin >> a;
  for(int i = 1 ; i <= a ; i ++){
	if(i%3 ==0 && i%5 ==0 ) cout << "FizzBuzz" << endl;
	else if(i%3 ==0) cout << "Fizz" << endl;
	else if(i%5 ==0 ) cout << "Buzz" << endl;
	else cout << i << endl;
  }
  return 0;
}

