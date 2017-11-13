/*
 * stablesort.cpp
 */

//include files
#include <iostream>

using namespace std;
struct Card{char suit,value;};

//DEFINE MACROS

//DEFINE CONSTANT


//DEFINE PROTOTYPE
void trace(Card C[],int N){
  for (int i = 0;  i < N; ++ i) {
    cout<<C[i].suit << C[i].value <<" ";
  }
  cout << "\n";
}

void BubbleSort(Card C[],int N){
  for (int i = 0; i < N; ++i) {
    for (int j = N-1; j >= i+1; --j) {
	  if (C[j].value < C[j-1].value)	swap(C[j],C[j-1]);
	}
  }
  trace(C,N);
}

bool isStable(Card C1[],Card C2[],int N){
  for (int i = 0; i < N; ++i) {	
    if(C1[i].suit != C2[i].suit ) return false;
  }
  return true;
}

void SelectionSort(Card C[],int N){
  for (int i = 0; i < N; ++i) {
    int minj = i;
	for (int j = i; j < N; ++j) {
	  if(C[j].value < C[minj].value){
		minj = j;
	  }
	}
	swap(C[i],C[minj]);
  }
  trace(C,N);
}

void swap(Card* a,Card* b){
  Card temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main(){
  Card C1[36],C2[36];
  int N;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> C1[i].suit >> C1[i].value;
  }

  for (int i = 0; i < N; ++i) {
    C2[i] = C1[i];
  }

  BubbleSort(C1,N);
  cout << "Stable" << "\n";
  SelectionSort(C2,N);
  cout << "Not stable" << "\n";
  
  return 0;
}

