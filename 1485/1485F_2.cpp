//# Author : godgiyeon =========================#
//# Problem Title : Copy or Prefix Sum =====#
//# Time Stamp : 2021-02-17T09:09:07 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <map>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;


int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        map<ll, ll> m;
        int n; cin >> n;
        ll b;
        ll num = 1;
        ll dy = 1;
        ll prefix = 0;
        m[0] = 1;
        
        for(int i=1; i<=n; i++) {
            cin >> b;
            num = m[-prefix];
            m[-prefix] = dy;
            dy = (2 * dy - num + MOD) % MOD;
            prefix += b;
        }
        cout << dy << "\n";
        
    }

}