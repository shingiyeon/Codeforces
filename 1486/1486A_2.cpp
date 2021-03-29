//# Author : godgiyeon =========================#
//# Problem Title : Shifting Stacks ========#
//# Time Stamp : 2021-03-04T15:53:47 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int tmp; vector<ll> v;
        bool flag = true;
        for(int i=0; i<n; i++) {
            cin >> tmp; v.push_back((ll)tmp);
        }
        for(int i=0; i<n; i++) {
            if(v[i] < (ll)i) {
                flag = false;
                break;
            }
            else {
                if(i == n-1) break;
                v[i+1] += v[i] - i;
                v[i] = i;
            }
        }
        if(flag) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}