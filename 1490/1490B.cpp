//# Author : godgiyeon =========================#
//# Problem Title : Balanced Remainders ====#
//# Time Stamp : 2021-03-02T15:13:23 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>

using namespace std;

int c[3];

int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        for(int i=0; i<3; i++) c[i] = 0;
        int n; cin >> n;
        for(int i=1; i<=n; i++) {
            int tmp; cin >> tmp; c[tmp%3]++;
        }
        int ans = 0;
        while(true){
            int flag = true;
            for(int i=0; i<3; i++) {
                if(c[i]<(n/3)) {
                    flag = false;
                    ans += (n/3 - c[i]);
                    if(i-1 == -1) c[2] -= (n/3 - c[i]);
                    else c[(i-1)%3] -= (n/3 - c[i]);
                    c[i] = n/3;
                }
            }
            if(flag) break;
        }
        cout << ans << "\n";
    }
}