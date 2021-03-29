//# Author : godgiyeon =========================#
//# Problem Title : Napoleon Cake ==========#
//# Time Stamp : 2021-03-13T22:44:21 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cout.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n+1);
        vector<int> ans(n+1, 0);
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int ggul = 0;
        for(int i=n-1; i>=0; i--) {
            if(arr[i] > ggul) {
                ggul = max(ggul, arr[i]);
            }
            if(ggul) {
                ans[i] = 1;
                ggul--;
            }
        }
        for(int i=0; i<n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}