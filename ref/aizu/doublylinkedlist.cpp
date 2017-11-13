/*
 * doublylinkedlist.cpp
 */

//include files
#include <bits/stdc++.h>

using namespace std;

//DEFINE MACROS

//DEFINE CONSTANT
struct node{
  int data;
  node *next,*prev;
};
node *root;

//DEFINE PROTOTYPE

node * searchnode(int x){
  node  * n = root->next;
  while(n != NULL){
	if(n->data == x) return n;
	n = n->next;
  }
  return NULL;
}

void insert(int x){
  node * n = (node *)malloc(sizeof(node));
  n->data = x;
  n->next = root->next;
  
  root->prev = n->next;
  n = root;
}

void deletex(int x){
  node * n = searchnode(x);
  if(n == NULL) return ;
  if(n->prev == NULL){
	root = n->next;
  }else if(n->next == NULL){
  }else{
	n->prev->next = n->next;
	n->next->prev = n->prev;
  }
}

void deleteFirst(){
  node * n;
  n = root;
  root = root->next;
  free(n);
}

void deleteLast(){
  node * n = root;
  while(n!=NULL){
	n = n->next;
  }
  free(n);
}

int main(){
  int n,b;
  string a;
  cin >> n;
  for (int i = 0; i < n; ++i) {
	cin >> a;
	cin >> b;
	if(a == "insert") insert(b);
	else if(a == "delete") deletex(b);
	else if(a == "deleteFirst") deleteFirst();	  
	else if(a == "deleteLast") deleteLast();
	else cout << "error" << "\n";
  }
  
  while(x != NULL) cout << x->data << "\n";		  

  return 0;
}

