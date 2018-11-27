/**
 * @author torith
 * @date 2018-11-24
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int rtnmsb(ll v) {
    for (ll i = 63; i >= 0; --i) {
        if(((ll)(1) << i) & v) return i + 1;
    }
    return -1;
}


int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K; cin >> N >> K;
    int A[1000];
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum += A[i];
    }

    vector<ll> sub_sum;
    ll start_sum = sum;
    ll max_sub_sum = 0;
    for (int i = N-1; i >= 0; --i) {
        ll tmp = start_sum;
        for (int s = 0; i + s < N; ++s) {
            sub_sum.push_back(tmp);
            tmp -= A[s];
            tmp += A[s + i + 1];
            max_sub_sum = max(tmp, max_sub_sum);
        }
        start_sum -= A[i];
    }

    sort(sub_sum.begin(), sub_sum.end());
    sub_sum.erase(unique(sub_sum.begin(), sub_sum.end()), sub_sum.end());

    int max_msb = rtnmsb(max_sub_sum);

    // 最上位が確定でk個集まるラインを求める
    vector<ll> cand;
    for (int i = max_msb; i >= 0; --i) {
        int count = 0;
        for (int j = sub_sum.size() - 1; j >= 0; --j) {
            if(rtnmsb(sub_sum[j]) == i){
                count++;
                cand.push_back(sub_sum[j]);
            }
            if(((ll)(1) << (i - 1)) > sub_sum[j]) break;
        }
        if(count >= K){
            max_msb = i;
            break;
        }
    }

    // 先に求めた桁から減らして和を求める
    ll ans = ((ll)(1) << (max_msb - 1));
    for (int i = max_msb - 1; i > 0; --i) {
        vector<ll> tmp;
        int count = 0;

        for (int j = cand.size() - 1; j >= 0; --j) {
            if((cand[j] & ((ll)(1) << (i - 1))) > 0){
                tmp.push_back(cand[j]);
            }
        }

        if(tmp.size() >= K){
            cand = tmp;
            ans += pow(2, i-1);
        }
    }

    cout << ans << "\n";


    return 0;
}

