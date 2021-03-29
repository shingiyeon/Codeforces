//# Author : godgiyeon =========================#
//# Problem Title : Shifting Stacks ========#
//# Time Stamp : 2021-03-04T16:03:46 ===========#
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
        ll sum = 0;
        for(int i=0; i<n; i++) {
            sum += v[i];
            if( ((ll)(i+1)*i)/2 > sum ) {
                flag = false;
                break;
            }
        }
        if(flag) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}