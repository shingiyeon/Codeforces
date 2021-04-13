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
const ll mod = 1e9 + 7;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    ll dy[202020];

    for(int i=0; i<9; i++) dy[i] = 2;
    dy[9] = 3;
    for(int i=10; i<202020; i++) dy[i] = (dy[i-10] + dy[i-9] ) % mod;
    
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        ll ans = 0;
        while(n) {
            int k = n%10;
            if(k + m >= 10) {
                ans = ( ans + dy[k + m - 10] ) % mod;
            }
            else {
                ans = ( ans + 1) % mod;
            }
            n = n/10;
        }
        cout << ans << "\n";
    }
}
