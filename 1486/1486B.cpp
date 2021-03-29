//# Author : godgiyeon =========================#
//# Problem Title : Eastern Exhibition =====#
//# Time Stamp : 2021-03-09T22:20:43 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        vector<long long> x, y;
        int n; cin >> n;
        for(int i=1; i<=n; i++) {
            long long a, b; cin >> a >> b;
            x.push_back(a); y.push_back(b);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        long long ans = 1;
        if( (n % 2) == 0) {
            ans = (x[n/2] - x[(n-1)/2] + 1) * (y[n/2] - y[(n-1)/2] + 1);
        }
        cout << ans << "\n";
    }
}