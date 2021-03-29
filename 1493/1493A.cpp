//# Author : godgiyeon =========================#
//# Problem Title : Anti-knapsack ==========#
//# Time Stamp : 2021-03-06T23:21:37 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> v;
        for(int i=(k+1)/2; i<=k-1; i++) {
            v.push_back(i);
        }
        for(int i=k+1; i<=n; i++) {
            v.push_back(i);
        }
        cout << v.size() << "\n";
        for(auto val: v) {
            cout << val << " ";
        }
        cout << "\n";
    }
}