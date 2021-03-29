//# Author : godgiyeon =========================#
//# Problem Title : Pekora and Trampoline ==#
//# Time Stamp : 2021-03-01T22:41:41 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
using namespace std;
int arr[5001];
int dp[5001];
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> arr[i];
            dp[i] = 0; 
        }
        long long ans = 0;
        for(int i=1; i<=n; i++) {
            ans += (long long)max(1, arr[i] - dp[i]) - 1;
            if(dp[i] + 1 >= arr[i]) {
                dp[i+1] += dp[i] + 1 - arr[i];
            }
            for(int j=i+2; j<=min(n, i+arr[i]); j++) dp[j]++;
        }
        cout << ans << "\n";
    }
}