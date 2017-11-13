/*
 * 188.cpp
 */

//include files
#include<bits/stdc++.h>

using namespace std;

//DEFINE CONSTANT

//DEFINE PROTOTYPE

int main(){
  int count=0;
  for(int month=1 ; month <=12 ;month++){
	for(int days=1 ; days <= 31 ; days++){
	  if(month == 2 && days == 29) break;
	  if(((month == 4)||(month == 6)||(month == 9)||(month == 11))&&(days ==31)) break;
	  if(month == (days/10 + days%10)) count++;
	}
  }
  cout << count <<endl;
}

