//# Author : godgiyeon =========================#
//# Problem Title : Dense Array ============#
//# Time Stamp : 2021-03-02T14:59:32 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <math.h>

using namespace std;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a, b;
        long long ans = 0;
        cin >> a;
        for(int i=1; i<n; i++) {
            cin >> b;
            int x = min(a, b); int y = max(a, b);
            if(2*x<y) {
                int tmp = log2(y/x) / log2(2);
                if(x * pow(2, tmp) == y) tmp--;
                ans += (long long)tmp;
            }
            a = b;
        }
        cout << ans << "\n";
    }
}