#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <queue>
#include <stack>
#include <string>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll comb(int n, int r) {
    if(n==r || r==0) return 1;
    return (comb(n-1, r-1) + comb(n-1, r)) % MOD;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v;
        int l = 0x7fffffff;
        for(int i=0; i<n; i++) {
            int tmp; cin >> tmp;
            v.push_back(tmp);
            l = l & tmp;
        }
        long long num = 0;
        for(auto val: v) {
            if(val == l) num++;
        }

        if(num <= 1) {
            cout << 0 << "\n";
        }
        else {
            long long tmp = (num ) * (num - 1) % MOD;
            for(int i=1; i<=n-2; i++) {
                tmp = (tmp * (ll)i) % MOD;
            }
            cout << tmp << "\n";
        }
    }
}
