/*
 * stack.cpp
 */

//include files
#include <iostream>
#include <cstdio>

using namespace std;

//DEFINE MACROS

//DEFINE CONSTANT
int S[1000],top;

//DEFINE PROTOTYPE
int pop(){
  top--;
  return S[top+1];
}

void push(int a){  
  S[++top] = a;
}

int main(){
  char s[100];
  int a,b;
  while(cin >> s){
	if(s[0] == '+'){
	  a = pop();
	  b = pop();
	  push(a+b);
	}else if(s[0] == '-'){
	  a = pop();
	  b = pop();
	  push(b-a);
	}else if(s[0] == '*'){
	  a = pop();
	  b = pop();
	  push(a*b);
	}else{
	  push(s[0]-'0');
	}
  }
  cout << pop() << "\n";
  
  return 0;
}

