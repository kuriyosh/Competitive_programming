#include "bits/stdc++.h"
using namespace std;

#define MAX 10105

bool dp[MAX];

int main() {
	int N;
	cin >> N;
	vector<int> W(N);
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> W[i];
		sum += W[i];
	}
	dp[0] = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = MAX - 1 - W[i]; j >= 0; j--)
		{
			dp[j + W[i]] |= dp[j];
		}
	}
	if (sum % 2 == 1 || !dp[sum / 2]) cout << "impossible" << endl;
	else cout << "possible" << endl;
}
