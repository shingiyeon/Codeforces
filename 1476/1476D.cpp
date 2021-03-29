//# Author : godgiyeon =========================#
//# Problem Title : Journey ================#
//# Time Stamp : 2021-02-25T14:05:46 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <string>
using namespace std;

string str;
int dp[300002][2];
int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t; int n;
    while(t--) {
        cin >> n; cin >> str;
        for(int i=0; i<=300001; i++) {
            dp[i][0] = dp[i][1] = 0;
        }
        int idx = n;
        for(int i=n-1; i>=0; i--) {
            if(str[i] == 'L') continue;
            if(i == n-1) {
                dp[i][0] = 1;
                continue;
            }
            if(str[i+1] == 'L') {
                dp[i][0] = dp[i+2][0] + 2;
            }
            else {
                dp[i][0] = 1;
            }
        }
        for(int i=1; i<=n; i++) {
            if(str[i-1] == 'R') continue;
            if(i == 0) {
                dp[i][1] = 1;
                continue;
            }
            if(str[i-2] == 'R'){
                dp[i][1] = dp[i-2][1] + 2;
            }
            else {
                dp[i][1] = 1;
            }
        }
        for(int i=0; i<=n; i++) {
            cout << dp[i][0] + dp[i][1] + 1 << " ";
        }
        cout << "\n";

    }
}