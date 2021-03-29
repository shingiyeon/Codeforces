//# Author : godgiyeon =========================#
//# Problem Title : Minimum Ties ===========#
//# Time Stamp : 2021-03-05T09:44:56 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v;
        if( (n % 2) == 0 ) {
            for(int i=0; i< (n-1)/2; i++) v.push_back(1);
            v.push_back(0);
            for(int i=0; i< (n-1)/2; i++) v.push_back(-1);
        }
        else {
            for(int i=0; i<n/2; i++) v.push_back(1);
            for(int i=0; i<n/2; i++) v.push_back(-1);
        }
        
        for(int i=v.size()-1; i>=0; i--) {
            for(int j=0; j<=i; j++) cout << v[j] << " ";
        }
        cout << "\n";
    }
}