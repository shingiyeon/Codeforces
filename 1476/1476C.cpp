//# Author : godgiyeon =========================#
//# Problem Title : Longest Simple Cycle ===#
//# Time Stamp : 2021-02-25T13:32:38 ===========#
//# Language : GNU C++17 =======================#

#include <iostream>
#include <math.h>
typedef long long ll;
using namespace std;

ll a[100001], b[100001], c[100001];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i=1; i<=n; i++) cin >> c[i];
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=n; i++) cin >> b[i];
        ll ans = 0; ll sum = 0;
        for(int i=2; i<=n; i++) {
            if(a[i] > b[i]) swap(a[i], b[i]);
            if(b[i] == a[i]) {
                ans = max(ans , sum);
                sum = b[i] - a[i] + c[i] + 1;
            }
            else {
                if(b[i]-a[i]+c[i]+1 >= sum -(b[i]-a[i])+c[i]+1) {
                    ans = max(ans , sum);
                    sum = b[i] - a[i] + c[i] + 1;
                }
                else {
                    ans = max(ans, sum);
                    sum = sum - (b[i] - a[i]) + c[i] + 1;
                }
            }
        }
        ans = max(ans, sum);
        cout << ans << "\n";
    }
}