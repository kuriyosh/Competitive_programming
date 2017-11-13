/*
 * 7.cpp
 */

//include files
#include<bits/stdc++.h>

using namespace std;

//DEFINE MACROS
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define INT_IN(a) int a; cin >> a
#define STR_IN(s) string s; cin >> s
#define PRINTLN(s) cout << s << endl
#define PRINTDOUBLELN(s) cout << setprecision(12) << (s) << endl;

//DEFINE CONSTANT
int prime[1000],prime_max=0;
bool key_prime[1000];
bool win_frag;
//DEFINE PROTOTYPE
int answer(int N,bool player);

int main(){
  bool frag;
  FOR(i,2,1000){
	frag = 0;
	FOR(j,2,i){
	  if(i%j == 0) frag = 1;
	}
	if(frag == 0){
	  prime[prime_max] = i;
	  prime_max++;
	}				  
  }
  INT_IN(N);
  if(answer(N,true) == 1) PRINTLN("Win");
  else PRINTLN("Lose");
  
}

int answer(int N,bool player){
  int i=0;
  int dif;
  while((dif = N-prime[i])>0){
	PRINTLN(dif);
	if((dif == 3||dif ==2) && (player == true)) return 1;
	if((dif == 3||dif ==2) && (player == false)) return 0;
	if(answer(dif,!player) == 1) return 1;
	i++;
  }
  return 0;

}
