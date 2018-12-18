/**
 * @author torith
 * @date 2018-12-18
 * p.39 next_permutationを試してみる
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int array[] = {1, 2, 3, 4, 5};

    do
    {
        for (int i = 0; i < 5; i++) {
            cout << array[i] << " ";
        }
        cout  << "\n";
    } while (next_permutation(array, array + 5));

    return 0;
}

