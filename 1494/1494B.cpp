//# Author : godgiyeon =========================#
//# Problem Title : Berland Crossword ======#
//# Time Stamp : 2021-03-05T14:51:52 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
using namespace std;
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int arr[4]; int n;
        cin >> n; cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
        bool flag = true;
        for(int i=0; i<4; i++) {
            int j = ((i-1) == -1)? 3 : (i-1);
            int k = ((i+1) == 4)? 0 : (i+1);
            int o = (i+2)%4;
            if(arr[j] == n-1 || arr[k] == n-1) {
                if(arr[i] + arr[o] < 1) flag = false;
            }
            if(arr[j] == n-1 && arr[k] == n-1) {
                if(arr[i] + arr[o] < 2) flag = false;
            }
            if(arr[j] == n || arr[k] == n) {
                if(arr[i] < 1 || arr[o] < 1) flag = false;
            }
            if( (arr[j] == n-1 && arr[k] == n) || (arr[j] == n-1 && arr[k] == n)) {
                if(arr[i] + arr[o] < 3) flag = false;
                if(arr[i] < 1 || arr[o] < 1) flag = false;
            }
            if(arr[j] == n & arr[k] == n) {
                if(arr[i] < 2 || arr[o] < 2) flag = false;
            }
        }
        if(flag) cout << "YES" << "\n";
        else cout << "NO" << "\n";
        
    }
}