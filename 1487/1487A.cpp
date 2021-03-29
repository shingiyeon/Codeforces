//# Author : godgiyeon =========================#
//# Problem Title : Arena ==================#
//# Time Stamp : 2021-03-04T15:44:33 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v;
        int tmp;
        for(int i=1; i<=n; i++) {
            cin >> tmp; v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        int num = 0;
        for(int i=0; i<n; i++) {
            if(v[i] == v[0]) num++;
        }
        cout << n - num << "\n";
    }
}