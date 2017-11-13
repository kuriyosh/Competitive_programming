#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cctype>
#define rep(i,a,b) for(int i=(a);i<b;i++)
#define INF 1000000000
using namespace std;
bool debug=true;
int n;

int change(int n){
  int cnt=0;
  while(n){
    if(n%2==1)cnt++;
    n/=2;
  }
  return cnt;
}

void bfs(){
  vector<int> vect(n+1,INF);
  queue<int>que;
  que.push(1);
  vect[1]=1;
  while(que.size()){
    int now=que.front();que.pop();
    int bit=change(now);
    if(now-bit>0&&vect[now-bit]==INF){
      vect[now-bit]=vect[now]+1;
      que.push(now-bit);
    }
    if(now+bit<=n&&vect[now+bit]==INF){
      vect[now+bit]=vect[now]+1;
      que.push(now+bit);
    }
  }
  cout<<( vect[n]!=INF ? vect[n] : -1 ) <<endl;
}

int main(){
  cin>>n;
  bfs();
  return 0;
}
