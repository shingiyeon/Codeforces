//# Author : godgiyeon =========================#
//# Problem Title : Floor and Mod ==========#
//# Time Stamp : 2021-02-17T10:14:56 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        ll x, y; cin >> x >> y;
        ll ans = 0;
        for(int i=1; i<=sqrt(x); i++) {
            ans += max( min( x/i - 1, y) - i, 0LL);
        }
        cout << ans << "\n";
    }
}