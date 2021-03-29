//# Author : godgiyeon =========================#
//# Problem Title : Copy or Prefix Sum =====#
//# Time Stamp : 2021-02-17T09:33:30 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <map>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;

ll f[200005];
ll g[200005];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        map<ll, ll> m;
        int n; cin >> n;
        ll b;
        ll prefix = 0;
        g[0] = 1;
        f[0] = 1;
        m[0] = 1;
        for(int i=1; i<=n; i++) {
            f[i] = (2 * f[i-1] - g[i-1] + MOD) % MOD;
            cin >> b; 
            prefix += b;
            if ( m.find(prefix) != m.end() ) g[i] = m[prefix];
            else g[i] = 0;
            m[prefix] = f[i];
        }
        cout << f[n] << "\n";
        
    }

}