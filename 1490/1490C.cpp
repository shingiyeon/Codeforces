//# Author : godgiyeon =========================#
//# Problem Title : Sum of Cubes ===========#
//# Time Stamp : 2021-03-02T15:18:35 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    vector<ll> v;
    for(int i=1; i<=10000; i++) {
        v.push_back((ll)i*i*i);
    }
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        bool flag = false;
        for(int i=1; i<=10000; i++) {
            ll tmp = n - (ll)i*i*i;
            if(tmp < 0) break;
            if(binary_search(v.begin() + i - 1, v.end(), tmp)) {
                cout << "YES" << "\n"; flag = true; break;
            }
        }
        if(!flag) {
            cout << "NO" << "\n";
        }
    }
}