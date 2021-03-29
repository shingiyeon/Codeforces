//# Author : godgiyeon =========================#
//# Problem Title : Minimal Cost ===========#
//# Time Stamp : 2021-03-01T01:04:50 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        long long u, v; cin >> n >> u >> v;
        cin >> k;
        long long ans = min(u+v, v+v);
        for(int i=1; i<n; i++) {
            int tmp;
            cin >> tmp;
            if(tmp < k-1 || tmp > k+1) {
                ans = 0;
            }
            if(tmp == k-1 || tmp == k+1) {
                ans = min(ans, min(u, v));
            }
            k = tmp;
        }
        cout << ans << "\n";
    }
}