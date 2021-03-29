//# Author : godgiyeon =========================#
//# Problem Title : Cat Cycle ==============#
//# Time Stamp : 2021-03-04T23:10:22 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        long long n, k;
        cin >> n >> k;
        if(n % 2) {
            long long z = (n-1) / 2;
            cout <<  ( (k-1) + (k-1) / ((n-1)/2) ) % n + 1 << "\n";
        }
        else {
            cout << (k-1) % n + 1 << "\n";
        }
    }
}