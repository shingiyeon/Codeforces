//# Author : godgiyeon =========================#
//# Problem Title : Max and Mex ============#
//# Time Stamp : 2021-03-12T22:29:03 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int upper(int a, int b) {
    if(a % b) {
        return (a/b) + 1;
    }
    return (a/b);
}
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; ll k; cin >> n >> k;
        vector<int> v;
        for(int i=1; i<=n; i++) {
            int tmp; cin >> tmp; v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        int mex_val = 0;
        for(auto val: v) {
            if(val == mex_val) {
                mex_val++;
            }
        }
        if(mex_val > v.back() || k == 0) {
            cout << k + n << "\n";
        }
        else {
            if(binary_search(v.begin(), v.end(), upper(mex_val + v.back(), 2))) {
                cout << n << "\n";
            }
            else {
                cout << n + 1 << "\n";
            }
        }
    }
}